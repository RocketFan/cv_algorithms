#include "BackEnd.h"

#include <QVariant>
#include <iostream>

BackEnd::BackEnd(QObject *parent) : QObject(parent) {}

QVariantList BackEnd::lines() {
    return m_lines;
}

void BackEnd::setLines(const QVariantList &lines) {
    if (lines == m_lines)
        return;

    std::cout << lines.count() << std::endl;
    // QVariant::fromValue(lines);

    m_lines = lines;
    emit linesChanged();
}