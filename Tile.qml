import QtQuick 2.0
import QtQuick.Controls 1.2

Image {
    property int numberValue: 0
    source: (numberValue) ? "Tile.png" : ""
    fillMode: Image.Stretch
    width: parent.width/4
    height: parent.height/4
    property int duration: 100
    Text {
        id: textData
        text: (numberValue) ? parent.numberValue : ""
        font.pointSize: parent.height/5;
        anchors.centerIn: parent
    }
    transitions: Transition {
            NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }
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

