#include "Sobel.h"

Sobel::Sobel(cv::Mat& inputImage) 
{
    //convert image to grayscale
    cv::cvtColor(inputImage, this->img, cv::COLOR_BGR2GRAY);
    //define Sobel kernels
    sobelKernelX = (cv::Mat_<float>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    sobelKernelY = (cv::Mat_<float>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
}

cv::Mat Sobel::computeGradientMagnitude(cv::Mat& gradientX, cv::Mat& gradientY) 
{
    //compute gradient magnitude 
    cv::Mat gradientMagnitude;
    float norm;
    float gradientXValue;
    float gradientYValue;

    // Create a result matrix with the same size as the input matrices
    gradientMagnitude.create(gradientX.size(), gradientX.type());

    // Calculate gradient magnitude
    for (int x = 0; x < gradientX.rows; x++) 
    {
        for (int y = 0; y < gradientX.cols; y++) 
        {
            gradientXValue = static_cast<float>(gradientX.at<float>(x, y));
            gradientYValue = static_cast<float>(gradientY.at<float>(x, y));

            // Calculate gradient norm
            norm = std::sqrt(gradientXValue * gradientXValue + gradientYValue * gradientYValue);

            // Set the result pixel value
            gradientMagnitude.at<float>(x, y) = norm;
        }
    }

    cv::normalize(gradientMagnitude, gradientMagnitude, 0, 255, cv::NORM_MINMAX, CV_8U);

    return gradientMagnitude;
}

cv::Mat Sobel::getEdges()
{
    //function used to group the steps of the algorithm
    cv::Mat gradientX = convolve(this->img, sobelKernelX);
    cv::Mat gradientY = convolve(this->img, sobelKernelY);
    cv::Mat gradientMagnitude = computeGradientMagnitude(gradientX, gradientY);
    
    return gradientMagnitude;
}

cv::Mat Sobel::convolve(cv::Mat& inputImage, cv::Mat& kernel) 
{
    cv::Mat filtered;

    //create a result matrix with the same size as the input image
    filtered.create(inputImage.size(), CV_32F);

    //iterate through the input image pixels
    for (int y = 1; y < inputImage.rows - 1; ++y) 
    {
        for (int x = 1; x < inputImage.cols - 1; ++x) 
        {
            //calculate the convolution sum
            float sum = 0.0;
            for (int i = -1; i <= 1; i++) 
            {
                for (int j = -1; j <= 1; j++) 
                {
                    sum += kernel.at<float>(i + 1, j + 1) * static_cast<float>(inputImage.at<uchar>(y + i, x + j));
                }
            }
            //set the result pixel value
            filtered.at<float>(y, x) = sum;
        }
    }

    return filtered;
}