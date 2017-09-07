
var component;
var sprite;
var context = [];
var winMessage;

function draw(_x, _y, _number)
{
    component = Qt.createComponent("qrc:/Tile.qml");
    sprite    = component.createObject(canvas, {"xPos": _x, "yPos": _y, "number": _number});
    appWindow.moveTile.connect(sprite.changePosition);
    context.push(sprite);
}

function createWinMessage()
{
    component  = Qt.createComponent("qrc:/WinMessage.qml");
    sprite     = component.createObject(appWindow, {"fontSize": appWindow / 5});
    winMessage = sprite;
}
function clearMessage()
{
    if (winMessage)
    {
        winMessage.destroy();
        winMessage = 0;
    }
}
