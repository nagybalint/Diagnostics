#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <QObject>
#include <QDataStream>

class LineSensor : public QObject
{
    Q_OBJECT
public:
    explicit LineSensor(QObject *parent = 0);

    float getFrontLinePos(void);
    float getBackLinePos(void);
    float getLineOrientation(void);

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

signals:

public slots:

private:
    float frontLinePos;     // [m]
    float backLinePos;      // [m]
    float lineOrientation;  // [rad]
};

/* covers writeTo function */
QDataStream& operator<<(QDataStream& stream, const LineSensor& LineSensor);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, LineSensor& LineSensor);

#endif // LINESENSOR_H
