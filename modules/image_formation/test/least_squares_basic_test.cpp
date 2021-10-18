#include "image_formation/least_squares_basic.h"

#include <gtest/gtest.h>

using namespace Eigen;
using namespace image_formation;

TEST(LeastSquaresBasicTest, find_lines_intersection_point_2d_InvalidArguments_ThrowException)
{
    Matrix<float, 1, 3> lines;
    lines << 1.f, 2.f, 3.f;

    EXPECT_THROW(LeastSquaresBasic::find_lines_intersection_point_2d(lines), std::invalid_argument);
}

TEST(LeastSquaresBasicTest, find_lines_intersection_point_2d_ValidArguments_NotThrowException)
{
    Matrix<float, 2, 3> lines;
    lines << 1.f, 10.f, 20.f,
        5.f, 2.f, 3.f;

    EXPECT_NO_THROW(LeastSquaresBasic::find_lines_intersection_point_2d(lines));
}