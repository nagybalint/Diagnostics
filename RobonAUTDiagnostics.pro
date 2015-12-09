TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Config/config.cpp \
    Config/Controllers/pid.cpp \
    RobotState/robotstate.cpp \
    RobotState/imu.cpp \
    RobotState/linesensor.cpp \
    RobotState/distancesensor.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Config/config.h \
    Config/Controllers/pid.h \
    RobotState/robotstate.h \
    RobotState/imu.h \
    RobotState/linesensor.h \
    RobotState/distancesensor.h

