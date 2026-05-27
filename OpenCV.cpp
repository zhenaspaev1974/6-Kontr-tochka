#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    // Загружаем изображение
    cv::Mat image = cv::imread("path_to_your_image.jpg"); 
    
    if (image.empty()) {
        std::cerr << "Error: Failed to load image." << std::endl;
        return -1;
    }

    // Создаем окна для отображения
    cv::namedWindow("Original image", cv::WINDOW_NORMAL);
    cv::namedWindow("Processed image", cv::WINDOW_NORMAL);

    // Конвертируем в оттенки серого
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Применяем размытие по Гауссу
    cv::Mat blurredImage;
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(5, 5), 0);

    // Отображаем результаты
    cv::imshow("Original image", image);
    cv::imshow("Processed image", blurredImage);
    cv::waitKey(0);
    return 0;
}
