#include <Eigen/Dense>
#include <iostream>
#include <vector>
#include <matplotlibcpp.h>

#include "algebra_ext/line_ext.h"
#include "algebra_ext/eigen_ext.h"
#include "image_formation/least_squares_basic.h"

namespace plt = matplotlibcpp;
using namespace image_formation;
using namespace Eigen;
using namespace algebra_ext;

const int SIZE = 100;

void plot_lines_intersection_point(const MatrixXf &lines)
{
    const int offset = 30;

    auto point = LeastSquaresBasic::find_lines_intersection_point_2d(lines);

    auto X = EigenExt::eigen2stdvec_2d<double>(point.row(0));
    auto Y = EigenExt::eigen2stdvec_2d<double>(point.row(1));

    VectorXf lines_X(2);
    lines_X << X[0] - offset, X[0] + offset;

    // Getting lines points to visualize theme
    for (int i = 0; i < lines.rows(); i++)
    {
        auto line_pts = LineExt::get_line_points_2d(lines.row(i), lines_X);
        auto line_x = EigenExt::eigen2stdvec_2d<double>(line_pts.col(0).array());
        auto line_y = EigenExt::eigen2stdvec_2d<double>(line_pts.col(1).array());

        plt::named_plot("plot " + std::to_string(i + 1), line_x, line_y);
    }

    plt::scatter(X, Y, SIZE);
    plt::legend();
    plt::show();
}

int main(int argc, char *argv[])
{
    Matrix<float, -1, 3> lines(4, 3);
    lines << 5.f, 2.f, 50.f,
        1.f, 6.f, 20.f,
        -1.f, 3.f, 50.f,
        15.f, 10.f, 3.f;

    std::cout << lines.rowwise().sum() << std::endl << std::endl;

    plot_lines_intersection_point(lines);

    return 0;
}