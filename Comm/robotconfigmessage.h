#ifndef ROBOTCONFIGMESSAGE_H
#define ROBOTCONFIGMESSAGE_H

#include <QObject>
#include "robotmessage.h"
#include "Config/config.h"
#include <QDataStream>

class RobotConfigMessage : public RobotMessage
{
    Q_OBJECT
public:
    RobotConfigMessage(Config& conf);
    ~RobotConfigMessage() = default;
    Config* config;
    int parseMessage(QDataStream& inStream) override;
signals:

public slots:
};

QDataStream& operator<<(QDataStream&, const RobotConfigMessage&);

#endif // ROBOTCONFIGMESSAGE_H
