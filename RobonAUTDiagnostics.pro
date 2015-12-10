TEMPLATE = app

QT += qml quick widgets serialport
CONFIG += c++14

QMAKE_CXXFLAGS_CXX11    = -std=c++1y

SOURCES += main.cpp \
    Comm/robotmsghandler.cpp \
    Comm/robotmessage.cpp \
    Comm/commserial.cpp \
    Comm/robotterminalmessage.cpp \
    Comm/roboterrormessage.cpp \
    Comm/robotstatusmessage.cpp \
    ConsoleTabEventClass.cpp \
    Application.cpp \
    Config/config.cpp \
    Config/Controllers/pid.cpp \
    RobotState/robotstate.cpp \
    RobotState/imu.cpp \
    RobotState/linesensor.cpp \
    RobotState/distancesensor.cpp \
    robotstatehistory.cpp \
    GraphTabEventClass.cpp \
    Comm/robotsetattrmessage.cpp \
    Comm/robotstatusrequest.cpp \
    updaterequest.cpp \
    MainWindowEventClass.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Comm/robotmsghandler.h \
    Comm/robotmessage.h \
    Comm/commserial.h \
    Comm/robotterminalmessage.h \
    Comm/roboterrormessage.h \
    Comm/robotstatusmessage.h \
    ConsoleTabEventClass.h \
    Application.h \
    Config/config.h \
    Config/Controllers/pid.h \
    RobotState/robotstate.h \
    RobotState/imu.h \
    RobotState/linesensor.h \
    RobotState/distancesensor.h \
    robotstatehistory.h \
    GraphTabEventClass.h \
    Comm/robotsetattrmessage.h \
    Comm/robotstatusrequest.h \
    updaterequest.h \
    MainWindowEventClass.h

DISTFILES +=
