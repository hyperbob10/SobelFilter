#ifndef SOBEL_H
#define SOBEL_H

#include <opencv2/opencv.hpp>

class Sobel
{
public:
    Sobel(cv::Mat& inputImage);
    cv::Mat getEdges();

private:
    cv::Mat sobelKernelX;
    cv::Mat sobelKernelY;
    cv::Mat img;
    cv::Mat convolve(cv::Mat& inputImage , cv::Mat& kernel);
    cv::Mat computeGradientMagnitude(cv::Mat& gradientX , cv::Mat& gradientY);
};

#endif 
