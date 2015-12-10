#ifndef ROBOTSTATUSMESSAGE_H
#define ROBOTSTATUSMESSAGE_H

#include <QObject>
#include "robotmessage.h"
#include "RobotState/robotstate.h"
/**
 * @brief RobotStatusMessage - A robot által küldött státuszfrissítés üzeneteket reprezentáló osztály,
 * az absztrakt RobotMessage ősosztály leszármazottja. Tartalmaz egy RobotState tagváltozót, melybe a
 * bejövő üzenet tartalma alapján a robot állapotát elmenti.
 */
class RobotStatusMessage : public RobotMessage
{
    Q_OBJECT
public:
    /**
     * @brief state - A bejövő üzenetben szerpelő robot-állapot tárolására szolgáló tagváltozó
     */
    RobotState state;
    /**
     * @brief RobotStatusMessage - Konstruktor
     */
    RobotStatusMessage();
    /// Destruktor
    ~RobotStatusMessage() = default;
    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     */
    int parseMessage(QDataStream &inStream) override;

private:
    /**
     * @brief size - A státuszfrissítés üzenet hossza
     */
    static const quint32 size = 5 * sizeof(quint32);
signals:

public slots:
};

#endif // ROBOTSTATUSMESSAGE_H
