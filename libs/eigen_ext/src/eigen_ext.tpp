
using namespace eigen_ext;

template <typename T, typename U>
std::vector<T> EigenExt::eigen2stdvec_2d(const DenseBase<U> &dense)
{
    std::vector<T> vec;
    vec.reserve(dense.rows() * dense.cols());

    for (int i = 0; i < dense.rows(); i++)
        for (int j = 0; j < dense.cols(); j++)
            vec.push_back((T)dense(i, j));

    return vec;
}