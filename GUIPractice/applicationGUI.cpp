// Include neccessary libraries
#include "applicationGUI.h"
#include "histogramSettingsDialog.h"
#include "logFileDisplay.h"
#include "outImageDisplay.h"
#include "backendCode.h"
#include <QFile>
#include <QTextStream> 
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <vector>

// Vector of structure type 'imageContents'
std::vector<imageContents> imageStore;

// Global variables
int currentImage = 1, sortType = 0;
QString imageName;
QString dir_name;
std::string currentDirectoryPath;
QString logLocation = QDir::homePath();
std::string logLocationConv = logLocation.toLocal8Bit().constData();
std::string logFileName = "/LogFile.txt";
double dataScale = 1;
int perXScale = 1, cThreshold = 26, pixelPercentage = 0;
bool showThreshold = false, smoothedLine = false, perIntensity = true, lineGraph = false;
bool singleFile = false;
bool viewThresh = false;

// Function for launching the application GUI
applicationGUI::applicationGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->resize(1280, 736);
	
	ui.previousImage->setEnabled(false);
	ui.nextImage->setEnabled(false);
	ui.actionCustomHistogram->setEnabled(false);
	ui.menuExport->setEnabled(false);
	ui.sortOptions->setEnabled(false);
	ui.actionSpot_Mode->setEnabled(false);
	ui.menuBar->setStyleSheet("background-color: lightGray;");
	ui.nextImage->setStyleSheet("background-color: lightGray;");
	ui.previousImage->setStyleSheet("background-color: lightGray;");
	ui.sortOptions->setStyleSheet("background-color: white;");
	ui.centralWidget->setStyleSheet("background-color: aqua;");

	connect(ui.actionDirectory, SIGNAL(triggered()), SLOT(selectDirectory()));
	connect(ui.actionLog_Location, SIGNAL(triggered()), SLOT(selectLogLocation()));
	connect(ui.actionImage, SIGNAL(triggered()), SLOT(selectFile()));
	connect(ui.nextImage, SIGNAL(clicked()), SLOT(nextImage()));
	connect(ui.previousImage, SIGNAL(clicked()), SLOT(prevImage()));
	connect(ui.actionHistogram, SIGNAL(triggered()), SLOT(saveHist()));
	connect(ui.actionResults, SIGNAL(triggered()), SLOT(saveResults()));
	connect(ui.actionAll, SIGNAL(triggered()), SLOT(saveAll()));
	connect(ui.actionCustomHistogram, SIGNAL(triggered()), SLOT(editHistogram()));
	connect(ui.sortOptions, SIGNAL(currentIndexChanged(int)), SLOT(updateSortType()));
	connect(ui.actionLog_History, SIGNAL(triggered()), SLOT(viewLogFile()));
	connect(ui.actionPop_Contents, SIGNAL(triggered()), SLOT(popUpDisplay()));
	connect(ui.actionSpot_Mode, SIGNAL(triggered()), SLOT(toggleSpotMode()));

	std::ofstream file;
	file.open(logLocationConv + logFileName, std::ios_base::app);
	file << "Log file instance initiated at | " << logLocationConv << " |" << std::endl;
	file.close();
}

// Function for setting the output location of the log file
void applicationGUI::selectLogLocation() {
	logLocation = QFileDialog::getExistingDirectory(this, "Select Directory", logLocation);
	logLocationConv = logLocation.toLocal8Bit().constData();
	if (logLocation != QDir::homePath() && logLocation != NULL) {
		std::ofstream file;
		file.open(logLocationConv + logFileName, std::ios_base::app);
		file << "Log file instance initiated at | " << logLocationConv << " |" << std::endl;
		file.close();
	}
	else {
		if (logLocation == QDir::homePath()) {
			ui.statusBar->showMessage("Please select a directory");
			selectLogLocation();
		}
	}
}

// Function for sorting vector
void applicationGUI::updateSortType() {
	sortType = ui.sortOptions->currentIndex();
	ui.sortOptions->setEnabled(false);
	ui.sortOptions->setEnabled(true);
	updateGUI();
}

// Function to toggle 'spot mode'
void applicationGUI::toggleSpotMode() {
	if (viewThresh == true) {
		viewThresh = false;
	}
	else {
		viewThresh = true;
	}
	updateGUI();
}

// Function to sort vector by file name
bool compareByName(const imageContents &a, const imageContents &b)
{
	return a.fileName < b.fileName;
}

