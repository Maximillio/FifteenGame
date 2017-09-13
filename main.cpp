#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <qqmlcontext.h>
#include "gamemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine *engine = new QQmlApplicationEngine();
    QQmlContext *context          = engine->rootContext();
    GameModel*  gameModel         = new GameModel();

    context->setContextProperty("gameModel", gameModel);
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
