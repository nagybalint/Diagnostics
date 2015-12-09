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
    ConsoleTabEventClass.cpp \
    Application.cpp

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
    ConsoleTabEventClass.h \
    Application.h

