#ifndef PID_H
#define PID_H

#include <QObject>
#include <QDataStream>

/**
 * @brief PID szabályozó konfigurálható paraméterei
 *
 * A Config osztály tartalmazza tagváltozóként,
 * a szabályozó hangolására szolgál
 */

class Pid : public QObject
{
    Q_OBJECT
public:
    explicit Pid(QObject *parent = 0);

    /** @brief set Kp */
    void setKp(float param);
    /** @brief set Ki */
    void setKi(float param);
    /** @brief set Kd */
    void setKd(float param);

    /** @brief get Kp */
    float getKp(void) const;
    /** @brief get Ki */
    float getKi(void) const;
    /** @brief get Kd */
    float getKd(void) const;

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);

    /** @brief egyenlőség operátor felüldefiniálása */
    Pid& operator=(const Pid& other);

signals:

public slots:

private:
    /** @brief szabályozó P tag szorzótényezője */
    float Kp;
    /** @brief szabályozó I tag szorzótényezője */
    float Ki;
    /** @brief szabályozó D tag szorzótényezője */
    float Kd;
};

/** << operátor felüldefiniálása, az Pid::writeTo függvény beburkolása */
QDataStream& operator<<(QDataStream& stream, const Pid& Pid);
/** >> operátor felüldefiniálása, a  Pid::readFrom függvény beburkolása */
QDataStream& operator>>(QDataStream& stream, Pid& Pid);

#endif // PID_H
