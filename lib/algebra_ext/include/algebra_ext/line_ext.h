#pragma once

#include <Eigen/Dense>

namespace algebra_ext {
using namespace Eigen;

class LineExt {
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

    /**
    * Get one point which lie on the line in 2D.
    * 
    * @param line the equation of the line in form (a, b, c) where ax + by + c = 0.
    * 
    * @return Point on the line.
   */
    static Vector2f get_line_point_2d(const Vector3f &line);

    /**
     * Get direction vector of the line in 2D.
     * 
     * @param line the equation of the line in form (a, b, c) where ax + by + c = 0.
     * 
     * @return Direction vector of the line.
    */
    static Vector2f get_line_dir_2d(const Vector3f &line);

   /**
    * Checks if points is lying on their lines. 
    * 
    * Lines and points should have equel length.
    * 
    * @param line the equation of the line in form (a, b, c) where ax + by + c = 0.
    * @param point the point which should lie on the line in the form of (x, y).
    * 
    * @return true if points lying on their lines and false otherwise.
   */
    static bool check_point(const Vector3f &line, const Vector2f &point);
};
}  // namespace algebra_ext