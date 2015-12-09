#include "GraphTabEventClass.h"

GraphTabEventClass::GraphTabEventClass(QQmlContext &context)
    : qmlContext(context)
{

}

void GraphTabEventClass::graphChanged() {

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
