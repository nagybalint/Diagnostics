#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include "Controllers/pid.h"

class Config : public QObject
{
    Q_OBJECT
public:
    explicit Config(QObject *parent = 0);

signals:

public slots:

private:
    Pid Pid;
};

#endif // CONFIG_H