// Function to sort vector by spot score
bool compareBySpot(const imageContents &a, const imageContents &b)
{
	return a.spotScore < b.spotScore;
}

// Function to film vector by aesthetic score
bool compareByFilm(const imageContents &a, const imageContents &b)
{
	return a.filmScore < b.filmScore;
}

// Function to sort vector by aesthetic score
bool compareByAesthetic(const imageContents &a, const imageContents &b)
{
	return a.aestheticScore < b.aestheticScore;
}

// Function to update the GUI
void applicationGUI::updateGUI() {
	switch (sortType) {
	case 1:
		sort(imageStore.begin(), imageStore.end(), compareBySpot);
		break;
	case 2:
		sort(imageStore.begin(), imageStore.end(), compareByFilm);
		break;
	case 3:
		sort(imageStore.begin(), imageStore.end(), compareByAesthetic);
		break;
	default:
		sort(imageStore.begin(), imageStore.end(), compareByName);
	}
	ui.menuExport->setEnabled(true);
	ui.actionCustomHistogram->setEnabled(true);
	ui.actionHistogram->setEnabled(true);
	ui.actionResults->setEnabled(true);
	imageName = QString::fromStdString(imageStore[currentImage].fileName);
	ui.statusBar->showMessage("Displaying image | " + imageName);

	QPixmap input;

	if (viewThresh == false) {
		input = QPixmap::fromImage(QImage(
			imageStore[currentImage].inputImage.data,
			imageStore[currentImage].inputImage.cols,
			imageStore[currentImage].inputImage.rows,
			imageStore[currentImage].inputImage.step,
			QImage::Format_RGB888
		));
	}
	else {
		input = QPixmap::fromImage(QImage(
			imageStore[currentImage].threshImage.data,
			imageStore[currentImage].threshImage.cols,
			imageStore[currentImage].threshImage.rows,
			imageStore[currentImage].threshImage.step,
			QImage::Format_RGB888
		));
	}

	QPixmap output = QPixmap::fromImage(QImage(
		imageStore[currentImage].imageHistogram.data,
		imageStore[currentImage].imageHistogram.cols,
		imageStore[currentImage].imageHistogram.rows,
		imageStore[currentImage].imageHistogram.step,
		QImage::Format_RGB888
	));
	ui.inputDisplay->setPixmap(input);
	ui.histDisplay->setPixmap(output);
	QString customStream;
	QTextStream fullPrint(&customStream);
	fullPrint << QString::fromStdString(imageStore[currentImage].fileName) << " | Threshold = " << cThreshold << endl << endl;
	fullPrint << fixed;
	fullPrint << qSetRealNumberPrecision(1);
	fullPrint << "pixels " << "all" << " = " << imageStore[currentImage].pixelCount << endl;
	fullPrint << "mean " << "all" << " = " << imageStore[currentImage].meanAll << endl;
	fullPrint << "stdDev " << "all" << " = " << imageStore[currentImage].stdDevAll << endl;
	fullPrint << "variance " << "all" << " = " << imageStore[currentImage].varAll << endl << endl;

	fullPrint << "pixels " << "above/equal" << " = " << imageStore[currentImage].pixelAbove << endl;
	fullPrint << "mean " << "above/equal" << " = " << imageStore[currentImage].meanAbove << endl;
	fullPrint << "stdDev " << "above/equal" << " = " << imageStore[currentImage].stdDevAbove << endl;
	fullPrint << "variance " << "above/equal" << " = " << imageStore[currentImage].varAbove << endl << endl;

	fullPrint << "spot" << " = " << imageStore[currentImage].spotScore << " | ";
	fullPrint << "film" << " = " << imageStore[currentImage].filmScore << " | ";
	fullPrint << "aesthetic" << " = " << imageStore[currentImage].aestheticScore;
	ui.textBrowser->setText(fullPrint.readAll());
}

// Function to select a directory of images for processing
void applicationGUI::selectDirectory() {
	dir_name = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::homePath());
	std::string conversionDirectory = dir_name.toLocal8Bit().constData();
	currentDirectoryPath = conversionDirectory + "/";
	if (dir_name != QDir::homePath() && dir_name != NULL) {
		ui.statusBar->showMessage("Processing all images");
		imageStore = process_all(currentDirectoryPath, dataScale, perXScale, cThreshold, pixelPercentage, showThreshold, smoothedLine, perIntensity, lineGraph);
		singleFile = false;
		ui.statusBar->showMessage("All images processed");
		QMessageBox::information(this, "Notification", "All Images Processed");
		ui.actionAll->setEnabled(true);
		currentImage = 1;
		updateGUI();
		ui.actionSpot_Mode->setEnabled(true);
		if (imageStore.size() > 2) {
			ui.previousImage->setEnabled(true);
			ui.nextImage->setEnabled(true);
			ui.sortOptions->setEnabled(true);
		}
		else {
			ui.previousImage->setEnabled(false);
			ui.nextImage->setEnabled(false);
			ui.sortOptions->setEnabled(false);
		}
	}
	else {
		if (dir_name == QDir::homePath()) {
			ui.statusBar->showMessage("Please select a directory");
			selectDirectory();
		}
	}
}

