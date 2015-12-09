#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include "Controllers/pid.h"

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = 0);

    void writeTo(QDataStream& stream) const;
    void readFrom(QDataStream& stream);

signals:

public slots:

private:
    Pid Pid;
};

/* cover writeTo function */
QDataStream& operator<<(QDataStream& stream, const Config& Config);
/* covers readFrom function */
QDataStream& operator>>(QDataStream& stream, Config& Config);

#endif // CONFIG_H
