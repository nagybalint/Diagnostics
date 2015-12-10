#ifndef ROBOTMESSAGE_H
#define ROBOTMESSAGE_H

#include <QObject>

#define DEBUG_MSG_START_CODE                0x02
#define DEBUG_MSG_END_CODE                  0x03

/**
 * @brief RobotMessage -
 * Absztrakt ősosztály, melyből a robot számára küldhető különböző üzenettípusok
 * származnak le.
 * Strategy tervezési minta ősosztálya -- az absztrakt RobotMessage::parseMessage(QDataStream&)
 * függvényét az egyes tagváltozó implementálják, és a leszármazott osztályok ezen függvényét
 * meghívva képesek magukat beolvasni.
 */

class RobotMessage : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief RobotMessage konstruktor
     * @warning A RobotMessage oszály egy absztrakt ősosztály, nem példányosítható!
     */
    RobotMessage();
    ~RobotMessage() = default;
    /**
     * @brief A robotnak küldhető egyes üzenetek típusait tartalmazza
     */
    enum class Type {
        /// A console ablakban megjelenő, illetve a robotnak terminál üzenetként elküldött adatok típusa
        Terminal = 0x01,
        /// A robottól beérkező hibajelző üzenetek
        Error = 0x02,
        /// A robottól beérkező státuszfrissítés
        StatusUpdate = 0x03,
        /// A robot számára küldött konfigurációs üzenet
        Config = 0x04,
        /// Státusz frissítés lekérése a robottól
        StatusRequest = 0x05,
        /// A robot sebességének beállítása
        SetSpeed = 0x06,
        /// A robot kormányszögének beállítása
        SetServo = 0x07
    };

    /**
     * @brief A RobotMessage példányok típusa
     * @note A leszármoazot osztályok töltik ki saját típusuknak megfelelően
     */
    Type type;

    /**
     * @brief getType - Egy üzenet típusának meghatározása annak azonosító byteja alapján
     * @param modeID - Az üzenet azonosító byteja
     * @return Az azonosító byte alapján meghatározott üzenettípus
     */
    static RobotMessage::Type getType(quint8 modeID);
    /**
     * @brief parseMessage - Virtuális üzenetfeldolgozó függvény, az absztrakt RobotMessage ősosztályban
     * nincs implementálva
     * @param inStream - A bejövő üzenetet tartalmazó adatfolyam
     * @return 0 ha sikeresen beolvasásra került az üzenet, -1 egyébként
     * @note Minden leszármazott osztály köteles megvalósítani
     * @warning csak akkor 0 a visszatérési érték, ha a TELJES üzenet beolvasásra került
     */
    virtual int parseMessage(QDataStream &inStream) = 0;

signals:
    /**
     * @brief messageError - Hibás üzenet vételét jelző szignál
     * @param description - A hiba leírása
     */
    void messageError(QString description);

};

#endif // ROBOTMESSAGE_H