// Function to select an image file for processing
void applicationGUI::selectFile() {
	QString file_name = QFileDialog::getOpenFileName(this, "Select File", QDir::homePath());
	std::string conversionDirectory = file_name.toLocal8Bit().constData();
	currentDirectoryPath = conversionDirectory;
	if (file_name != NULL) {
		ui.statusBar->showMessage("Processing image");
		imageStore = process_image(currentDirectoryPath, dataScale, perXScale, cThreshold, pixelPercentage, showThreshold, smoothedLine, perIntensity, lineGraph);
		singleFile = true;
		ui.statusBar->showMessage("Image processed");
		QMessageBox::information(this, "Notification", "Image Processed");
		ui.actionAll->setEnabled(false);
		currentImage = 0;
		updateGUI();
		ui.actionSpot_Mode->setEnabled(true);
		ui.previousImage->setEnabled(false);
		ui.nextImage->setEnabled(false);
		ui.sortOptions->setEnabled(false);
	}
}

// Function to view next image
void applicationGUI::nextImage() {
	if (currentImage < (imageStore.size() - 1)) {
		currentImage++;
	}
	else {
		currentImage = 1;
	}
	updateGUI();
}

// Function to view previous image
void applicationGUI::prevImage() {
	if (currentImage > 1) {
		currentImage--;
	}
	else {
		currentImage = (imageStore.size() - 1);
	}
	updateGUI();
}

// Function to save histogram image file
void applicationGUI::saveHist() {
	dir_name = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::homePath());
	if (dir_name != QDir::homePath() && dir_name != NULL) {
		dir_name = dir_name + "/";
		std::string conversionDirectory = dir_name.toLocal8Bit().constData();
		save_histogram(conversionDirectory, imageStore[currentImage].imageHistogram, imageStore[currentImage].fileName);

		std::ofstream file;
		file.open(logLocationConv + logFileName, std::ios_base::app);
		file << "Histogram of image | " << imageStore[currentImage].fileName << " | saved at | " << conversionDirectory << " |" << std::endl;
		file.close();
	}
	else {
		if (dir_name == QDir::homePath()) {
			ui.statusBar->showMessage("Please select a directory");
			selectDirectory();
		}
	}
}

// Function to save results text file
void applicationGUI::saveResults() {
	dir_name = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::homePath());
	if (dir_name != QDir::homePath() && dir_name != NULL) {
		dir_name = dir_name + "/";
		std::string conversionDirectory = dir_name.toLocal8Bit().constData();
		set_text_file(conversionDirectory, imageStore[currentImage].fileName, cThreshold);
		save_statistics(imageStore[currentImage].pixelCount, imageStore[currentImage].meanAll, imageStore[currentImage].stdDevAll,
			imageStore[currentImage].varAll, "all", imageStore[currentImage].fileName, conversionDirectory);
		save_statistics(imageStore[currentImage].pixelAbove, imageStore[currentImage].meanAbove, imageStore[currentImage].stdDevAbove,
			imageStore[currentImage].varAbove, "above/equal", imageStore[currentImage].fileName, conversionDirectory);
		save_scores(imageStore[currentImage].spotScore, imageStore[currentImage].filmScore, imageStore[currentImage].aestheticScore,
			imageStore[currentImage].fileName, conversionDirectory);

		std::ofstream file;
		file.open(logLocationConv + logFileName, std::ios_base::app);
		file << "Statistics/results of image | " << imageStore[currentImage].fileName << " | saved at | " << conversionDirectory << " |" << std::endl;
		file.close();
	}
	else {
		if (dir_name == QDir::homePath()) {
			ui.statusBar->showMessage("Please select a directory");
			selectDirectory();
		}
	}
}

