#include <opencv2/opencv.hpp>
#include <fmt/core.h>
#include "tools.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        fmt::print("Usage: {} <image_path>\n", argv[0]);
        return -1;
    }

    // 读取图片
    cv::Mat image = cv::imread(argv[1]);
    if (image.empty()) {
        fmt::print("Failed to load image: {}\n", argv[1]);
        return -1;
    }

    fmt::print("成功加载图像: {} ({}x{})\n", argv[1], image.cols, image.rows);

    // 调用缩放函数
    ScalingResult result = scaleAndCenterImage(image, 640, 640);
    
    // 显示结果
    cv::imshow("Scaled Image", result.scaledImage);
    cv::waitKey(0);
    
    return 0;
}