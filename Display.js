
var blockSize = 100;
var component;
var sprite;
var context = [];

function draw(_x, _y, _number)
{
    component = Qt.createComponent("qrc:/Tile.qml");
    sprite = component.createObject(canvas, {"xPos": _x, "yPos": _y, "number": _number});
    appWindow.moveTile.connect(sprite.changePosition);
    context.push(sprite);
}

function clear()
{
    while (context.length)
    {
        context.pop().destroy();
    }
}
function createWinMessage()
{
    component = Qt.createComponent("qrc:/WinMessage.qml");
    sprite = component.createObject(appWindow, {"fontSize": blockSize / 5});
}
