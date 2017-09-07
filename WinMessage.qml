import QtQuick 2.0

Rectangle
{
    anchors.centerIn: parent
    Text {
        text: "You've solved the puzzle!";
        color: "#EE7600"
        font.pointSize: parent.parent.height/20;
        anchors.centerIn: parent
    }
    width: childrenRect.width
    height: childrenRect.height
}
