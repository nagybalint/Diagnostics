#ifndef ROBOTTERMINALMESSAGE_H
#define ROBOTTERMINALMESSAGE_H

#include <QObject>
#include "robotmessage.h"
/**
 * @brief RobotTerminalMessage - A robotnak küldhető, illetve onnan fogadható console üzeneteket reprezentáló
 * osztály, az absztrakt RobotMessage ősosztály leszármazottja. Küldése a robot számára az alkalmazás
 * console ablakán kersztül lehetséges.
 * A robotnak küldött RobotTerminalMessage üzeneteket a roboton futó montiroprogram értelmezi, a robottól fogadott RobotTerminalMessage
 * üzenetek az alkalmazás console ablakában jelennek meg.
 */
class RobotTerminalMessage : public RobotMessage
{
    Q_OBJECT
public:
    /**
     * @brief RobotTerminalMessage - Konstruktor
     */
    RobotTerminalMessage();
    /**
     * @brief RobotTerminalMessage - Konstruktor
     * @param msg - Az üzenet szövege
     */
    RobotTerminalMessage(QString& msg);

    /**
     * @brief parseMessage - Az absztrakt RobotMessage ősosztály RobotMessage::parseMessage() virtuális
     * függvényének implementációja
     * @see RobotMessage::parseMessage()
     */
    int parseMessage(QDataStream &inStream) override;
    /**
     * @brief setMessage - Az üzenet szövegét beállító függvény
     * @param msg - Az üzenet szövege
     */
    void setMessage(QString& msg);
    /**
     * @brief getMessage - Az üzenet szövegét lekérdező függvény
     * @return Az üzenet szövege
     */
    QString& getMessage();
    friend QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

private:
    /**
     * @brief message - Az üzenet szövegét tartalmazó változó
     */
    QString message;

signals:

public slots:
};
/**
 * @brief operator << - RobotTerminalMessage objektumot QDataStream-be író operátor
 * @warning Az üzenetet tartalmazó RobotTerminalMessage::message QString hossza NEM kerül
 * kiírásra, csak a nyers adat
 */
QDataStream &operator<<(QDataStream &, const RobotTerminalMessage &);

#endif // ROBOTTERMINALMESSAGE_H
