#pragma once

#include <Eigen/Dense>

namespace image_formation {
using namespace Eigen;

class LeastSquaresBasic {
   public:
    /**
      * Find nearest intersection point of n lines in 2d.
      * 
      * @note Even if lines have no common point algorithm 
      *      still can find it using least square method.
      * 
      * @param[out] point the inhomogeneus intersection point.
      * @param[in] lines the martrix with n rows and m cols, where each row is a line with 
      *      format (a, b, c) for line equation ax + by + c = 0. Minimum 2 rows.
      * 
      * @return False if in_lines rows is less than 2 otherwise true.
      */
    static bool find_lines_intersection_point_2d(Matrix<float, 1, 2> &point, const Matrix<float, -1, 3> &lines);

    /**
      * Fit a line to banch of points in 2d using least squares
      * 
      * @param[out] line the best fitted line to input points with format (a, b, c)
      *      for line equation ax + by + c = 0.
      * @param[in] points the matrix with n rows and m cols, where each row is a point. 
      *      Minimum 2 rows.
      * 
      * @return false if in_points rows is less than 2 otherwise true. 
      */
    static bool fit_line_2d(Matrix<float, 1, 2> &line, const Matrix<float, -1, 3> &points);
};
}  // namespace image_formation