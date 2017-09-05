#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include "gameengine.h"
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject*     qmlWindow     = engine.rootObjects()[0];
    QQmlContext* windowContext = engine.rootContext();
    GameEngine*  gameEngine    = new GameEngine();

    windowContext->setContextProperty("gameEngine", gameEngine);
    gameEngine->connect(gameEngine, SIGNAL(draw(QVariant, QVariant, QVariant)), qmlWindow, SLOT(draw(QVariant, QVariant, QVariant)));
    gameEngine->connect(gameEngine, SIGNAL(clear()), qmlWindow, SLOT(clear()));
    gameEngine->initRender();

    return app.exec();
}
