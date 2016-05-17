#
#
# The Main application project

include(../Common.pri)

QT       += core \
            dbus

QT       -= gui

TARGET = BlueAgent
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    BlueAgent.cpp \
    dbus/SystemBusInterface.cpp

HEADERS += \
    BlueAgent.h \
    dbus/SystemBusInterface.h
