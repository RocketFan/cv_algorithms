import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtQuick.Shapes 1.12
import QtCharts 2.3

import io.qt.backend 1.0

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    BackEnd {
        id: backend
    }

    ChartView {
        x: 100
        y: 100
        width: 300
        height: 300
        id: chartView
        anchors.fill: parent
        antialiasing: true
        legend.visible: false

        LineSeries {
            id: lineSeries
            name: "LineSeries"
        }

        MouseArea {
            id: area
            x: parent.plotArea.x
            y: parent.plotArea.y
            z: parent.z + 1
            width: parent.plotArea.width
            height: parent.plotArea.height
            clip: true

            function renderLine() {
                const mousePoint = Qt.vector2d(mouseX, mouseY)
                const center = Qt.vector2d(lineDrawing.center.x, lineDrawing.center.y)
                const dir = center.minus(mousePoint).normalized()

                const start = center.plus(dir.times(1000))
                const end = center.plus(dir.times(-1000))

                lineDrawing.start = Qt.point(start.x, start.y)
                lineDrawing.end = Qt.point(end.x, end.y)
            }

            function drawLineOnChart() {
                const start = lineDrawing.start
                const end = lineDrawing.end

                if (start == end)
                    return

                const qtPoint1 = Qt.point(start.x + x, start.y + y)
                const qtPoint2 = Qt.point(end.x + x, end.y + y)
                const point1 = chartView.mapToValue(qtPoint1, parent.plotArea)
                const point2 = chartView.mapToValue(qtPoint2, parent.plotArea)

                const axisX = chartView.axisX(lineSeries)
                const axisY = chartView.axisY(lineSeries)
                var line = chartView.createSeries(ChartView.SeriesTypeLine, "Line", axisX, axisY)
                line.append(point1.x, point1.y)
                line.append(point2.x, point2.y)
                console.log(backend.lines.length)
                backend.lines.append(line)
            }

            onPressed: {
                lineDrawing.center = Qt.point(mouseX, mouseY)
                renderLine()
                lineDrawing.visible = true
            }

            onPositionChanged: {
                renderLine()
            }

            onReleased: {
                drawLineOnChart()
                lineDrawing.visible = false
            }
                   
            ShapeLine {
                id: lineDrawing
                visible: false
                anchors.fill: parent
                start: Qt.point(50, 50)
            }
        }
    }
}
