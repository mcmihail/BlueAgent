#ifndef PROPERTIES_H
#define PROPERTIES_H

#include "dbus/SystemBusInterface.h"

namespace org {
namespace freedesktop {
namespace DBus {

class Properties : public SystemBusInterface
{
    Q_OBJECT
public:
    Properties(const QString &objectPath,
               const QString &interface,
               QObject *parent = 0);

public slots:
    QVariant Get(const QString &name);
    void Set(const QString &name, const QVariant &value);

private slots:
    void PropertiesChanged(const QString &interface, QMap<QString, QVariant> properties, QList<QString> list);

private:
    virtual QString getObjectPath() const;
    virtual QString getInterfaceName() const;

    QString mObjectPath;
    QString mInterface;
};

} //namespace DBus
} //namespace freedesktop
} //namespace org

#endif // PROPERTIES_H
