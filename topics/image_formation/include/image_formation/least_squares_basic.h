#pragma once

#include <Eigen/Dense>

namespace image_formation
{
    using namespace Eigen;

    class LeastSquaresBasic
    {
    public:
        /**
         * Find nearest intersection point of n lines in 2d.
         * 
         * @note Even if lines have no common point algorithm 
         *      still can find it using least square method.
         * 
         * @param out_point inhomogeneus intersection point.
         * @param in_lines Martrix with n rows and m cols, where each row is a line with 
         *      format (a, b, c) for line equation ax + by + c = 0. Minimum 2 rows.
         * 
         * @return false if in_lines rows is less than 2 otherwise true.
         */
        static bool find_lines_intersection_point_2d(Matrix<float, 1, 2> &out_point, Matrix<float, -1, 3> &in_lines);

        /**
         * Fit a line to banch of points in 2d using least squares
         * 
         * @param out_line best fitted line to input points with format (a, b, c)
         *      for line equation ax + by + c = 0.
         * @param in_points Matrix with n rows and m cols, where each row is a point. Minimum 2 rows.
         * 
         * @return false if in_points rows is less than 2 otherwise true. 
         */
        static bool fit_line_2d(Matrix<float, 1, 2> &out_line, Matrix<float, -1, 3> &in_points);
    };
}