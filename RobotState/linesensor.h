#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <QObject>

class LineSensor : public QObject
{
    Q_OBJECT
public:
    explicit LineSensor(QObject *parent = 0);

    float getFrontLinePos(void);
    float getBackLinePos(void);
    float getLineOrientation(void);

signals:

public slots:

private:
    float frontLinePos;     // [m]
    float backLinePos;      // [m]
    float lineOrientation;  // [rad]
};

#endif // LINESENSOR_H
