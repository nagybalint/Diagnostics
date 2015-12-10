#ifndef ROBOTCONFIGMESSAGE_H
#define ROBOTCONFIGMESSAGE_H

#include <QObject>
#include "robotmessage.h"
#include "Config/config.h"
#include <QDataStream>
/**
 * @brief RobotConfigMessage - Robot konfiguráció üzenettípus, a RobotMessage absztrakt ősosztály leszármazott osztálya
 * Rendelkezik egy Config tagváltozóra mutató pointerrel, mely az elküldendő konfiguráció beállításait tárolja. Az
 * oszátlyra felüldefiniálásra került az operator <<() operátor, melynek segítségével QDataStream-be írható
 */
class RobotConfigMessage : public RobotMessage
{
    Q_OBJECT
public:
    /**
     * @brief RobotConfigMessage - konstruktor. Az üzenet típusát RobotMessage::Type::Config típusra állítja,
     * illetve elmenti a konfigurációs beállításokra mutató változót
     * @param conf - Az elküldendő beállításokat tartalmazó Config változó referenciája
     */
    RobotConfigMessage(Config& conf);
    /// Destruktor
    ~RobotConfigMessage() = default;
    /**
     * @brief config - Az elküldendő konfigurációs beállításokat tartalmazó Config változóra mutató pointer
     */
    Config* config;
    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     * @note Dummy függvény. A robot nem küld vissza a kliensnek konfigurációs adatokat.
     */
    int parseMessage(QDataStream& inStream) override;
signals:

public slots:
};
/**
 * @brief operator << - Egy RobotConfigMessage objecktumot QDataStream-be író operátor
 */
QDataStream& operator<<(QDataStream&, const RobotConfigMessage&);

#endif // ROBOTCONFIGMESSAGE_H
