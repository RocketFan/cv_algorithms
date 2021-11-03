import QtQuick 2.12
import QtQuick.Shapes 1.12

Item {
    smooth: true
    antialiasing: true

    property point start: Qt.point(0, 0)
    property point end: Qt.point(0, 0)
    property point center: Qt.point(0, 0)

    Shape {
        id: shape

        ShapePath {
            id: line
            strokeWidth: 4
            strokeColor: "red"
            fillColor: "transparent"

            startX: start.x; startY: start.y
            PathLine { x: end.x; y: end.y }
        }
    }

    Rectangle {
        width: 15
        height: width
        x: center.x - width / 2
        y: center.y - width / 2

        color: "red"
        radius: width * 0.5
    }
}
