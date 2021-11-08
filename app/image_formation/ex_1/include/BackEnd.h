#pragma once

#include <QObject>
#include <QtCharts/QLineSeries>

#include "LinesMatrix.h"

using namespace QtCharts;

namespace image_formation {

class BackEnd : public QObject {
    Q_OBJECT
    Q_PROPERTY(LinesMatrix* lines READ lines WRITE setLines NOTIFY linesChanged)

   public:
    explicit BackEnd(QObject* parent = nullptr);

    LinesMatrix* lines();
    void setLines(LinesMatrix* lines);

   signals:
    void linesChanged();

   public slots:
    void print();

   private:
    LinesMatrix* m_lines;
};
}  // namespace image_formation