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
    dbus/SystemBusInterface.cpp \
    dbus/Properties.cpp

HEADERS += \
    BlueAgent.h \
    dbus/SystemBusInterface.h \
    dbus/Properties.h
