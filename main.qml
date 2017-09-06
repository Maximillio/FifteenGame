import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import "Display.js" as Display

ApplicationWindow {
    id: appWindow
    visible: true
    width: 600
    height: 600 + toolBar.height

    title: qsTr("Fifteen")

    function draw(_x, _y, _number) {
        Display.draw(_x, _y, _number);
    }
    signal moveTile(int _x, int _y, int _number);
    function invokeMoveTitle(_x, _y, _number) {
        moveTile(_x, _y, _number);
    }
    function clear() {
        Display.clear();
    }
    function displayWinMessage() {
        Display.createWinMessage();
    }

    toolBar:ToolBar {
                ToolButton {
                    text: "Shuffle"
                    onClicked: gameEngine.shuffle();
                    }
                }


    Canvas {
        visible: true;
        id: canvas
        width: appWindow.width
        height: appWindow.height - toolBar.height
        MouseArea {
            anchors.fill: parent
            onClicked: {
                gameEngine.move(mouse.x/(canvas.width/4), mouse.y/(canvas.height/4));
            }
        }
    }


}
