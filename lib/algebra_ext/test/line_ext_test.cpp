#include "algebra_ext/line_ext.h"

#include "gtest/gtest.h"

using namespace algebra_ext;
using namespace Eigen;

class LineExtTest : public ::testing::Test {
   protected:
    void SetUp() override {
        _line0 << 1.f, 1.f, 1.f;
        _line1 << 2.f, 3.f, 5.f;
        _line2 << -1.f, 2.f, 3.f;
        _line3 << -5.f, -10.f, 50.f;
        _line4 << 0, 0, 0;

        _X0.resize(5);
        _X0 << 1.f, 2.f, 3.f, 4.f, 5.f;
        _X1.resize(1);
        _X1 << 0;
        _X2.resize(3);
        _X2 << 1, 2, 3;
        _X3.resize(10);
        _X3 << 1, 2, 3, 50, 100, 4, 10, 20, -500, -10;
        _X4.resize(3);
        _X4 << -1, -2, -3;
    }

    Vector3f _line0, _line1, _line2, _line3, _line4;
    VectorXf _X0, _X1, _X2, _X3, _X4;
};

TEST_F(LineExtTest, get_line_points_2d_NumberOfPoints_SameAsXInputLength) {
    EXPECT_EQ(LineExt::get_line_points_2d(_line0, _X0).rows(), _X0.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line1, _X1).rows(), _X1.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X2).rows(), _X2.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X3).rows(), _X3.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X4).rows(), _X4.size());
}

TEST_F(LineExtTest, get_line_points_2d_PointsX_StayTheSameAsInputX) {
    EXPECT_EQ(LineExt::get_line_points_2d(_line0, _X0).col(0), _X0);
    EXPECT_EQ(LineExt::get_line_points_2d(_line1, _X1).col(0), _X1);
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X2).col(0), _X2);
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X3).col(0), _X3);
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X4).col(0), _X4);
}

TEST_F(LineExtTest, get_line_points_2d_ReturnedPoints_AsExpected) {
    MatrixX2f points0(_X0.size(), 2), points1(_X1.size(), 2), points2(_X2.size(), 2);
    points0 << _X0(0), -2,
        _X0(1), -3,
        _X0(2), -4,
        _X0(3), -5,
        _X0(4), -6;
    points1 << _X1(0), -5.f / 3;
    points2 << _X2(0), -1,
        _X2(1), -1.f / 2,
        _X2(2), 0;

    EXPECT_EQ(LineExt::get_line_points_2d(_line0, _X0), points0);
    EXPECT_EQ(LineExt::get_line_points_2d(_line1, _X1), points1);
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _X2), points2);
}

