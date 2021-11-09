#include "BackEnd.h"

#include <QVariant>

#include "image_formation/least_squares_basic.h"

using namespace image_formation;

BackEnd::BackEnd(QObject* parent) : QObject(parent), m_lines(new LinesMatrix(this)) {
    QObject::connect(this->m_lines, &LinesMatrix::linesChanged, this, &BackEnd::onLinesChanged);
    QObject::connect(this, &BackEnd::pointChanged, this, &BackEnd::onPointChanged);
}

LinesMatrix* BackEnd::lines() {
    return m_lines;
}

void BackEnd::setLines(LinesMatrix* lines) {
    if (lines == m_lines)
        return;

    delete m_lines;

    m_lines = lines;
    emit linesChanged();
}

QPointF& BackEnd::point() {
    return m_point;
}

void BackEnd::setPoint(QPointF& point) {
    if (point == m_point)
        return;

    m_point = point;
    emit pointChanged();
}

void BackEnd::onLinesChanged() {
    if (m_lines->getSize() < 2)
        return;

    auto point = LeastSquaresBasic::find_lines_intersection_point_2d(m_lines->matrix());
    auto qt_point = QPointF(point.x(), point.y());

    setPoint(qt_point);
}

void BackEnd::onPointChanged() {}