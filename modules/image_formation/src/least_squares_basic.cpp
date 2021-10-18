#include "image_formation/least_squares_basic.h"

#include <algebra_ext/line_ext.h>
#include <iostream>

using namespace image_formation;
using namespace algebra_ext;

Vector2f LeastSquaresBasic::find_lines_intersection_point_2d(const Matrix<float, -1, 3> &lines) {
    int n_lines = lines.rows();

    if (n_lines < 2)
        throw std::invalid_argument("Expect min 2 lines rows, got " + std::to_string(n_lines));

    MatrixXf I = MatrixXf::Identity(2, 2);
    MatrixXf R = MatrixXf::Zero(2, 2);
    Vector2f q = Vector2f::Zero();

    for(int i = 0; i < n_lines; i++) {
        Vector3f line = lines.row(i);
        Vector2f line_dir = LineExt::get_line_dir_2d(line);
        Vector2f line_point = LineExt::get_line_point_2d(line);

        MatrixXf tmp = I - line_dir * line_dir.transpose();
        R += tmp;
        q += tmp * line_point;
    }

    // To solve Rp = q, where p is wanted point
    auto R_pseudo_inv = (R.transpose() * R).inverse() * R.transpose();
    auto point = R_pseudo_inv * q;

    return point;
}