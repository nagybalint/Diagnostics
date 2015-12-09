#ifndef ROBOTSTATUSMESSAGE_H
#define ROBOTSTATUSMESSAGE_H

#include <QObject>

class RobotStatusMessage : public QObject
{
    Q_OBJECT
public:
    explicit RobotStatusMessage(QObject *parent = 0);

signals:

public slots:
};

#endif // ROBOTSTATUSMESSAGE_H
