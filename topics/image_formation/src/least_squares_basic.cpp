#include "image_formation/least_squares_basic.h"

using namespace image_formation;

bool LeastSquaresBasic::find_lines_intersection_point_2d(Matrix<float, 1, 2> &out_point, Matrix<float, -1, 3> &in_lines)
{
    int n_lines = in_lines.rows();

    if(n_lines < 2)
        return false;

    Matrix<float, 3, 1> cross_lines = in_lines.row(0).transpose();

    for(int i = 1; i < n_lines - 1; i++)
        cross_lines = cross_lines.cross(in_lines.row(i));

    out_point << cross_lines(0, 0), cross_lines(0, 1);
    out_point /= cross_lines(0, 2);
    
    return true;
}