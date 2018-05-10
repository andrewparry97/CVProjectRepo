#include "backendCode.h"
#include <atlstr.h>

// Improves readability
using namespace std;
using namespace cv;

// Obtain histogram data from image
vector<double> obtain_histogram(Mat image) {
	vector<double> histogram(MAX_INTENSITY);
	int position = 0, i, j;
	for (i = 0; i < image.rows; i++) {
		for (j = 0; j < image.cols; j++) {
			position = (int)image.at<uchar>(i, j);
			histogram[position]++;
		}
	}
	return histogram;
}

// Obtain scaling factor for drawing histogram
double scale_histogram(int max, int pixelCount, int histHeight) {
	double vScale = 1;
	while ((((double)max / pixelCount)*(histHeight*vScale)) <= ((double)histHeight / 4) * 3) {
		vScale += 0.5;
	}
	return vScale;
}


// Count pixels above/equal to threshold
int count_greater(vector<double> histogram, int cThreshold) {
	int pixelCount = 0, i;
	for (i = 0; i < histogram.size(); i++) {
		if (i >= cThreshold) {
			pixelCount += histogram[i];
		}
	}
	return pixelCount;
}


// Draw the y-axis of the histogram
Mat draw_vertical(vector<double> histogram, double vScale, int pixelCount, int histHeight, int histWidth, double dataScale, int pixelPercentage) {
	Mat outputHist(histHeight, histWidth, CV_8UC1, Scalar(MAX_INTENSITY, MAX_INTENSITY, MAX_INTENSITY));
	char textVar[16];
	double yValues;
	if (pixelPercentage == 0) {
		yValues = (double)pixelCount;
	}
	else {
		yValues = 100;
	}
	int mark = 0, i;
	for (i = 0; i < 100; i++) {
		if (i % 10 == 0 && i > 0) {
			mark = 5;
			snprintf(textVar, 10, "%.0f", ((((double)yValues / vScale) / 100) / dataScale)*i);
			putText(outputHist, textVar, Point(2 * SCALE, histHeight - (i + 9)*SCALE), 1, 0.4*SCALE, 0);
		}
		else {
			mark = 0;
		}
		rectangle(
			outputHist,
			Point(30 * SCALE - mark, histHeight - (i + 10)*SCALE),
			Point(30 * SCALE, histHeight - (i + 10)*SCALE - SCALE),
			Scalar(0, 0, 0),
			CV_FILLED
		);
	}
	return outputHist;
}


// Draw the x-axis of the histogram, along with the data
Mat draw_horizontal(vector<double> histogram, double vScale, int pixelCount, int histHeight, int histWidth, double dataScale, int pixelPercentage, int perXScale, int cThreshold, bool showThreshold, bool lineGraph) {
	Mat outputHist(histHeight, histWidth, CV_8UC1, Scalar(MAX_INTENSITY, MAX_INTENSITY, MAX_INTENSITY));
	outputHist = draw_vertical(histogram, vScale, pixelCount, histHeight, histWidth, dataScale, pixelPercentage);
	char textVar[16];
	int mark = 0, i, j, prevX, prevY;
	double test;
	double percentage = 0;
	double linePlot = 0;
	for (i = 0; i < histogram.size();)
	{
		test = 0;
		for (j = 0; j < perXScale && i+j < histogram.size(); j++) {
			test += (double)histogram[i + j];
		}
		test = (double)test / j;
		percentage = ((double)test / pixelCount)*(histHeight*vScale);
		if (lineGraph == true) {
			linePlot = percentage;
			percentage = 0;
		}
		for (j; j > 0; j--) {
			if (i % 25 == 0 && i > 0) {
				mark = 5;
				snprintf(textVar, 10, "%d", i);
				putText(outputHist, textVar, Point((i + 26)*SCALE, histHeight - 2 * SCALE), 1, 0.4*SCALE, 0);
			}
			else if (i % 5 == 0 && i > 0) {
				mark = 2;
			}
			else {
				mark = 0;
			}
			if (showThreshold) {
				if (i == cThreshold) {
					rectangle(
						outputHist,
						Point((i + 30)*SCALE, histHeight - 10 * SCALE),
						Point((i + 30)*SCALE, 0 - 10 * SCALE),
						Scalar(200, 200, 200),
						CV_FILLED
					);
				}
			}
			rectangle(
				outputHist,
				Point((i + 30)*SCALE, histHeight - 10 * SCALE + mark),
				Point(SCALE + (i + 30)*SCALE, (histHeight - percentage * dataScale) - 10 * SCALE),
				Scalar(0, 0, 0),
				CV_FILLED
			);
			if (lineGraph == true) {
				if (i == 0) {
					line(
						outputHist,
						Point((i + 30)*SCALE, (histHeight - linePlot * dataScale) - 10 * SCALE),
						Point(SCALE + (i + 30)*SCALE, (histHeight - linePlot * dataScale) - 10 * SCALE),
						Scalar(0, 0, 0),
						1
					);
				}
				else {
					line(
						outputHist,
						Point(prevX, prevY),
						Point(SCALE + (i + 30)*SCALE, (histHeight - linePlot * dataScale) - 10 * SCALE),
						Scalar(0, 0, 0),
						1
					);
				}
				prevX = SCALE + (i + 30)*SCALE;
				prevY = (histHeight - linePlot * dataScale) - 10 * SCALE;
			}
			i++;
		}
	}
	return outputHist;
}


