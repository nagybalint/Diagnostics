#ifndef ROBOTMSGHANDLER_H
#define ROBOTMSGHANDLER_H

#include <QObject>
#include "commserial.h"
#include "robotmessage.h"
#include "roboterrormessage.h"
#include "RobotState/robotstate.h"
#include "Comm/robotstartmessage.h"
/**
 * @brief RobotMsgHandler - Proxy tervezési minta alapján létrehozott osztály, a robot számára üzenetek küldését,
 * a robottól üzenetek fogadását teszi lehetővé az alkalmazás számára.
 * A fogadott üzenetekről a signaljain keresztül jelez, üzenetek küldése a slotjainak hívásával lehetséges.
 * Tartalmaz egy CommSerial ojektumra mutató pointert, amine kersztül az üzenetek küldése és
 * fogadása megvalósul, illetve a std::unique_ptr<RobotMessage> RobotMsgHandler ::messageIn pointert
 * a bejövő üzenetek feldolgozásához (ez strategy pattern alapján történik)
 * @see RobotMessage - Az üzenettípusok feldolgozásának megvalósításai
 */
class RobotMsgHandler : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief RobotMsgHandler - Konstruktor. Hozzáköti a RobotMsgHandler objektumpéldányt a
     * kommunikációért felelős CommSerial objektumhoz.
     * @param serial - A soros kommunkiációért felelős objektum
     */
    RobotMsgHandler(CommSerial& serial);
    /// Destruktor
    ~RobotMsgHandler() = default;
    /**
     * @brief listenOn - Hozzáköti a RobotMsgHandler példányt a paraméterként kapott, kommunikációért
     * felelős objektumhoz
     * @param serial - A soros kommunikációért felelős objektum
     */
    void listenOn(CommSerial& serial);

    /**
     * @brief Error - Az üzenetek fogadásával kapcsolatos hibatípusokattartalmazó osztály
     */
    enum class Error {
        /// Az üzenet fejléce hiányzik
        MissingStartByte,
        /// Az üzenetet lezáró byte hiányzik
        MissingEndByte,
        /// Ismeretlen üzenettípus érkezett
        UnknownType
    };

private:
    /**
     * @brief ParseState - A beérkező üzenet feldolgozásának lehetséges állapotait tartalmazó osztály
     */
    enum class ParseState {
        /// Az üzenet fejléce következik
        StartByte,
        /// Az üzenet típusa következik
        MsgType,
        /// A konkrét üzenettípus feldolgozás alatt áll
        Parsing,
        /// Az üzenetet lezáró szekvencia következik
        EndByte
    };
    /**
     * @brief currentParseState - A beérkező üzenet feldolgozottsági állapotát jellemző tagváltozó
     */
    ParseState currentParseState;
    /**
     * @brief serial - A soros kommunikációért felelős objektum
     */
    CommSerial* serial;
    /**
     * @brief messageIn - Az üzenetek feldolgozásáért felelős RobotMessage pointer
     * @note A RobotMessage osztály absztrakt ősosztály, így nem példányosítható. Az ősosztályra mutató pointer
     * a feldolgozás során mutat majd egy RobotMessage leszármazottra, ami az üzenet típusának megfelelően kerül
     * létrehozásra.
     */
    std::unique_ptr<RobotMessage> messageIn;
    /**
     * @brief emitSignal - A megfelelő üzenettípus megérkezését jelző signal kiadása
     * @param msg - A beérkezett üzenetre mutató pointer. A RobotMessage::type tagváltozója tartalmazza
     * az üzenet típusát.
     */
    void emitSignal(RobotMessage* msg);

signals:
    /**
     * @brief messageError - Az üzenetfogadás során fellépő hibát jelző signal.
     * @param errorCode - A fellépő hiba kódja.
     */
    void messageError(RobotMsgHandler::Error errorCode);
    /**
     * @brief terminalMessageReceived - A robottól a consolera érkezett üzenetet jelzi
     * @param msg - A beérkezett üzenet
     */
    void terminalMessageReceived(QString& msg);
    /**
     * @brief errorMessageReceived - A robottól beérkezett hibaüzenetet jelző signal
     * @param errorCode - A hiba kódja.
     */
    void errorMessageReceived(RobotErrorMessage::Code errorCode);
    /**
     * @brief statusUpdateReceived - A robottól státuszfrissítés érkezett
     * @param newState - A frissített státsuzt tartalmazó struktúra
     */
    void statusUpdateReceived(RobotState& newState);

public slots:

    /**
     * @brief dataAvailable - A soros portról beérkező adat feldolgozása
     * @param inStream - A bejövő adatokat tartalmazó stream
     */
    void dataAvailable(QDataStream &inStream);
    /**
     * @brief sendTerminalMsg - terminál üzenet küldése a robot számára
     * @param command - Az elküldendő üzenet szövege
     */
    void sendTerminalMsg(QString& command);
    /**
     * @brief setRobotAttribute - Skalár attribútumok beállítása a roboton
     * @param attr - Az elküldendő attribútum típusa
     * @param value - Az elküldendő attribútum értéke
     * @warning Csak RobotMessage::Type::SetServo és RobotMessage::Type::SetSpeed típusú üzenetek
     * küldhetők vele
     */
    void setRobotAttribute(RobotMessage::Type attr, float value);
    /**
     * @brief sendStatusRequest - státuszfrissítés kérése a robottól
     */
    void sendStatusRequest();
    /**
     * @brief sendConfig - Új konfiguráció elküldése a robot számára
     * @param config - Az elküldendő konfiguráció
     */
    void sendConfig(Config& config);

    void sendStartMessage(RobotStartMessage& msg);

};

#endif // ROBOTMSGHANDLER_H
