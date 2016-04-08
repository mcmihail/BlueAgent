#
#
# The Main application project

include(../Common.pri)

QT       += core

QT       -= gui

TARGET = BlueAgent
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    BlueAgent.cpp
