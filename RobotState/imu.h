#ifndef IMU_H
#define IMU_H

#include <QObject>
#include <QDataStream>

/*
 * Inertial Measurement Unit
 * store the orientation around each axis
 */
class Imu : public QObject
{
    Q_OBJECT
public:
    explicit Imu(QObject *parent = 0);

    void setOrientX(float param);
    void setOrientY(float param);
    void setOrientZ(float param);

    float getOrientX(void) const;
    float getOrientY(void) const;
    float getOrientZ(void) const;

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

    Imu& operator=(const Imu& other);

signals:

public slots:

private:
    float orientX;  // orientation around X axis
    float orientY;  // orientation around Y axis
    float orientZ;  // orientation around Z axis
};

/* covers writeTo function */
QDataStream& operator<<(QDataStream& stream, const Imu& Imu);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, Imu& Imu);

#endif // IMU_H
