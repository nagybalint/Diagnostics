#ifndef ROBOTSTATUSREQUEST_H
#define ROBOTSTATUSREQUEST_H

#include <QObject>
#include "robotmessage.h"
#include <QDataStream>
/**
 * @brief RobotStatusRequest - A robottól státuszfrissítést kérő üzenet reprezentációja, az absztrakt RobotMessage
 * ősosztály leszármazottja.
 */
class RobotStatusRequest : public RobotMessage
{
    Q_OBJECT
public:
    RobotStatusRequest();
    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     * @note Dummy függvény. A robot nem küld a kliensnek státuszlekérdezést
     */
    int parseMessage(QDataStream &inStream) override;

signals:

public slots:
};
/**
 * @brief operator << Egy RobotStatusRequest objektumot QDataStream-be író operátor
 */
QDataStream& operator<<(QDataStream&, const RobotStatusRequest&);

#endif // ROBOTSTATUSREQUEST_H
