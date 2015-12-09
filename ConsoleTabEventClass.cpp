#include "ConsoleTabEventClass.h"
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "Comm/commserial.h"
#include "Comm/robotterminalmessage.h"

ConsoleTabEventClass::ConsoleTabEventClass(QQmlContext &context)
    : qmlContext(context)
{
    historyCurrent = 0;
    QString placeHolder("");
    this->dataList.append(placeHolder);
}


void ConsoleTabEventClass::consoleTextArrived(QString text) {

    // Debug code
    //qDebug() << text;
    emit this->commandAvailable(text);

    // Add new text to historyList
    historyList.append(text);

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

void ConsoleTabEventClass::addToListView(QString& string) {

    if(string.at(string.length() - 1) != '\r') {
        this->dataList.last().append(string);
    } else {
        QString placeHolder("");
        this->dataList.append(placeHolder);
    }
    listChanged();

}

void ConsoleTabEventClass::listChanged() {

    qmlContext.setContextProperty(QStringLiteral("monitorModel"), QVariant::fromValue(dataList));

}
