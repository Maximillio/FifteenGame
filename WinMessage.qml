import QtQuick 2.0

Rectangle
{
    anchors.centerIn: parent
    property int fontSize: 25;
    Text {
        text: "You've solved the puzzle!";
        color: "#EE7600"
        font.pointSize: fontSize
        anchors.centerIn: parent
    }
    width: childrenRect.width
    height: childrenRect.height
}
