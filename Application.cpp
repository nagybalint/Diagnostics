#include "Application.h"
#include <QDebug>

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv), engine(), console(*engine.rootContext())
{

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    console.setTextInput(engine.rootObjects());

    auto rootObjects = engine.rootObjects();
    if (rootObjects.size() == 0)
    {
        qDebug() << "HIBA: Nem sikerült létrehozni a QML környezetet.";
        return;
    }

    QObject *rootObject = rootObjects[0];

    QObject::connect(rootObject, SIGNAL(sendTextInput(QString)), &console, SLOT(consoleTextArrived(QString)));
}

