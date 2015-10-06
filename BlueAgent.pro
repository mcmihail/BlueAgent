#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T17:22:49
#
#-------------------------------------------------

QT       += core dbus

QT       -= gui

TARGET = BlueAgent
CONFIG   += console
CONFIG   -= app_bundle

DBUS_ADAPTORS += generated/Agent1.xml

TEMPLATE = app


SOURCES += main.cpp \
    dbus/Agent1.cpp

HEADERS += \
    dbus/Agent1.h

init_generated.commands = rm -rf generated; mkdir generated

generate_xml.commands += qdbuscpp2xml -o generated/Agent1.xml dbus/Agent1.h
generate_xml.depends = init_generated

#generate_adaptor.commands = qdbusxml2cpp -a generated/Agent1Adaptor generated/Agent1.xml
#generate_adaptor.depends = generate_xml

QMAKE_EXTRA_TARGETS += generate_xml init_generated
PRE_TARGETDEPS += generate_xml
