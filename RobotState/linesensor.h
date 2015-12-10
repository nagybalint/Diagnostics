#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <QObject>
#include <QDataStream>

class LineSensor : public QObject
{
    Q_OBJECT
public:
    explicit LineSensor(QObject *parent = 0);

    float frontLinePos;     // [m]
    float backLinePos;      // [m]
    float lineOrientation;  // [rad]

    float getFrontLinePos(void) const;
    float getBackLinePos(void) const;
    float getLineOrientation(void) const;

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

    LineSensor& operator=(const LineSensor& other);

signals:

public slots:
};

/* covers writeTo function */
QDataStream& operator<<(QDataStream& stream, const LineSensor& LineSensor);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, LineSensor& LineSensor);

#endif // LINESENSOR_H
