#include "gtest/gtest.h"

#include "algebra_ext/line_ext.h"

using namespace Eigen;
using namespace algebra_ext;

class LineExtTest : public ::testing::Test {
   protected:
    void SetUp() override {
        _line0 << 1.f, 1.f, 1.f;
        _line1 << 2.f, 3.f, 5.f;
        _line2 << -1.f, 2.f, 3.f;

        _vec0.resize(5);
        _vec0 << 1.f, 2.f, 3.f, 4.f, 5.f;
        _vec1.resize(1);
        _vec1 << 1;
        _vec2.resize(4);
        _vec2 << 1, 2, 3, 4;
    }

    Vector3f _line0, _line1, _line2;

    VectorXf _vec0;
    VectorXf _vec1;
    VectorXf _vec2;
};

TEST_F(LineExtTest, get_line_points_2d_NumberOfPoints_SameAsXInputLength) {
    EXPECT_EQ(LineExt::get_line_points_2d(_line0, _vec0).rows(), _vec0.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line1, _vec1).rows(), _vec1.size());
    EXPECT_EQ(LineExt::get_line_points_2d(_line2, _vec2).rows(), _vec2.size());
}