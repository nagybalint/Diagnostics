#ifndef MAINWINDOWEVENTCLASS_H
#define MAINWINDOWEVENTCLASS_H

#include <QObject>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "robotstatehistory.h"

class MainWindowEventClass : public QObject
{
    Q_OBJECT

public:
    MainWindowEventClass(QQmlContext &context, RobotStateHistory &hState);

    ~MainWindowEventClass() = default;

    void connectQmlSignals(QObject *rootObject, QString str);

public slots:
    void graphChanged();
    void stopCommand();
    void startCommand();

signals:
    void graphContextUpdated();

private:
    QQmlContext &qmlContext;
    RobotStateHistory &history;

    static QQuickItem* FindItemByName(QObject *rootObject, const QString& name);

    static QQuickItem* FindItemByName(QList<QObject*> nodes, const QString& name);
};

#endif // MAINWINDOWEVENTCLASS_H
