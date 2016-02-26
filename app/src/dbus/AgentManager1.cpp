#include "dbus/AgentManager1.h"
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusConnection>
#include <QDebug>
#include <QVariant>

namespace org {
namespace bluez {

const QString AgentManager1::SERIVCE_NAME = "org.bluez";
const QString AgentManager1::INTERFACE_NAME = "org.bluez.AgentManager1";
const QString AgentManager1::OBJECT_PATH = "/org/bluez";

AgentManager1::AgentManager1(QObject *parent) : QObject(parent)
{

}

void AgentManager1::RegisterAgent(QDBusObjectPath agent, QString capability) {
    QDBusMessage msg = QDBusMessage::createMethodCall(SERIVCE_NAME, OBJECT_PATH, INTERFACE_NAME, "RegisterAgent");
    msg << QVariant::fromValue(agent) << capability;
    QDBusMessage reply = QDBusConnection::systemBus().call(msg);
    if(reply.errorName() != "") {
        qDebug() << "Failed to register the agent: " << reply.errorName();
    } else {
        qDebug() << "Ok";
    }
}

void AgentManager1::UnregisterAgent(QDBusObjectPath agent) {
    QDBusMessage msg = QDBusMessage::createMethodCall(SERIVCE_NAME, OBJECT_PATH, INTERFACE_NAME, "UnregisterAgent");
    msg << QVariant::fromValue(agent);
    QDBusMessage reply = QDBusConnection::systemBus().call(msg);
    if(reply.errorName() != "") {
        qDebug() << "Failed to register the agent: " << reply.errorName();
    } else {
        qDebug() << "Ok";
    }
}

} // namespace bluez
} // namespace org
