import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQuick.Window 2.12
import QtCharts 2.3

import "canvas.js" as CanvasJS

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//    RowLayout {
//        id: buttons
//        anchors.horizontalCenter: parent.horizontalCenter
//        z: canvas.z + 1

//        Button {
//            text: 'Clear'

//            onClicked: CanvasJS.clearButton(canvas)
//        }

//        Button {
//            text: 'Exit'

//            onClicked: {
//                console.log("Exit")
//                Qt.quit();
//            }
//        }
//    }

    ChartView {
        title: "Line"
        x: 100
        y: 100
        width: 300
        height: 300
        id: chartView
        anchors.fill: parent
        antialiasing: true

        LineSeries {
            id: series
            name: "LineSeries"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
        }

//        Rectangle {
//            anchors.fill: parent
//            color: "red"
//        }

//        Rectangle {
//            x: parent.plotArea.x
//            y: parent.plotArea.y
//            width: parent.plotArea.width
//            height: parent.plotArea.height
//            color: "blue"
//        }

        MouseArea {
            id: area
            x: parent.plotArea.x
            y: parent.plotArea.y
            z: parent.z + 1
            width: parent.plotArea.width
            height: parent.plotArea.height
            anchors.fill: parent

            onPressed: {
                console.log("Click")
                console.log(series.count)
                console.log(parent.plotArea.x)

                const qtPoint = Qt.point(mouseX, mouseY)
                const point = parent.mapToValue(qtPoint, parent.plotArea)
                const len = series.count

                for (var i = 0; i < len; i++){
                    console.log(series.count)
                    if (series.at(i).x > point.x) {
                        series.insert(Math.max(i, 0), point.x, point.y)
                        console.log(i)
                        break
                    }
                }

                console.log(point)
            }
        }
    }
}
