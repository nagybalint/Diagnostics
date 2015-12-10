#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QObject>
#include <QSerialPort>
#include <memory>

/**
 * @brief CommSerial - Soros porton keresztüli kommunikációt kezelő osztály. Rendelkezik egy QSerialPort
 * tagváltozóval, melyen keresztül a soros kommunikáció lezajlik.
 */
class CommSerial : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief CommSerial - Konstruktor. Csatlakozik a soros portra és csatlakozik a soros port
     * hibakezelő signaljához
     */
    CommSerial();
    /// Destruktor
    ~CommSerial();

    /**
     * @brief isConnected - A soros port állapotát lekérdező függvény
     * @return true, ha nyitva van a port, false, ha zárva
     */
    bool isConnected();
    /**
     * @brief connect - Megnyitja az osztályhoz tartozó soros portot - ha még nem volt nyitva
     */
    void connect();
    /**
     * @brief disconnect - Lezárja az osztályhoz tartozó soros portot - ha nyitva volt
     */
    void disconnect();


    template<typename T>
    /**
     * @brief send - A soros porthoz tartozó küldő függvény. A kiírandó objektumot a küldő streambe írja, majd
     * a streamhez tartozó konténer tartalmát a soros portra küldi.
     * @param outObject - A soros portra írandó objektum
     * @warning csak QDataStream-be sorosítható osztályokkal hívható
     */
    void send(const T& outObject) {

        auto stream = getSendStream();
        *stream << outObject;
        sendBufferedContent();

    }

private:

    /**
     * @brief serialPort - Soros port tagváltozó
     */
    QSerialPort serialPort;
    /**
     * @brief sendBuffer - A küldési stream által használt konténer objektum
     */
    QByteArray sendBuffer;
    /**
     * @brief receiveStream - A fogadáshoz használt stream
     */
    std::unique_ptr<QDataStream> receiveStream;
    /**
     * @brief getReceiveStream - A fogadáshoz használt stream lekérdezése
     * @return A fogadásra szolgáló streamre mutató pointerrel tér vissza
     */
    QDataStream* getReceiveStream();
    /**
     * @brief getSendStream - A küldéshez használt stream lekérdezése
     * @return A küldésre szolgáló streamre mutató pointerrel tér vissza
     */
    std::unique_ptr<QDataStream> getSendStream();
    /**
     * @brief sendBufferedContent - Elküldi a sendBuffer tartalmát a soros porton keresztül
     */
    void sendBufferedContent();

signals:
    /**
     * @brief dataAvailable - A soron porton rendelkezésre álló adatot jelző signal
     * @param inStream - A bejövő üzenet elérésére használható stream
     * @warning Nem biztos, hogy a teljes üzenet a fogadó streamben van a signal kiadásakor!
     */
    void dataAvailable(QDataStream &inStream);

public slots:
    /**
     * @brief dataReceived - A serial port beérkező adataira figyelő slot. A CommSerial osztály
     * dataAvailable() szignálját adja ki rendelkezésre álló adat esetén
     */
    void dataReceived();
    /**
     * @brief handleSerialPortError - A soros porton bekövetkező hibaeseményeket lekezelő slot
     * @param error - A soros porton keletkezett hibaüzenet leírója
     */
    void handleSerialPortError(QSerialPort::SerialPortError error);
};

#endif // COMMUNICATION_H
