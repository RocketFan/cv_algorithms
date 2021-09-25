#include <iostream>
#include <vector>
#include <Eigen/Dense>

#include "image_formation/least_squares_basic.h"
#include "matplotlibcpp.h"
#include "eigen_ext.h"

namespace plt = matplotlibcpp;
using namespace image_formation;
using namespace Eigen;

int main(int argc, char *argv[])
{
    Matrix<float, 1, 2> point(1, 2);
    Matrix<float, -1, 3> lines(3, 3);
    lines << 1.f, 2.f, 3.f,
        2.f, 5.f, 1.f,
        7.f, 6.f, 2.f;

    std::cout << "Lines:\n " << lines << std::endl;

    if (LeastSquaresBasic::find_lines_intersection_point_2d(point, lines))
    {
        std::cout << "Point: " << point << std::endl;
        std::cout << point.array() << std::endl;
        
        auto x = EigenExt::eigen2stdvec_2d<double>(point.col(0).array());
        auto y = EigenExt::eigen2stdvec_2d<double>(point.col(1).array()); 

        plt::scatter(x, y, 100);
        plt::plot();
        plt::show();
    }

    return 0;
}