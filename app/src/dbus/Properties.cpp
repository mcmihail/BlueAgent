#include "Properties.h"
#include <QDebug>
#include <QDBusArgument>
#include <QDBusVariant>
#include <QDBusConnection>

namespace org {
namespace freedesktop {
namespace DBus {

Properties::Properties(const QString &objectPath,
                       const QString &interface,
                       QObject *parent)
    : SystemBusInterface(parent),
      mObjectPath(objectPath),
      mInterface(interface)
{
   qDebug() << "Connected" <<
               QDBusConnection::systemBus().connect(getServiceName(), getObjectPath(), getInterfaceName(), "PropertiesChanged", this, SLOT(PropertiesChanged(QString,QMap<QString,QVariant>,QList<QString>)));

}

QVariant Properties::Get(const QString &name) {
    QVariantList args;
    args.append(mInterface);
    args.append(name);

    QDBusMessage reply = call("Get", args);
    qDebug() << reply;

    if(reply.type() == QDBusMessage::ReplyMessage) {
        QVariant container = reply.arguments().at(0);
        QDBusVariant wrapper = container.value<QDBusVariant>();

        return wrapper.variant();
    }
    return QVariant("Invalid");
}

void Properties::Set(const QString &name, const QVariant &value) {
    QVariantList args;
    QDBusVariant dbusValue (value);

    args.append(mInterface);
    args.append(name);
    args.append(QVariant::fromValue(dbusValue));

    QDBusMessage reply = call("Set", args);

    qDebug() << reply;

    if(reply.type() == QDBusMessage::ReplyMessage) {

    }

}

void Properties::PropertiesChanged(const QString &interface, QMap<QString, QVariant> properties, QList<QString> list)
{
    qDebug() << "It works";
}

QString Properties::getObjectPath() const {
    return mObjectPath;
}

QString Properties::getInterfaceName() const {
    return "org.freedesktop.DBus.Properties";
}

} //namespace DBus
} //namespace freedesktop
} //namespace org


