import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2
import "Display.js" as Display



Window {
    id: appWindow
    width: 600
    height: 650
    visible: true
    ToolBar {
        id: toolBar
        Row{
            anchors.fill: parent
            ToolButton {
                text: qsTr("Shuffle")
                onClicked: gameModel.shuffle()
            }
        }
    }
    Connections {
        target: gameModel
        onVictory: messageDialog.open();
    }

    GridView {
        y: toolBar.height
        width: appWindow.width
        height: appWindow.height - toolBar.height
        model: gameModel
        cellWidth: width / 4
        cellHeight: height / 4
        delegate: Tile{width: parent.width/4; height: parent.height/4; numberValue: number;}
        MouseArea {
            anchors.fill: parent
            onClicked: gameModel.moveTile(parent.indexAt(mouse.x, mouse.y));
        }
        displaced: Transition {
                NumberAnimation { properties: "x,y"; duration: 200; easing.type: Easing.InOutCubic }
            }
        move: Transition {
                NumberAnimation { properties: "x,y"; duration: 200; easing.type: Easing.InOutCubic }
            }
        populate: Transition {
                NumberAnimation { properties: "x,y"; duration: 500; easing.type: Easing.InOutCubic }
        }

    }
    MessageDialog {
        id: messageDialog
        standardButtons: StandardButton.Close | StandardButton.Ok
        visible: false
            title: "You have solved the puzzle!"
            text: "Do you want to restart?"
            onAccepted: gameModel.shuffle()
            onRejected: appWindow.close()
    }
}
