#include <iostream>
#include <opencv2/highgui.hpp>
#include <Eigen/Dense>

int main(int argc, char *argv[])
{
    std::cout << "Hello main" << std::endl;
    // cv::namedWindow("Window");

    while (true)
    {
        cv::Mat mat(300, 300, CV_8UC3, cv::Scalar(0, 0, 0)), img;
        mat.convertTo(img, CV_8U);
        std::cout << img.type() << std::endl;
        cv::imshow("Window", img);
        char c = (char)cv::waitKey(0);

        if (c == 27)
            return 0;
    }

    return 1;
}