#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <qqmlcontext.h>
#include <QMessageBox>
#include "gameengine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject*     qmlWindow     = engine.rootObjects()[0];
    QQmlContext* windowContext = engine.rootContext();
    GameEngine*  gameEngine;
    try
    {
        gameEngine    = new GameEngine();
        windowContext->setContextProperty("gameEngine", gameEngine);
        gameEngine->connect(gameEngine, SIGNAL(draw(QVariant, QVariant, QVariant)), qmlWindow, SLOT(draw(QVariant, QVariant, QVariant)));
        gameEngine->connect(gameEngine, SIGNAL(clear()), qmlWindow, SLOT(clear()));
        gameEngine->connect(gameEngine, SIGNAL(displayWinMessage()), qmlWindow, SLOT(displayWinMessage()));
        gameEngine->initRender();
    }
    catch(std::exception& ex)
    {
        if (gameEngine)
        {
            delete gameEngine;
        }
    }

    return app.exec();
}
