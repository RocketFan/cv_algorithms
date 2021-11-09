#include "LinesMatrix.h"

#include <algebra_ext/eigen_ext.h>

using namespace image_formation;
using namespace algebra_ext;
using namespace Eigen;

LinesMatrix::LinesMatrix(QObject *parent) : QObject(parent) {}

void LinesMatrix::append(const QPointF &p1, const QPointF &p2) {
    Vector3f p1_h = Vector3f(p1.x(), p1.y(), 1);
    Vector3f p2_h = Vector3f(p2.x(), p2.y(), 1);
    Vector3f line = p1_h.cross(p2_h);

    auto lineVec = EigenExt::eigen2stdvec_2d<float>(line);
    _lines.push_back(lineVec);

    emit linesChanged();
}

int LinesMatrix::getSize() {
    return _lines.size();
}

MatrixXf LinesMatrix::matrix() {
    const int linesSize = _lines.size();
    auto linesMat = MatrixX3f(linesSize, 3);

    for (int i = 0; i < linesSize; i++)
        linesMat.row(i) = Map<MatrixX3f>(_lines[i].data(), 1, 3);

    return linesMat;
}