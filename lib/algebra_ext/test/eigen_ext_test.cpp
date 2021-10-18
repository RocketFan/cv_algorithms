#include "algebra_ext/eigen_ext.h"

#include <gtest/gtest.h>
#include <vector>
#include <iostream>

using namespace algebra_ext;
using namespace Eigen;

class EigenExtTest : public ::testing::Test {
   protected:
    void SetUp() override {
        _std_vector3x3f = std::vector<float>({1.2f, 2.f, 3.f,
                                        -2.4f, -5.f, 10.f,
                                        -5.f, 7.f, -3.2f});
        _std_vector3x3d = std::vector<double>(_std_vector3x3f.begin(), _std_vector3x3f.end());
        _std_vector3x3i = std::vector<int>(_std_vector3x3f.begin(), _std_vector3x3f.end());

        _std_vector3f = std::vector<float>({2.4f, 5.f, -100.45f});
        _std_vector3d = std::vector<double>(_std_vector3f.begin(), _std_vector3f.end());
        _std_vector3i = std::vector<int>(_std_vector3f.begin(), _std_vector3f.end());

        _matrixf = Matrix3f(_std_vector3x3f.data()).transpose();
        _matrixd = Matrix3d(_std_vector3x3d.data()).transpose();
        _matrixi = Matrix3i(_std_vector3x3i.data()).transpose();

        _vectorf = Vector3f(_std_vector3f.data()).transpose();
        _vectord = Vector3d(_std_vector3d.data()).transpose();
        _vectori = Vector3i(_std_vector3i.data()).transpose();

        _arrayf = Array3f(_std_vector3f.data()).transpose();
        _arrayd = Array3d(_std_vector3d.data()).transpose();
        _arrayi = Array3i(_std_vector3i.data()).transpose();
    }

    std::vector<float> _std_vector3x3f, _std_vector3f;
    std::vector<double> _std_vector3x3d, _std_vector3d;
    std::vector<int> _std_vector3x3i, _std_vector3i;

    Matrix3f _matrixf;
    Matrix3d _matrixd;
    Matrix3i _matrixi;

    Vector3f _vectorf;
    Vector3d _vectord;
    Vector3i _vectori;

    Array3f _arrayf;
    Array3d _arrayd;
    Array3i _arrayi;
};

TEST_F(EigenExtTest, eigen2stdvec_2d_ReturnedWithSameType_AsInput) {
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_matrixf), _std_vector3x3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<double>(_matrixd), _std_vector3x3d);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<int>(_matrixi), _std_vector3x3i);

    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_vectorf), _std_vector3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<double>(_vectord), _std_vector3d);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<int>(_vectori), _std_vector3i);

    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_arrayf), _std_vector3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<double>(_arrayd), _std_vector3d);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<int>(_arrayi), _std_vector3i);
}

TEST_F(EigenExtTest, eigen2stdvec_2d_ReturnedWithDifferenType_AsCastInput) {
    std::vector<float> cast_vector3i_f(_std_vector3i.begin(), _std_vector3i.end());
    std::vector<double> cast_vector3f_d(_std_vector3f.begin(), _std_vector3f.end());
    std::vector<int> cast_vector3d_i(_std_vector3d.begin(), _std_vector3d.end());

    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_vectori), cast_vector3i_f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<double>(_vectorf), cast_vector3f_d);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<int>(_vectord), cast_vector3d_i);
}

TEST_F(EigenExtTest, eigen2stdvec_2d_ParametterAsSomeDenseWrapper_AsCastInput) {
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_matrixf.array()), _std_vector3x3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_matrixf.matrix()), _std_vector3x3f);

    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_vectorf.array()), _std_vector3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_vectorf.matrix()), _std_vector3f);

    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_arrayf.array()), _std_vector3f);
    EXPECT_EQ(EigenExt::eigen2stdvec_2d<float>(_arrayf.matrix()), _std_vector3f);
}