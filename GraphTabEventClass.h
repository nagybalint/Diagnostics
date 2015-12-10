#ifndef GRAPHTABEVENTCLASS_H
#define GRAPHTABEVENTCLASS_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <robotstatehistory.h>

class GraphTabEventClass : public QObject
{
    Q_OBJECT
public:
    GraphTabEventClass(QQmlContext &context, RobotStateHistory &history);

    ~GraphTabEventClass() = default;

    void connectQmlSignals(QObject *rootObject, QString str);

public slots:
    void graphChanged();

signals:
    void graphContextUpdated();


private:
    QQmlContext &qmlContext;
    RobotStateHistory &history;

    static QQuickItem* FindItemByName(QObject *rootObject, const QString& name);

    static QQuickItem* FindItemByName(QList<QObject*> nodes, const QString& name);
};

#endif // GRAPHTABEVENTCLASS_H
