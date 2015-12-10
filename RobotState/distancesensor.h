#ifndef DISTANCESENSOR_H
#define DISTANCESENSOR_H

#include <QObject>
#include <QDataStream>

/**
 * @brief Távolságérzékelő szenzorok adatai (bal, jobb, első)
 */
class DistanceSensor : public QObject
{
    Q_OBJECT
public:
    explicit DistanceSensor(QObject *parent = 0);

    float getDistLeft(void) const;
    float getDistRight(void) const;
    float getDistFront(void) const;

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

    DistanceSensor& operator=(const DistanceSensor& other);

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
