import QtQuick 2.0
import QtQuick.Controls 1.2

Image {
    source: "Tile.png"
    fillMode: Image.Stretch
    width: parent.width/4
    height: parent.height/4
    property int number: 0
    property int xPos: 0
    property int yPos: 0
    property int duration: 100
    x: xPos * width
    y: yPos * height
    Text {
        id: textData
        text: parent.number
        font.pointSize: parent.height/5;
        anchors.centerIn: parent
    }
    function changePosition(_x, _y, _number) {
        if (number === _number)
        {
            xPos = _x;
            yPos = _y;
        }
    }
    Behavior on y {
                NumberAnimation {
                    duration: duration
                    easing.type: Easing.InOutExpo
                }
            }
    Behavior on x {
                NumberAnimation {
                    duration: duration
                    easing.type: Easing.InOutExpo
                }
            }
    Behavior on width {
                NumberAnimation {
                    duration: duration
                    easing.type: Easing.InOutCubic
                }
            }
    Behavior on height {
                NumberAnimation {
                    duration: duration
                    easing.type: Easing.InOutCubic
                }
            }
}

