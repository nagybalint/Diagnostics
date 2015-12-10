#ifndef ROBOTSETATTRMESSAGE_H
#define ROBOTSETATTRMESSAGE_H

#include "robotmessage.h"
#include <QDataStream>
/**
 * @brief RobotSetAttrMessage - A robot bizonyos skalár attibútumait beállító üzenettípus, a RobotMessage
 * absztrakt ősosztály leszármazot osztálya.
 */
class RobotSetAttrMessage : RobotMessage
{
public:
    /**
     * @brief value - A robotban beállítandó skalárattribútum értéke
     */
    float value;

    /**
     * @brief RobotSetAttrMessage - Konstruktor. Beállítja az üzenet típusát és a skalát attribútum értékét. Az üzenet
     * típusa egyben a beállítandó paramétert is meghatározza.
     * @param type - A beállítandó paraméter típusa
     * @param value - A beállítandó paraméter értéke
     * @warning Csak RobotMessage::Type::SetServo és RobotMessage::Type::SetSpeed típusokkal hozható létre
     */
    RobotSetAttrMessage(RobotMessage::Type type, float value);
    ~RobotSetAttrMessage() = default;
    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     * @note Dummy függvény. A robot nem küld a kliensnek attribútumbeállító parancsot
     */
    int parseMessage(QDataStream &inStream) override;
    friend QDataStream& operator<<(QDataStream&, const RobotSetAttrMessage&);

};

/**
 * @brief operator << Egy RobotSetAttrMessage objektumot QDataStream-be író operátor
 */
QDataStream& operator<<(QDataStream&, const RobotSetAttrMessage&);

#endif // ROBOTSETATTRMESSAGE_H
