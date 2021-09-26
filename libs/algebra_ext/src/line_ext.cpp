#include "algebra_ext/line_ext.h"

#include <iostream>

using namespace Eigen;
using namespace algebra_ext;

MatrixX2f LineExt::get_line_points_2d(const Vector3f &line,
                                      const VectorXf &X) {
    MatrixX2f points(X.size(), 2);
    std::cout << "Line: " << line << std::endl;

    for (int i = 0; i < X.size(); i++) {
        points(i, 0) = X(i);
        points(i, 1) = (line(0) * X(i) + line(2)) / -line(1);
    }

    return points;
}