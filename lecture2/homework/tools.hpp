#ifndef TOOLS_HPP
#define TOOLS_HPP

#include <opencv2/opencv.hpp>
#include <fmt/core.h>

struct ScalingResult {
    cv::Mat scaledImage;
    double scaleRatio;
    int offsetX;
    int offsetY;
};

ScalingResult scaleAndCenterImage(const cv::Mat& inputImage, int targetWidth, int targetHeight);

#endif