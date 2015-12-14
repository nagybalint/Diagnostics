#include "MainWindowEventClass.h"
#include <QQmlContext>
#include "RobotState/robotstate.h"
#include <QDebug>
#include <Comm/roboterrormessage.h>
#include "Config/config.h"
#include "Comm/robotstartmessage.h"

MainWindowEventClass::MainWindowEventClass(QQmlContext &context, RobotStateHistory &hState) :
    qmlContext(context), history(hState)
{
    QObject::connect(&this->history, SIGNAL(historyChanged()),this, SLOT(graphChanged()));
    qmlContext.setContextProperty(QStringLiteral("graphFrontSensorPos"), QVariant::fromValue(0));
    qmlContext.setContextProperty(QStringLiteral("graphOrientationAngle"), QVariant::fromValue(0));
    qmlContext.setContextProperty(QStringLiteral("graphBatContrV"), QVariant::fromValue(0));
    qmlContext.setContextProperty(QStringLiteral("graphBatMotorV"), QVariant::fromValue(0));
    qmlContext.setContextProperty(QStringLiteral("batterryTextColor"), QVariant::fromValue(QString("")));
    qmlContext.setContextProperty(QStringLiteral("selfTestMessage"), QVariant::fromValue((QString(""))));
}

void MainWindowEventClass::graphChanged() {

    qmlContext.setContextProperty(QStringLiteral("graphFrontSensorPos"), QVariant::fromValue((qreal)history.currentState->lineSensor.getFrontLinePos()));
    qmlContext.setContextProperty(QStringLiteral("graphOrientationAngle"), QVariant::fromValue((qreal)history.currentState->lineSensor.getLineOrientation()));
    qmlContext.setContextProperty(QStringLiteral("graphBatContrV"), QVariant::fromValue((qreal)history.currentState->batVoltage3S));
    qmlContext.setContextProperty(QStringLiteral("graphBatMotorV"), QVariant::fromValue((qreal)history.currentState->batVoltage2S));

    emit graphContextUpdated();
}

void MainWindowEventClass::startCommand() {
    RobotStartMessage msg(RobotStartMessage::Type::Start);
    emit startRobotControl(msg);
}

void MainWindowEventClass::stopCommand() {
    RobotStartMessage msg(RobotStartMessage::Type::Stop);
    emit startRobotControl(msg);
}

void MainWindowEventClass::setPidParemeters(qreal kp, qreal ki, qreal kd) {
    Config config;
    Pid pid;

    pid.setKd(kd);
    pid.setKi(ki);
    pid.setKp(kp);

    config.setPid(pid);

    emit controlParametersUpdated(config);
}

void MainWindowEventClass::setSSParameters(QString param, QString val) {
    Q_UNUSED(param);
    Q_UNUSED(val);
}

void MainWindowEventClass::errorMsgReceived(RobotErrorMessage::Code code) {
    switch (code) {

    case RobotErrorMessage::Code::LowBattery3S:
        qmlContext.setContextProperty(QStringLiteral("batterryTextColor"), QVariant::fromValue(QString("red")));
        break;

    case RobotErrorMessage::Code::LowBattery2S:
        qmlContext.setContextProperty(QStringLiteral("batterryTextColor"), QVariant::fromValue(QString("red")));
        break;

    default:
        break;
    }
}

void MainWindowEventClass::selfTestReceivedMessage(QString message) {
        qmlContext.setContextProperty(QStringLiteral("selfTestMessage"), QVariant::fromValue((message)));
}

QQuickItem* MainWindowEventClass::FindItemByName(QList<QObject *> nodes, const QString &name) {

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

QQuickItem* MainWindowEventClass::FindItemByName(QObject *rootObject, const QString &name) {
    return FindItemByName(rootObject->children(), name);
}

void MainWindowEventClass::connectQmlSignals(QObject *rootObject, QString str) {

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

