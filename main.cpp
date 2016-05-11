#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QAbstractListModel>
#include <QQmlContext>

#include "model.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AnimalModel model;
    model.addAnimal(Animal("Wolf", "Medium"));
    model.addAnimal(Animal("Polar bear", "Large"));
    model.addAnimal(Animal("Quoll", "Small"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("myModel", &model);

    return app.exec();
}





