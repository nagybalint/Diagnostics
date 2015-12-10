#ifndef IMU_H
#define IMU_H

#include <QObject>
#include <QDataStream>

/**
 * @brief Inertial Measurement Unit -
 * A 9 szabadsági fokú mozgásérzékelő modul adatai
 * és az azokból származtatott mennyiségek
 *
 * MPU-9250 modul \n
 * 3 tengelyes gyorsulásérzékelő \n
 * 3 tengelyes giroszkóp \n
 * 3 tengelyes mágneses iránytű \n
 */
class Imu : public QObject
{
    Q_OBJECT
public:
    /** @brief Default konstruktor */
    explicit Imu(QObject *parent = 0);

    /** @brief Imu::orientX setter */
    void setOrientX(float param);
    /** @brief Imu::orientY setter */
    void setOrientY(float param);
    /** @brief Imu::orientZ setter */
    void setOrientZ(float param);

    /** @brief Imu::orientX getter */
    float getOrientX(void) const;
    /** @brief Imu::orientY getter */
    float getOrientY(void) const;
    /** @brief Imu::orientZ getter */
    float getOrientZ(void) const;

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);

    /** @brief egyenlőség operátor felüldefiniálása */
    Imu& operator=(const Imu& other);

signals:

public slots:

private:
    /** @brief robot orientációja az X tengely körül */
    float orientX;
    /** @brief robot orientációja az Y tengely körül */
    float orientY;
    /** @brief robot orientációja az Z tengely körül */
    float orientZ;
};

/** << operátor felüldefiniálása, az Imu::writeTo beburkolása */
QDataStream& operator<<(QDataStream& stream, const Imu& Imu);
/** >> operátor felüldefiniálása, a  Imu::readFrom beburkolása */
QDataStream& operator>>(QDataStream& stream, Imu& Imu);

#endif // IMU_H
