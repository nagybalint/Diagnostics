#include "ConsoleTabEventClass.h"
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>


ConsoleTabEventClass::ConsoleTabEventClass(QQmlContext &context)
    : qmlContext(context)
{
    historyCurrent = 0;
}


void ConsoleTabEventClass::consoleTextArrived(QString text) {

    // Debug code
    qDebug() << text;
    addToListView(text);
    historyList.append(text);
    listChanged();

    // Set history position
    historyCurrent = historyList.size();

}

void ConsoleTabEventClass::consoleKeyPressed(int key) {

    QString string;

    if(historyCurrent < 0 ) return;

    switch (key) {

    case 1:
        string = historyList.at(historyCurrent - 1);
        if (historyCurrent > 1) historyCurrent--;
        break;

    case 2:
        if (historyCurrent == historyList.size()) {
            string = "";
        }
        else string = historyList.at(historyCurrent);
        if (historyCurrent < historyList.size()) historyCurrent++;
        break;

    default:
        break;
    }

    qmlContext.setContextProperty(QStringLiteral("setHistoryText"), QVariant::fromValue(string));
}

void ConsoleTabEventClass::addToListView(QString string) {

    this->dataList.append(string);

}

void ConsoleTabEventClass::listChanged() {

    qmlContext.setContextProperty(QStringLiteral("monitorModel"), QVariant::fromValue(dataList));

}
