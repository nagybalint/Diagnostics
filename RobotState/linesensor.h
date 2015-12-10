#ifndef LINESENSOR_H
#define LINESENSOR_H

#include <QObject>
#include <QDataStream>

/**
 * @brief Vonalszenzor adatai
 *
 * Tartalmazza az első és hátsó szenzorsor pozíciót
 * valamint a vonal orientációt
 */
class LineSensor : public QObject
{
    Q_OBJECT
public:
    /** @brief default konstruktor */
    explicit LineSensor(QObject *parent = 0);

    /** @brief első szenzorsor pozíciója [m] */
    float frontLinePos;     // [m]
    /** @brief hátsó szenzorsor pozíciója [m] */
    float backLinePos;      // [m]
    /**
     * @brief vonal orientációja a robot koordinátarendszerében [rad]
     *
     * 0 rad az autó főtengelyével párhuzamos
     */
    float lineOrientation;  // [rad]

    /** @brief LineSensor::frontLinePos getter */
    float getFrontLinePos(void) const;
    /** @brief LineSensor::backLinePos getter */
    float getBackLinePos(void) const;
    /** @brief LineSensor::lineOrientation getter */
    float getLineOrientation(void) const;

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);

    /** @brief egyenlőség operátor felüldefiniálása */
    LineSensor& operator=(const LineSensor& other);

signals:

public slots:
};

/** << operátor felüldefiniálása, az LineSensor::writeTo beburkolása */
QDataStream& operator<<(QDataStream& stream, const LineSensor& LineSensor);
/** >> operátor felüldefiniálása, a  LineSensor::readFrom beburkolása */
QDataStream& operator>>(QDataStream& stream, LineSensor& LineSensor);

#endif // LINESENSOR_H
