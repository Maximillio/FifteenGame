import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import "Display.js" as Display

ApplicationWindow {
    id: appWindow
    visible: true
    width: Display.blockSize * 4
    height: Display.blockSize * 4
    maximumHeight: height
    maximumWidth:  width
    minimumHeight: height
    minimumWidth:  width

    title: qsTr("Fifteen")

    function draw(_x, _y, _number) {
        Display.draw(_x, _y, _number);
    }
    function clear() {
        Display.clear();
    }
    function displayWinMessage() {
        Display.createWinMessage();
    }

    Canvas {
        visible: true;
        id: canvas
        width: appWindow.width
        height: appWindow.height
        MouseArea {
            anchors.fill: parent
            onClicked: {
                gameEngine.move(mouse.x/Display.blockSize, mouse.y/Display.blockSize);
            }
        }
    }


}
