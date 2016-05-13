#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QQmlContext>

#include "model.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Game game;

    QQmlApplicationEngine engine;
    QQmlContext *ctxt = engine.rootContext();
//    ctxt->setContextProperty("myModel", &model);
    ctxt->setContextProperty("game", &game);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}





