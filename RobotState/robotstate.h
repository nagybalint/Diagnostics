#ifndef ROBOTSTATE_H
#define ROBOTSTATE_H

#include <QObject>
#include <QDataStream>
#include <QString>
#include "RobotState/imu.h"
#include "RobotState/linesensor.h"
#include "RobotState/distancesensor.h"
#include "Config/config.h"

/**
 * @brief A robot egy időpillanathoz tartozó állapotát reprezentálja
 *
 * Ilyen osztálypéldányok vannak eltárolva a RobotStateHistory::container vector-ban,
 * amikből majd a grafikonok rajzolódnak.
 */
class RobotState : public QObject
{
    Q_OBJECT
public:
    /** @brief Default konstruktor */
    explicit RobotState(QObject *parent = 0);
/*
    Q_PROPERTY(Config config READ getConfig WRITE setConfig MEMBER Config NOTIFY configChanged)
    Config getConfig() const { return Config; }
    void setConfig(const Config& param) { Config = param; }

    Q_PROPERTY(Imu imu READ getImu WRITE setImu MEMBER IMU NOTIFY imuChanged)
    Imu getImu() const { return IMU; }
    void setImu(const Imu& param) { IMU = param; }

    Q_PROPERTY(LineSensor linesensor READ getLineSensor WRITE setLineSensor MEMBER LineSensor NOTIFY linesensorChanged)
    LineSensor getLineSensor() const { return LineSensor; }
    void setLineSensor(const LineSensor& param) { LineSensor = param; }

    Q_PROPERTY(DistanceSensor distsensor READ getDistanceSensor WRITE setDistanceSensor MEMBER DistanceSensor NOTIFY distanceSensorChanged)
    Config getDistanceSensor() const { return DistanceSensor; }
    void setDistanceSensor(const DistanceSensor& param) { DistanceSensor = param; }
*/
    Q_PROPERTY(float batvoltage3S READ getBatVoltage3S WRITE setBatVoltage3S MEMBER batVoltage3S NOTIFY batVoltage3SChanged)
    /// @brief get batVoltage3S
    float getBatVoltage3S() const { return batVoltage3S; }
    /// @brief set batVoltage3S
    void setBatVoltage3S(const float& param) { batVoltage3S = param; }

    Q_PROPERTY(float batvoltage2S READ getBatVoltage2S WRITE setBatVoltage2S MEMBER batVoltage3S NOTIFY batVoltage2SChanged)
    /// @brief get batVoltage2S
    float getBatVoltage2S() const { return batVoltage2S; }
    /// @brief set batVoltage2S
    void setBatVoltage2S(const float& param) { batVoltage2S = param; }

    Q_PROPERTY(float carspeed READ getCarSpeed WRITE setCarSpeed MEMBER carSpeed NOTIFY carSpeedChanged)
    /// @brief get carSpeed
    float getCarSpeed() const { return carSpeed; }
    /// @brief set carSpeed
    void setCarSpeed(const float& param) { carSpeed = param; }

    Q_PROPERTY(float steeringangle READ getSteeringAngle WRITE setSteeringAngle MEMBER steeringAngle NOTIFY steeringAngleChanged)
    /// @brief get steeringAngle
    float getSteeringAngle() const { return steeringAngle; }
    /// @brief set steeringAngle
    void setSteeringAngle(const float& param) { steeringAngle = param; }

    Q_PROPERTY(float frontsensorangle READ getFrontSensorAngle WRITE setFrontSensorAngle MEMBER frontSensorAngle NOTIFY frontSensorAngleChanged)
    /// @brief get frontSensorAngle
    float getFrontSensorAngle() const { return frontSensorAngle; }
    /// @brief set frontSensorAngle
    void setFrontSensorAngle(const float& param) { frontSensorAngle = param; }

    /** @brief tagváltozók streambe írása */
    void writeTo(QDataStream& stream) const;
    /** @brief tagváltozók streamből olvasása */
    void readFrom(QDataStream& stream);
    /** osztály másolása (mert egy QObject-hez nem lehet másolókonstruktort létrehozni) */
    void copyFrom(const RobotState &other);

signals:
    /* not used */
    void batVoltage3SChanged();
    void batVoltage2SChanged();
    void carSpeedChanged();
    void steeringAngleChanged();
    void frontSensorAngleChanged();

public slots:

public:

    /** @see config */
    Config config;

    /** @see Imu */
    Imu IMU;

    /** @see LineSensor */
    LineSensor lineSensor;

    /** @see DistanceSensor */
    DistanceSensor distanceSensor;

    /** 3 cellás akku feszültsége [V] */
    float batVoltage3S;
    /** 2 cellás akku feszültsége [V] */
    float batVoltage2S;

    /** autó sebessége [m/s] */
    float carSpeed;

    /** kormányszervó szöge [rad] */
    float steeringAngle;

    /** elülső távolságszenzor szervójának szöge [rad] */
    float frontSensorAngle;

};

/** << operátor felüldefiniálása, az RobotState::writeTo beburkolása */
QDataStream& operator<<(QDataStream& stream, const RobotState& RobotState);
/** >> operátor felüldefiniálása, a  RobotState::readFrom beburkolása */
QDataStream& operator>>(QDataStream& stream, RobotState& RobotState);

#endif // ROBOTSTATE_H
