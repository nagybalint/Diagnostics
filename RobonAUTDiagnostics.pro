TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    Config/config.cpp \
    Config/Controllers/pid.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Config/config.h \
    Config/Controllers/pid.h

