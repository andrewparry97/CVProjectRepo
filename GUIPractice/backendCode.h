#ifndef BACKENDCODE_H
#define BACKENDCODE_H

// Include neccesary libraries
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <windows.h>
#include <iomanip>
#include <fstream>

// Definitions/constants to improve code readability
#define SCALE 2 // Image scaling
#define ZOOM 1 // Data scaling
#define MAX_INTENSITY 256
#define DEFAULT_HEIGHT 100
#define THRESHOLD 26

//struct for containing an image along with all of it's contents such as technical scores
struct imageContents {
	int id, pixelCount, pixelAbove, spots;
	std::string fileName;
	cv::Mat inputImage;
	cv::Mat threshImage;
	cv::Mat imageHistogram;
	double meanAll, meanAbove, varAll, varAbove, stdDevAll, stdDevAbove, spotScore, filmScore, aestheticScore;
};

// Functions for creating histogram
std::vector<double> obtain_histogram(cv::Mat image());
double scale_histogram(int max, int pixelCount, int histHeight);
int count_greater(std::vector<double> histogram, int cThreshold);
cv::Mat draw_vertical(std::vector<double> histogram, double vScale, int pixelCount, int histHeight, int histWidth, double dataScale, int pixelPercentage);
cv::Mat draw_horizontal(std::vector<double> histogram, double vScale, int pixelCount, int histHeight, int histWidth, double dataScale, int pixelPercentage);

// Functions for calculating statistics and scores
double find_mean(std::vector<double> histogram, int pixels, int start);
double find_variance(std::vector<double> histogram, double mean, int pixels, int start);
std::vector<imageContents> count_spots(std::vector<imageContents> imageStore, int i, cv::Mat image, int cThreshold);
std::vector<imageContents> update_scores(int spots, double variance, double mean, std::vector<imageContents> imageStore, int i);

// Other functions
void create_directories(std::string directory);
void save_histogram(std::string directory, cv::Mat histogram, std::string name);
void set_text_file(std::string conversionDirectory, std::string fileName, int threshold);
void save_statistics(int pixels, double mean, double stdDev, double variance, std::string label, std::string fileName, std::string location);
void save_scores(double spot, double film, double aesthetic, std::string fileName, std::string location);

// Main functions for processing, each hold a sequence of functions
std::vector<imageContents> process_all(std::string directory, double dataScale, int perXScale, int cThreshold, int pixelPercentage, bool showThreshold, bool smoothedLine, bool perIntensity, bool lineGraph);
std::vector<imageContents> process_image(std::string fileLoc, double dataScale, int perXScale, int cThreshold, int pixelPercentage, bool showThreshold, bool smoothedLine, bool perIntensity, bool lineGraph);
#endif BACKENDCODE_H