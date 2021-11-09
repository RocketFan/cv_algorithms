#pragma once

#include <QObject>
#include <QtCharts/QLineSeries>
#include <QPoint>

#include "LinesMatrix.h"

using namespace QtCharts;

namespace image_formation {

class BackEnd : public QObject {
    Q_OBJECT
    Q_PROPERTY(LinesMatrix* lines READ lines WRITE setLines NOTIFY linesChanged)
    Q_PROPERTY(QPointF point READ point WRITE setPoint NOTIFY pointChanged)

   public:
    explicit BackEnd(QObject* parent = nullptr);

    LinesMatrix* lines();
    void setLines(LinesMatrix* lines);

    QPointF& point();
    void setPoint(QPointF &point);

   signals:
    void linesChanged();
    void pointChanged();

   public slots:
    void onLinesChanged();
    void onPointChanged();

   private:
    LinesMatrix* m_lines;
    QPointF m_point;
};
}  // namespace image_formation