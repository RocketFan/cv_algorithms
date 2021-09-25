#pragma once

#include <Eigen/Dense>

namespace algebra_ext
{
    using namespace Eigen;

    class LineExt
    {
    public:
        /**
         * Get points which lie on the line at x positions in 2D.
         * 
         * @param line the equation of the line in form (a, b, c) where ax + by + c = 0.
         * @param X the set of x positions.
         * 
         * @return Matrix where each row is point in form (x, y).
        */
        static MatrixX2f get_line_points_2d(const Vector3f &line,
                                            const VectorXf &X);
    };
}