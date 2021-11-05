#pragma once

#include <image_formation/least_squares_basic.h>

#include <QObject>
#include <QtCharts/QLineSeries>

using namespace QtCharts;

class BackEnd : public QObject {
    Q_OBJECT
    Q_PROPERTY(QVariantList lines READ lines WRITE setLines NOTIFY linesChanged)

   public:
    explicit BackEnd(QObject *parent = nullptr);

    QVariantList lines();
    void setLines(const QVariantList &lines);

   signals:
    void linesChanged();

   private:
    QVariantList m_lines;
};