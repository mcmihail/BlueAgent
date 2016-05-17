#include "dbus/SystemBusInterface.h"
#include <QDBusConnection>
#include <QDBusArgument>
#include <QDebug>

SystemBusInterface::SystemBusInterface(QObject *parent) :
    QObject(parent)
{
}

QDBusMessage SystemBusInterface::call(const QString &methodName) {
    QVariantList emptyList;
    return call(methodName, emptyList);
}

QDBusMessage SystemBusInterface::call(const QString &methodName, QVariantList arguments) {
    QDBusMessage msg = QDBusMessage::createMethodCall(
                getServiceName(), getObjectPath(), getInterfaceName(), methodName);

    foreach (QVariant arg, arguments) {
        msg << arg;
    }

    return QDBusConnection::systemBus().call(msg);
}

bool SystemBusInterface::connect(const QString &signal, QObject *receiver, const char *slot) {
    return QDBusConnection::systemBus().connect(getServiceName(), getObjectPath(), getInterfaceName() , signal, receiver, slot);
}

bool SystemBusInterface::hasReplied(const QDBusMessage &message) {
    return message.type() == QDBusMessage::ReplyMessage;
}

QString SystemBusInterface::getServiceName() const {
    return "org.bluez";
}
