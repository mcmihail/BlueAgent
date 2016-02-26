#include "dbus/SystemBusInterface.h"
#include <QDBusConnection>

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

bool SystemBusInterface::connect(const QString &signal, const char *slot) {
    return QDBusConnection::systemBus().connect(getServiceName(), getObjectPath(), getInterfaceName() , signal, this, slot);
}

bool SystemBusInterface::hasReplied(const QDBusMessage &message) {
    return message.type() == QDBusMessage::ReplyMessage;
}
