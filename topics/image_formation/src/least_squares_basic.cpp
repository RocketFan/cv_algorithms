#include "image_formation/least_squares_basic.h"

#include <iostream>

using namespace image_formation;

bool LeastSquaresBasic::find_lines_intersection_point_2d(Matrix<float, 1, 2> &out_point, Matrix<float, -1, 3> &in_lines) {
    int n_lines = in_lines.rows();

    if (n_lines < 2) {
        std::cout << "Expect min 2 in_lines rows, got " << n_lines << std::endl;

        return false;
    }

    Matrix<float, 1, 3> cross_lines = in_lines.row(0);

    for (int i = 1; i < n_lines - 1; i++) {
        std::cout << "Cross of lines " << i << ":\n"
                  << cross_lines << std::endl;
        cross_lines = cross_lines.cross(in_lines.row(i));
    }

    MatrixXf point(1, 2);
    point << cross_lines(0, 0), cross_lines(0, 1);
    out_point = point / cross_lines(0, 2);

    return true;
}