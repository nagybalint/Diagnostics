#ifndef ROBOTERRORMESSAGE_H
#define ROBOTERRORMESSAGE_H

#include <QObject>
#include "robotmessage.h"
/**
 * @brief RobotErrorMessage - A robot által küldött hibaüzeneteket reprezentáló osztály, az absztrakt
 * RobotMessage osztály leszármazottja. A beérkező hiba típusát egy RobotErrorMessage::Code hibakód
 * azonosítja.
 */
class RobotErrorMessage : public RobotMessage
{
    Q_OBJECT
public:
    /**
     * @brief RobotErrorMessage - Konstruktor. Az üzenet típusát RobotMessage::Type::Error értékre állítja
     */
    RobotErrorMessage();
    /// Destruktor
    ~RobotErrorMessage() = default;

    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     */
    int parseMessage(QDataStream &inStream) override;

    /**
     * @brief Code - A robot által küldött hibaüzenet lehetséges típusait tartalmazó osztály
     */
    enum class Code {
        /// Alacsony feszültség a 3 cellás akkumulátoron
        LowBattery3S = 0x0001,
        /// Alacsony feszültség a 2 cellás akkumulátoron
        LowBattery2S = 0x0002
    };

    /**
     * @brief getCode - A hibaüzenet hibakódját lekérdező függvény
     * @return Hibakód
     */
    RobotErrorMessage::Code getCode();
    /**
     * @brief getErrorCode - A beérkezett hibakód alapján megállapítja a hiba típusát
     * @param codeByte - A beérkezett 2 bájtos hibakód
     * @return A hibakód alapján megállapított hibatípus
     */
    RobotErrorMessage::Code getErrorCode(quint16 codeByte);

private:
    /**
     * @brief errorCode - A hibaüzenet típusa
     */
    RobotErrorMessage::Code errorCode;
    /**
     * @brief msgSize - A hibaüzenet mérete
     */
    const quint32 msgSize = 2; // In bytes

public slots:
};

#endif // ROBOTERRORMESSAGE_H
