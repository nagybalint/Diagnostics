#ifndef CONSOLETABEVENTCLASS_H
#define CONSOLETABEVENTCLASS_H

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QQmlApplicationEngine>

class ConsoleTabEventClass : public QObject
{
    Q_OBJECT

public:
    ConsoleTabEventClass(QQmlContext &context);

    ~ConsoleTabEventClass() = default;

    void addToListView(QString string);

signals:



public slots:
    void consoleTextArrived(QString text);
    void consoleKeyPressed(int key);
    void listChanged();

private:
    QQmlContext &qmlContext;
    QString text;
    QStringList dataList;
    QStringList historyList;
    int historyCurrent;
};

#endif // CONSOLETABEVENTCLASS_H
