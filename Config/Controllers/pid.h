#ifndef PID_H
#define PID_H

#include <QObject>
#include <QDataStream>

class Pid : public QObject
{
    Q_OBJECT
public:
    explicit Pid(QObject *parent = 0);

    /* set Kp gain */
    void setKp(float param);
    /* set Ki gain */
    void setKi(float param);
    /* set Kd gain */
    void setKd(float param);

    /* get Kp gain */
    float getKp(void);
    /* get Ki gain */
    float getKi(void);
    /* get Kd gain */
    float getKd(void);

    /* serialize the object to a stream */
    void writeTo(QDataStream& stream) const;

signals:

public slots:

private:
    float Kp;
    float Ki;
    float Kd;
};

/* cover the writeTo function */
QDataStream& operator<<(QDataStream& stream, const Pid& Pid);

#endif // PID_H
