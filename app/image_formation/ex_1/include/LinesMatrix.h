#pragma once

#include <Eigen/Dense>
#include <QObject>
#include <QPoint>
#include <vector>

namespace image_formation {
using namespace Eigen;

// Stores matrix of lines in 2D space
class LinesMatrix : public QObject {
    Q_OBJECT

   public:
    explicit LinesMatrix(QObject *parent = nullptr);

    MatrixXf matrix();

   public slots:
    // Add line from two points
    void append(const QPointF &p1, const QPointF &p2);

    int getSize();

   signals:
    void linesChanged();

   private:
    // Lines are in every row in format (a, b, c), where ax + by + c = 0
    std::vector<std::vector<float>> _lines;
};
}  // namespace image_formation