// Calculate the mean
double find_mean(vector<double> histogram, int pixels, int start) {
	double score = 0;
	double mean = 0;
	int i;
	for (i = start; i < histogram.size(); i++) {
		score += histogram[i] * i;
	}
	mean = (double)score / pixels;
	return mean;
}


// Calculate the variance
double find_variance(vector<double> histogram, double mean, int pixels, int start) {
	int score = 0, i;
	double variance = 0;
	for (i = start; i < histogram.size(); i++) {
		score = pow((i - mean), 2)*histogram[i];
		variance += score;
	}
	variance = (double)variance / pixels;
	return variance;
}

// Count spots in an image
vector<imageContents> count_spots(vector<imageContents> imageStore, int i, Mat image, int cThreshold) {
	int count = 0, imageSize;
	Mat thresh_image, drawing;
	RNG rng(12345);
	Mat test_image = image; 
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	thresh_image = test_image;

	blur(thresh_image, thresh_image, Size(3, 3));
	threshold(thresh_image, thresh_image, cThreshold, MAX_INTENSITY - 1, THRESH_BINARY);
	findContours(thresh_image, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	imageSize = image.rows*image.cols;
	imageSize = imageSize / 5;
	drawing = Mat::zeros(thresh_image.size(), CV_8UC3);
	for (int i = 0; i< contours.size(); i++)
	{
		if (contours[i].size() > 2 && contourArea(contours[i]) < imageSize) {
			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
			count++;
		}
	}
	imageStore[i].threshImage = drawing.clone();
	imageStore[i].spots = count;
	return imageStore;
}

// Update scores
vector<imageContents> update_scores(int spots, double variance, double mean, vector<imageContents> imageStore, int i) {
	double spot, film, aesthetic;
	spot = 10 - 10 * ((double)spots / 50);
	if (spot > 10) {
		spot = 10;
	}
	else if (spot < 0) {
		spot = 0;
	}
	imageStore[i].spotScore = spot;
	film = 10 - (10 * ((double)mean / 50));
	if (film > 10) {
		film = 10;
	}
	else if (film < 0) {
		film = 0;
	}
	imageStore[i].filmScore = film;
	aesthetic = 10 - 10 * ((double)variance / 50);
	aesthetic = (aesthetic*0.4) + (spot*0.2) + (film*0.4);
	if (aesthetic > 10) {
		aesthetic = 10;
	}
	else if (aesthetic < 0) {
		aesthetic = 0;
	}
	imageStore[i].aestheticScore = aesthetic;
	return imageStore;
}

// Create output directories
void create_directories(string directory) {
	string dito;
	dito = string(directory) + "statistics/";
	LPCSTR STATSDIR = LPCSTR(dito.c_str());
	CreateDirectoryA(STATSDIR, NULL);
	dito = string(directory) + "histograms/";
	LPCSTR HISTDIR = LPCSTR(dito.c_str());
	CreateDirectoryA(HISTDIR, NULL);
	dito = string(directory) + "histograms/";

}

// Save histogram
void save_histogram(string directory, Mat histogram, string name) {
	string outputName = "Histogram_" + name;
	string outputLocation = directory + outputName;
	imwrite(outputLocation, histogram);
}

// Create/reset text file
void set_text_file(string conversionDirectory, string fileName, int threshold) {
	ofstream file;
	fileName.resize(fileName.length() - 4, '-');
	file.open(conversionDirectory + fileName + ".txt");
	file << fileName << " | Threshold = " << threshold << endl << endl;
	file.close();
}

// Save statistics of individual result
void save_statistics(int pixels, double mean, double stdDev, double variance, string label, string fileName, string location) {
	ofstream file;
	fileName.resize(fileName.length() - 4, '-');
	fileName = location + fileName + ".txt";
	file.open(fileName, ios_base::app);
	file << fixed;
	file << setprecision(1);
	file << "pixels " << label << " = " << pixels << endl;
	file << "mean " << label << " = " << mean << endl;
	file << "stdDev " << label << " = " << stdDev << endl;
	file << "variance " << label << " = " << variance << endl << endl;
	file.close();
}

// Save scores
void save_scores(double spot, double film, double aesthetic, string fileName, string location) {
	ofstream file;
	fileName.resize(fileName.length() - 4, '-');
	fileName = location + fileName + ".txt";
	file.open(fileName, ios_base::app);
	file << fixed;
	file << setprecision(1);
	file << "spot" << " = " << spot << " | ";
	file << "film" << " = " << film << " | ";
	file << "aesthetic" << " = " << aesthetic;
	file.close();
}

// Main method for sequence of functions
vector<imageContents> process_all(string directory, double dataScale, int perXScale, int cThreshold, int pixelPercentage, bool showThreshold, bool smoothedLine, bool perIntensity, bool lineGraph) {
	
	// Declare all variables
	String location;
	int max, histWidth, histHeight, i;
	double vScale;

	// Create vector to store histogram data
	vector<double> histogram(MAX_INTENSITY);

	// Create vector to store image names
	vector<imageContents> imageStore;

	// Create the histogram, determine dimensions
	histWidth = (MAX_INTENSITY + 32)*SCALE + SCALE; histHeight = (DEFAULT_HEIGHT + 10)*SCALE;
	Mat outputHist(histHeight, histWidth, CV_8UC1, Scalar(MAX_INTENSITY, MAX_INTENSITY, MAX_INTENSITY));

	// For file handling
	WIN32_FIND_DATAA FindFileData;
	HANDLE hFind;

	// Locate input folders
	// DIRECTORY + "*"
	string dito = directory + "*";
	LPCSTR INPUTPATH = LPCSTR(dito.c_str());
	hFind = FindFirstFileA(INPUTPATH, &FindFileData);

	// Obtain and store image names
	int x = 0;
	while (FindNextFileA(hFind, &FindFileData)) {
		string test = FindFileData.cFileName;
		imageStore.push_back(imageContents());
		imageStore[x].fileName = test;
		x++;
	}

	// Process each image
	for (i = 1; i < imageStore.size(); i++) {

		// Retrieve current image location
		location = string(directory) + imageStore[i].fileName;

		// Read input image
		imageStore[i].inputImage = imread(location, IMREAD_GRAYSCALE);

		// Obtain histogram and properties
		histogram = obtain_histogram(imageStore[i].inputImage);
		imageStore[i].pixelCount = accumulate(histogram.begin(), histogram.end(), 0);
		max = *max_element(histogram.begin(), histogram.end());

		// Obtain vertical scale for drawing histogram
		vScale = scale_histogram(max, imageStore[i].pixelCount, histHeight);

		// Obtain count for pixels above threshold
		imageStore[i].pixelAbove = count_greater(histogram, cThreshold);

		// Draw the histogram
		if (perIntensity) {
			perXScale = 1;
		}
		imageStore[i].imageHistogram = draw_horizontal(histogram, vScale, imageStore[i].pixelCount, histHeight, histWidth, dataScale, pixelPercentage, perXScale, cThreshold, showThreshold, lineGraph);

		// Calculate the mean values
		imageStore[i].meanAll = find_mean(histogram, imageStore[i].pixelCount, 0);
		imageStore[i].meanAbove = find_mean(histogram, imageStore[i].pixelAbove, cThreshold);

		// Calculate the variance values
		imageStore[i].varAll = find_variance(histogram, imageStore[i].meanAll, imageStore[i].pixelCount, 0);
		imageStore[i].varAbove = find_variance(histogram, imageStore[i].meanAbove, imageStore[i].pixelAbove, cThreshold);

		// Calculate the standard deviation values
		imageStore[i].stdDevAll = sqrt(imageStore[i].varAll);
		imageStore[i].stdDevAbove = sqrt(imageStore[i].varAbove);

		// Count spots
		Mat test = imageStore[i].inputImage.clone();
		imageStore = count_spots(imageStore, i, test, cThreshold);

		imageStore = update_scores(imageStore[i].spots, imageStore[i].varAll, imageStore[i].meanAll, imageStore, i);

		cvtColor(imageStore[i].inputImage, imageStore[i].inputImage, CV_GRAY2RGB);
		cvtColor(imageStore[i].imageHistogram, imageStore[i].imageHistogram, CV_GRAY2RGB);
		
	}
	return imageStore;
}

vector<imageContents> process_image(string fileLoc, double dataScale, int perXScale, int cThreshold, int pixelPercentage, bool showThreshold, bool smoothedLine, bool perIntensity, bool lineGraph) {
	// Declare all variables
	String location;
	int max, histWidth, histHeight, i;
	double vScale;

	// Create vector to store histogram data
	vector<double> histogram(MAX_INTENSITY);

	// Create vector to store image name
	vector<imageContents> imageStore;
	imageStore.push_back(imageContents());

	// Create the histogram, determine dimensions
	histWidth = (MAX_INTENSITY + 32)*SCALE + SCALE; histHeight = (DEFAULT_HEIGHT + 10)*SCALE;
	Mat outputHist(histHeight, histWidth, CV_8UC1, Scalar(MAX_INTENSITY, MAX_INTENSITY, MAX_INTENSITY));

	i = 0;

	// Obtain and store image names
	LPCSTR help = LPCSTR(fileLoc.c_str());
	imageStore[i].fileName = PathFindFileNameA(help);
	imageStore[i].fileName = imageStore[i].fileName;
	
	// Process image . . .

	// Retrieve current image location
	location = string(fileLoc);

	// Read input images
	imageStore[i].inputImage = imread(location, IMREAD_GRAYSCALE);

	// Obtain histogram and properties
	histogram = obtain_histogram(imageStore[i].inputImage);
	imageStore[i].pixelCount = accumulate(histogram.begin(), histogram.end(), 0);
	max = *max_element(histogram.begin(), histogram.end());

	// Obtain vertical scale for drawing histogram
	vScale = scale_histogram(max, imageStore[i].pixelCount, histHeight);

	// Obtain count for pixels above threshold
	imageStore[i].pixelAbove = count_greater(histogram, cThreshold);

	// Draw the histogram
	if (perIntensity) {
		perXScale = 1;
	}
	imageStore[i].imageHistogram = draw_horizontal(histogram, vScale, imageStore[i].pixelCount, histHeight, histWidth, dataScale, pixelPercentage, perXScale, cThreshold, showThreshold, lineGraph);

	// Calculate the mean values
	imageStore[i].meanAll = find_mean(histogram, imageStore[i].pixelCount, 0);
	imageStore[i].meanAbove = find_mean(histogram, imageStore[i].pixelAbove, cThreshold);

	// Calculate the variance values
	imageStore[i].varAll = find_variance(histogram, imageStore[i].meanAll, imageStore[i].pixelCount, 0);
	imageStore[i].varAbove = find_variance(histogram, imageStore[i].meanAbove, imageStore[i].pixelAbove, cThreshold);

	// Calculate the standard deviation values
	imageStore[i].stdDevAll = sqrt(imageStore[i].varAll);
	imageStore[i].stdDevAbove = sqrt(imageStore[i].varAbove);

	// Count spots
	Mat test = imageStore[i].inputImage.clone();
	imageStore = count_spots(imageStore, i, test, cThreshold);

	imageStore = update_scores(imageStore[i].spots, imageStore[i].varAll, imageStore[i].meanAll, imageStore, i);

	cvtColor(imageStore[i].inputImage, imageStore[i].inputImage, CV_GRAY2RGB);
	cvtColor(imageStore[i].imageHistogram, imageStore[i].imageHistogram, CV_GRAY2RGB);

	return imageStore;
}