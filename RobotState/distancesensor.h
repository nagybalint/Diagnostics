#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <QObject>

class DistanceSensor : public QObject
{
    Q_OBJECT
public:
    explicit DistanceSensor(QObject *parent = 0);

    float getDistLeft(void);
    float getDistRight(void);
    float getDistFront(void);

signals:

public slots:

private:
    float distLeft;     // [m]
    float distRight;    // [m]
    float distFront;    // [m]
};

#endif // DISTANCESENSOR_H
