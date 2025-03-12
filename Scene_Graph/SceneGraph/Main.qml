import QtQuick
import SceneGraph
import QtQml

Window {
    id: root
    visible: true
    width: 640
    height: 480

    property color triangleColor: "red"
    title: "QSceneGraph Demo"

    Rectangle {
        color: "lightblue"
        anchors.fill: parent

        Triangle {
            id: triangle
            anchors.centerIn: parent
            width: parent.width/2;
            height: parent.height/2;
            color: root.triangleColor
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.triangleColor = Qt.rgba(Math.random(),Math.random(),Math.random(),1);
    }
}
