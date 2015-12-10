#include "GraphTabEventClass.h"
#include <QQmlContext>

GraphTabEventClass::GraphTabEventClass(QQmlContext &context, RobotStateHistory &history)
    : qmlContext(context), history(history)
{
    QObject::connect(&this->history, SIGNAL(historyChanged()),this, SLOT(graphChanged()));
    qmlContext.setContextProperty(QStringLiteral("graphSpeedData"), QVariant::fromValue(this->history.graphCarSpeed));
    qmlContext.setContextProperty(QStringLiteral("graphPositionData"), QVariant::fromValue(this->history.graphFrontLinePos));
    qmlContext.setContextProperty(QStringLiteral("graphSteeringAngleData"), QVariant::fromValue(this->history.graphSteeringAngle));
    qmlContext.setContextProperty(QStringLiteral("graphFrontSensorPos"), QVariant::fromValue(10));
    qmlContext.setContextProperty(QStringLiteral("graphOrientationAngle"), QVariant::fromValue(-0.05));
}

void GraphTabEventClass::graphChanged() {

    qmlContext.setContextProperty(QStringLiteral("graphSpeedData"), QVariant::fromValue(history.graphCarSpeed));
    qmlContext.setContextProperty(QStringLiteral("graphPositionData"), QVariant::fromValue(history.graphFrontLinePos));
    qmlContext.setContextProperty(QStringLiteral("graphSteeringAngleData"), QVariant::fromValue(history.graphSteeringAngle));
    qmlContext.setContextProperty(QStringLiteral("graphFrontSensorPos"), QVariant::fromValue(history.graphFrontLinePos.last()));
    qmlContext.setContextProperty(QStringLiteral("graphOrientationAngle"), QVariant::fromValue(0.05));


    emit graphContextUpdated();
}

QQuickItem* GraphTabEventClass::FindItemByName(QList<QObject *> nodes, const QString &name) {

    for(int i = 0; i < nodes.size(); i++)
    {
        if (nodes.at(i) && nodes.at(i)->objectName() == name)
        {
            return dynamic_cast<QQuickItem*>(nodes.at(i));
        }
        else if (nodes.at(i) && nodes.at(i)->children().size() > 0)
        {
            QQuickItem* item = FindItemByName(nodes.at(i)->children(), name);
            if (item)
                return item;
        }
    }
    return nullptr;
}

QQuickItem* GraphTabEventClass::FindItemByName(QObject *rootObject, const QString &name) {
    return FindItemByName(rootObject->children(), name);
}

void GraphTabEventClass::connectQmlSignals(QObject *rootObject, QString str) {

    QQuickItem *historyGraph = FindItemByName(rootObject,str);
    if (historyGraph)
    {
        QObject::connect(this, SIGNAL(graphContextUpdated()), historyGraph, SLOT(requestPaint()));
    }
    else
    {
        qDebug() << "Error!!! Can't find QML object.";
    }
}

