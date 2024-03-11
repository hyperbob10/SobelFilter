#include <opencv2/opencv.hpp>
#include "Sobel.h"

int main(int argc, char** argv)
{
    // Read an image
    cv::Mat inputImage = cv::imread(argv[1]);

    if (inputImage.empty()) 
    {
        std::cout << "Error: Unable to read the input image." << std::endl;
        return -1;
    }

    cv::imshow("input image" , inputImage);
    cv::waitKey(0);

    //create sobe filter object
    Sobel* sobel = new Sobel(inputImage);

    //get the edges through the Sobel Algorithm
    cv::Mat result = sobel->getEdges();

    //show the final result
    cv::imshow("output image" , result);
    cv::waitKey(0);

    delete sobel;
    sobel = nullptr;
    return 0;
}
