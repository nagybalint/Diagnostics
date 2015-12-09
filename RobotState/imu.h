#ifndef IMU_H
#define IMU_H

#include <QObject>

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

    float getOrientX(void);
    float getOrientY(void);
    float getOrientZ(void);


signals:

public slots:

private:
    float orientX;  // orientation around X axis
    float orientY;  // orientation around Y axis
    float orientZ;  // orientation around Z axis
};

#endif // IMU_H
