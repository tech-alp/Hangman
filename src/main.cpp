#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controllers/mastercontroller.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    Mastercontroller mastercontroller;
    //qmlRegisterType<Mastercontroller>("techalp.company",1,0,"Mastercontroller");
    qmlRegisterType<Navigationcontroller> ("techalp.company",1,0,"NavigationController");
    qmlRegisterType<Gamedatamanagement>("techalp.company",1,0,"Gamedatamanagement");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/view/MasterView.qml"));
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("Mastercontroller",&mastercontroller);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
