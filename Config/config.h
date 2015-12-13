#ifndef CONFIG_H
#define CONFIG_H

#include <QObject>
#include "Controllers/pid.h"

/**
 * @brief Az autó konfigurálható paramétereit tartalmazza
 */
class Config : public QObject
{
    Q_OBJECT
public:
    /** @brief default konstruktor */
    explicit Config(QObject *parent = 0);

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);

    void setPid(Pid &pid);

    /** @brief egyenlőség operátor felüldefiniálása */
    Config& operator=(const Config& other);

signals:

public slots:

private:
    /**
     * @brief PID szabályozó paraméterei
     *
     * @see Pid
     */
    Pid pid;
};

/** << operátor felüldefiniálása, az Config::writeTo beburkolása */
QDataStream& operator<<(QDataStream& stream, const Config& Config);
/** >> operátor felüldefiniálása, a  Config::readFrom beburkolása */
QDataStream& operator>>(QDataStream& stream, Config& Config);

#endif // CONFIG_H
