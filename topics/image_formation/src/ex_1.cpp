#include <Eigen/Dense>
#include <iostream>
#include <vector>

#include "algebra_ext/eigen_ext.h"
#include "algebra_ext/line_ext.h"
#include "image_formation/least_squares_basic.h"
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace image_formation;
using namespace Eigen;
using namespace algebra_ext;

int main(int argc, char *argv[]) {
    Matrix<float, 1, 2> point;
    Matrix<float, -1, 3> lines(3, 3);
    lines << 1.f, 2.f, 3.f,
        1.f, 3.f, 20.f,
        7.f, 6.f, 2.f;

    std::cout << "Lines:\n " << lines << std::endl;

    if (LeastSquaresBasic::find_lines_intersection_point_2d(point, lines)) {
        std::cout << "Point: " << point << std::endl;

        auto x = EigenExt::eigen2stdvec_2d<double>(point.col(0).array());
        auto y = EigenExt::eigen2stdvec_2d<double>(point.col(1).array());

        float offset = 100;
        VectorXf X(2);
        X << x[0] - offset, x[0] + offset;

        for (int i = 0; i < lines.rows(); i++) {
            auto line_pts = LineExt::get_line_points_2d(lines.row(i), X);
            auto line_x = EigenExt::eigen2stdvec_2d<double>(line_pts.col(0).array());
            auto line_y = EigenExt::eigen2stdvec_2d<double>(line_pts.col(1).array());

            std::cout << line_pts << std::endl;
            plt::named_plot("plot " + std::to_string(i + 1), line_x, line_y);
        }

        plt::scatter(x, y, 100);
        plt::legend();
        plt::show();
    }

    return 0;
}