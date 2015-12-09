#include "ConsoleTabEventClass.h"
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>


ConsoleTabEventClass::ConsoleTabEventClass(QQmlContext &context)
    : qmlContext(context)
{

}

void ConsoleTabEventClass::setTextInput(QList<QObject*> object) {

    // TODO history is not working
    textInput = object.at(0)->findChild<QQuickItem*>("textInput");
    if (textInput)
        qDebug() << "Finding text Input secceded!!!";
}


void ConsoleTabEventClass::consoleTextArrived(QString text) {

    // Debug code
    qDebug() << text;
    addToList(text);
    listChanged();

}

void ConsoleTabEventClass::addToList(QString string) {

    this->dataList.append(string);

}

void ConsoleTabEventClass::listChanged() {

    qmlContext.setContextProperty(QStringLiteral("monitorModel"), QVariant::fromValue(dataList));

}