// Function to save all contents currently stored within the vector
void applicationGUI::saveAll() {
	int i;
	dir_name = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::homePath());
	if (dir_name != QDir::homePath() && dir_name != NULL) {
		dir_name = dir_name + "/";
		std::string conversionDirectory = dir_name.toLocal8Bit().constData();
		std::string currentDirectory;
		create_directories(conversionDirectory);
		std::ofstream file;
		file.open(logLocationConv + logFileName, std::ios_base::app);
		for (i = 1; i < imageStore.size(); i++) {
			currentDirectory = conversionDirectory + "histograms/";
			save_histogram(currentDirectory, imageStore[i].imageHistogram, imageStore[i].fileName);
			file << "Histogram of image | " << imageStore[i].fileName << " | saved at | " << currentDirectory << " |" << std::endl;

			currentDirectory = conversionDirectory + "statistics/";
			set_text_file(currentDirectory, imageStore[i].fileName, cThreshold);
			save_statistics(imageStore[i].pixelCount, imageStore[i].meanAll, imageStore[i].stdDevAll,
				imageStore[i].varAll, "all", imageStore[i].fileName, currentDirectory);
			save_statistics(imageStore[i].pixelAbove, imageStore[i].meanAbove, imageStore[i].stdDevAbove,
				imageStore[i].varAbove, "above/equal", imageStore[i].fileName, currentDirectory);
			save_scores(imageStore[i].spotScore, imageStore[i].filmScore, imageStore[i].aestheticScore,
				imageStore[i].fileName, currentDirectory);
			file << "Statistics/results of image | " << imageStore[i].fileName << " | saved at | " << currentDirectory << " |" << std::endl;
		}
		file.close();
	}
	else {
		if (dir_name == QDir::homePath()) {
			ui.statusBar->showMessage("Please select a directory");
			selectDirectory();
		}
	}
}

// Function for obtaining user input for editing the histogram
void applicationGUI::editHistogram()
{
	histogramSettingsDialog test;
	test.setModal(true);
	// Set GUI elements to current settings
	test.optionDataScale->setText(QString::number(dataScale));
	test.optionThreshold->setText(QString::number(cThreshold));
	test.optionScalePXI->setText(QString::number(perXScale));
	test.optionLineGraph->setChecked(lineGraph);
	test.optionScalePI->setChecked(perIntensity);
	test.optionShowThreshold->setChecked(showThreshold);
	test.optionSmoothedLine->setChecked(smoothedLine);
	test.optionPercentage->setCurrentIndex(pixelPercentage);
	test.exec();
	// Retrieve new settings from GUI elements
	dataScale = test.optionDataScale->text().toDouble();
	lineGraph = test.optionLineGraph->isChecked();
	pixelPercentage = test.optionPercentage->currentIndex();
	perIntensity = test.optionScalePI->isChecked();
	perXScale = test.optionScalePXI->text().toInt();
	showThreshold = test.optionShowThreshold->isChecked();
	smoothedLine = test.optionSmoothedLine->isChecked();
	cThreshold = test.optionThreshold->text().toInt();

	if (singleFile) {
		imageStore = process_image(currentDirectoryPath, dataScale, perXScale, cThreshold, pixelPercentage, showThreshold, smoothedLine, perIntensity, lineGraph);
	}
	else {
		imageStore = process_all(currentDirectoryPath, dataScale, perXScale, cThreshold, pixelPercentage, showThreshold, smoothedLine, perIntensity, lineGraph);
	}

	updateGUI();
}

// Function to view the log file within the GUI
void applicationGUI::viewLogFile() {
	logFileDisplay test;
	test.setModal(true);

	std::string comeOn = logLocationConv + logFileName;
	QString help = QString::fromStdString(comeOn);
	QFile file(help);
	file.open(QIODevice::ReadOnly);
	QTextStream in(&file);

	test.logDisplay->setText(in.readAll());
	file.close();
	test.exec();
}

// Function for 'pop contents'
void applicationGUI::popUpDisplay() {
	outImageDisplay* test = new outImageDisplay(this);

	QPixmap tempPix;
	if (ui.histDisplay->pixmap()) {
		tempPix = *ui.histDisplay->pixmap();
		test->histDisplay->setPixmap(tempPix);
	}
	if (ui.inputDisplay->pixmap()) {
		tempPix = *ui.inputDisplay->pixmap();
		test->inputDisplay->setPixmap(tempPix);
	}
	QString tempStr;
	QTextDocument *doc = ui.textBrowser->document();
	tempStr = doc->toHtml();

	test->textBrowser->setText(tempStr);

	test->show();
}