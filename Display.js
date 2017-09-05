
var blockSize = 100;
var component;
var sprite;
var context = [];

function draw(_x, _y, _number)
{
    component = Qt.createComponent("qrc:/Tile.qml");
    sprite = component.createObject(appWindow, {"width": blockSize, "height": blockSize, "x": _x * blockSize, "y": _y * blockSize, "text": _number});
    context.push(sprite);
}
function clear()
{
    while (context.length)
    {
        context.pop().destroy();
    }
}
