/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp -a agent1_adaptor.h: generated/Agent1.xml
 *
 * qdbusxml2cpp is Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * This file may have been hand-edited. Look for HAND-EDIT comments
 * before re-generating it.
 */

#ifndef AGENT1_ADAPTOR_H_1456473005
#define AGENT1_ADAPTOR_H_1456473005

#include <QtCore/QObject>
#include <QtDBus/QtDBus>
QT_BEGIN_NAMESPACE
class QByteArray;
template<class T> class QList;
template<class Key, class Value> class QMap;
class QString;
class QStringList;
class QVariant;
QT_END_NAMESPACE

/*
 * Adaptor class for interface org.bluez.Agent1
 */
class Agent1Adaptor: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.bluez.Agent1")
    Q_CLASSINFO("D-Bus Introspection", ""
"  <interface name=\"org.bluez.Agent1\">\n"
"    <method name=\"Release\"/>\n"
"    <method name=\"RequestPinCode\">\n"
"      <arg direction=\"out\" type=\"s\"/>\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"    </method>\n"
"    <method name=\"DisplayPinCode\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"pincode\"/>\n"
"    </method>\n"
"    <method name=\"RequestPasskey\">\n"
"      <arg direction=\"out\" type=\"u\"/>\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"    </method>\n"
"    <method name=\"DisplayPasskey\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"      <arg direction=\"in\" type=\"u\" name=\"passkey\"/>\n"
"      <arg direction=\"in\" type=\"q\" name=\"entered\"/>\n"
"    </method>\n"
"    <method name=\"RequestConfirmation\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"      <arg direction=\"in\" type=\"u\" name=\"passkey\"/>\n"
"    </method>\n"
"    <method name=\"RequestAuthorization\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"    </method>\n"
"    <method name=\"AuthorizeService\">\n"
"      <arg direction=\"in\" type=\"o\" name=\"device\"/>\n"
"      <arg direction=\"in\" type=\"s\" name=\"uuid\"/>\n"
"    </method>\n"
"    <method name=\"Cancel\"/>\n"
"  </interface>\n"
        "")
public:
    Agent1Adaptor(QObject *parent);
    virtual ~Agent1Adaptor();

public: // PROPERTIES
public Q_SLOTS: // METHODS
    void AuthorizeService(const QDBusObjectPath &device, const QString &uuid);
    void Cancel();
    void DisplayPasskey(const QDBusObjectPath &device, uint passkey, ushort entered);
    void DisplayPinCode(const QDBusObjectPath &device, const QString &pincode);
    void Release();
    void RequestAuthorization(const QDBusObjectPath &device);
    void RequestConfirmation(const QDBusObjectPath &device, uint passkey);
    uint RequestPasskey(const QDBusObjectPath &device);
    QString RequestPinCode(const QDBusObjectPath &device);
Q_SIGNALS: // SIGNALS
};

#endif