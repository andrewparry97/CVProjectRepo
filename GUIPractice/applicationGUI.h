#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GUIPractice.h"
#include "histogramSettingsDialog.h"
#include "Ui_histogramSettingsDialog.h"

class applicationGUI : public QMainWindow
{
	Q_OBJECT

public:
	applicationGUI(QWidget *parent = Q_NULLPTR);

public slots:
	void selectDirectory();
	void selectFile();
	void nextImage();
	void prevImage();
	void saveHist();
	void saveResults();
	void saveAll();
	void editHistogram();
	void updateSortType();
	void selectLogLocation();
	void viewLogFile();
	void popUpDisplay();
	void toggleSpotMode();

private:
	Ui::GUIPracticeClass ui;
	void updateGUI();
};