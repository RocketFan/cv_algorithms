#pragma once

#include <Eigen/Dense>
#include <vector>

namespace algebra_ext {
using namespace Eigen;

class EigenExt {
   public:
    /**
     * Create 2d vector from Eigen DanseBase of any type.
     * 
     * @tparam T type of returned vector.
     * @tparam U type of Dense (used to allow all types).
     * 
     * @param dense the matrix or array which values are used to create vector.
     * 
     * @return 2D vector of type T.
    */
    template <typename T, typename U>
    static std::vector<T> eigen2stdvec_2d(const DenseBase<U> &dense);
};
}  // namespace algebra_ext

#include "../../src/eigen_ext.tpp"