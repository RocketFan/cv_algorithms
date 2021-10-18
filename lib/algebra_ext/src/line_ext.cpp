#include "algebra_ext/line_ext.h"

#include <iostream>

using namespace Eigen;
using namespace algebra_ext;

MatrixX2f LineExt::get_line_points_2d(const Vector3f &line,
                                      const VectorXf &X) {
    MatrixX2f points(X.size(), 2);

    for (int i = 0; i < X.size(); i++) {
        points(i, 0) = X(i);
        points(i, 1) = (line(0) * X(i) + line(2)) / -line(1);
    }

    return points;
}

Vector2f LineExt::get_line_point_2d(const Vector3f &line) {
    // Vector of (a, b) from line equation in form ax + by + c = 0
    Vector2f ab_vec = line.block(0, 0, 2, 1);
    Vector2f point = ab_vec.normalized() * (-line[2] / ab_vec.norm());

    return point;
}

Vector2f LineExt::get_line_dir_2d(const Vector3f &line) {
    Vector2f ab_vec = line.block(0, 0, 2, 1);
    Vector2f line_dir = ab_vec.reverse().normalized();
    line_dir[1] *= -1;

    return line_dir;
}

bool LineExt::check_point(const Vector3f &line,
                          const Vector2f &point) {
    float pred_y = -(line[0] * point[0] + line[2]) / line[1];

    return std::abs(pred_y - point[1]) <= 0.0001f;
}