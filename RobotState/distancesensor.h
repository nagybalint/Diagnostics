#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <QObject>
#include <QDataStream>

class DistanceSensor : public QObject
{
    Q_OBJECT
public:
    explicit DistanceSensor(QObject *parent = 0);
    DistanceSensor(const DistanceSensor &from); // Copy constructor

    float getDistLeft(void);
    float getDistRight(void);
    float getDistFront(void);

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

signals:

public slots:

private:
    float distLeft;     // [m]
    float distRight;    // [m]
    float distFront;    // [m]
};

/* covers writeTo function */
QDataStream& operator<<(QDataStream& stream, const DistanceSensor& DistanceSensor);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, DistanceSensor& DistanceSensor);

#endif // DISTANCESENSOR_H
