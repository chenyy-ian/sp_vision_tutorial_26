#include "tools.hpp"

ScalingResult scaleAndCenterImage(const cv::Mat& inputImage, int targetWidth, int targetHeight) {
    ScalingResult result;
    
    // 计算缩放比例
    double scaleW = static_cast<double>(targetWidth) / inputImage.cols;
    double scaleH = static_cast<double>(targetHeight) / inputImage.rows;
    result.scaleRatio = std::min(scaleW, scaleH);
    
    // 计算缩放后的尺寸
    int newWidth = static_cast<int>(inputImage.cols * result.scaleRatio);
    int newHeight = static_cast<int>(inputImage.rows * result.scaleRatio);
    
    // 缩放图像
    cv::Mat resizedImage;
    cv::resize(inputImage, resizedImage, cv::Size(newWidth, newHeight));
    
    // 创建目标画布（黑色背景）
    result.scaledImage = cv::Mat::zeros(targetHeight, targetWidth, inputImage.type());
    
    // 计算偏移量（居中放置）
    result.offsetX = (targetWidth - newWidth) / 2;
    result.offsetY = (targetHeight - newHeight) / 2;
    
    // 将缩放后的图像复制到画布中央
    cv::Rect roi(result.offsetX, result.offsetY, newWidth, newHeight);
    resizedImage.copyTo(result.scaledImage(roi));
    
    // 输出参数
    fmt::print("缩放比例: {:.4f}\n", result.scaleRatio);
    fmt::print("水平偏移: {} 像素\n", result.offsetX);
    fmt::print("垂直偏移: {} 像素\n", result.offsetY);
    fmt::print("缩放后尺寸: {}x{}\n", newWidth, newHeight);
    
    return result;
}