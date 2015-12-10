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
    /** Defauld konstruktor */
    explicit DistanceSensor(QObject *parent = 0);

    /** @brief Visszaadja a bal oldali távolságérzékelő által mért adatot */
    float getDistLeft(void) const;
    /** @brief Visszaadja a jobb oldali távolságérzékelő által mért adatot */
    float getDistRight(void) const;
    /** @brief Visszaadja az elülső távolságérzékelő által mért adatot */
    float getDistFront(void) const;

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);

    /** @brief egyenlőség operátor felüldefiniálása */
    DistanceSensor& operator=(const DistanceSensor& other);

signals:

public slots:

private:
    /** @brief bal oldali távolságérzékelő által mért adat [m] */
    float distLeft;
    /** @brief jobb oldali távolságérzékelő által mért adat */
    float distRight;
    /** @brief elülső távolságérzékelő által mért adat */
    float distFront;
};

/** << operátor felüldefiniálása, az DistanceSensor::writeTo beburkolása */
QDataStream& operator<<(QDataStream& stream, const DistanceSensor& DistanceSensor);
/** >> operátor felüldefiniálása, a  DistanceSensor::readFrom beburkolása */
QDataStream& operator>>(QDataStream& stream, DistanceSensor& DistanceSensor);

#endif // DISTANCESENSOR_H
