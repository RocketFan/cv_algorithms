#include "BackEnd.h"

#include <QVariant>
#include <iostream>

using namespace image_formation;

BackEnd::BackEnd(QObject *parent) : QObject(parent), m_lines(new LinesMatrix(this)) {
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

void BackEnd::print() {
    std::cout << "BacEnd!!" << std::endl;
}