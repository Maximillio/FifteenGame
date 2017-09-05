import QtQuick 2.0
import QtQuick.Controls 1.2

Image {
    id: image
    source: "Tile.png"
    property string text: "0"
    Text {
        id: textData
        text: image.text
        anchors.centerIn: parent
    }
}

