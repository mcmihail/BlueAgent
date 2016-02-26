#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "dbus/SystemBusInterface.h"
#include <QString>
#include <QDBusObjectPath>

typedef QMap<QString, QVariantMap> InterfaceList;
typedef QMap<QDBusObjectPath, InterfaceList> ManagedObjectList;

Q_DECLARE_METATYPE(InterfaceList)
Q_DECLARE_METATYPE(ManagedObjectList)

namespace org {
namespace freedesktop {
namespace DBus {

class ObjectManager : public SystemBusInterface
{
    Q_OBJECT
public:
    ObjectManager(QObject *parent = 0);

public slots:
    void GetManagedObjects();


private slots:
    void InterfacesAdded(InterfaceList);
    void getManagedObjectsCallback(ManagedObjectList objs);

private:
    virtual QString getServiceName() const;
    virtual QString getObjectPath() const;
    virtual QString getInterfaceName() const;


    static const QString OBJECT_PATH;
};

} //namespace DBus
} //namespace freedesktop
} //namespace org

#endif // OBJECTMANAGER_H
