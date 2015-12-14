#ifndef ROBOTSTARTMESSAGE_H
#define ROBOTSTARTMESSAGE_H

#include <QObject>
#include <QDataStream>
#include "robotmessage.h"

/**
 * @brief RobotStatusRequest - A robottól státuszfrissítést kérő üzenet reprezentációja, az absztrakt RobotMessage
 * ősosztály leszármazottja.
 */
class RobotStartMessage : public RobotMessage
{
    Q_OBJECT
public:

    enum class Type {
        Start = 0x01,
        Stop = 0x02
    };

    RobotStartMessage(RobotStartMessage::Type type);
    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     * @note Dummy függvény. A robot nem küld a kliensnek státuszlekérdezést
     */
    int parseMessage(QDataStream &inStream) override;

    RobotStartMessage::Type startType;

signals:

public slots:
};
/**
 * @brief operator << Egy RobotStatusRequest objektumot QDataStream-be író operátor
 */
QDataStream& operator<<(QDataStream&, const RobotStartMessage&);

#endif // ROBOTSTARTMESSAGE_H
