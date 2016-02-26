#include "ObjectManager.h"
#include <QDBusConnection>
#include <QDebug>
#include <QDBusMessage>
#include <QDBusArgument>
#include <QDBusMetaType>

namespace org {
namespace freedesktop {
namespace DBus {

const QString ObjectManager::OBJECT_PATH = "/";

ObjectManager::ObjectManager(QObject *parent) : SystemBusInterface(parent)
{
    qDBusRegisterMetaType<InterfaceList>();
    qDBusRegisterMetaType<ManagedObjectList>();

    bool connected = connect("InterfacesAdded",SLOT(InterfacesAdded(QDBusObjectPath,QVariantMap)));
    qDebug() << "Connected to ObjectManager: " << (connected ? "YES" : "NO");
}

void ObjectManager::GetManagedObjects() {
    QDBusMessage msg = QDBusMessage::createMethodCall(getServiceName(), getObjectPath(), getInterfaceName(),"GetManagedObjects");
    QDBusConnection::systemBus().callWithCallback(msg, this, SLOT(getManagedObjectsCallback));

//    qDebug() << reply;

//    if(hasReplied(reply)){
//        if(!reply.arguments().isEmpty()) {
//            QVariant first = reply.arguments().at(0);

//            const QDBusArgument &arg    = first.value<QDBusArgument>();

//            QMap<QDBusObjectPath,QVariant> big;
//            arg.beginMap();
//            while ( !arg.atEnd() ) {
//                QDBusObjectPath path;
//                QVariantMap arg1;

//                arg.beginMapEntry();
//                arg >> path >> arg1;
//                arg.endMapEntry();
//                big.insert(path, arg1);

//                qDebug() << ">>>> " << path.path();
//                qDebug() << ">>>> " << arg1;



//                if(arg1.contains("org.bluez.Adapter1")) {

//                    qDebug() << arg1.value("org.bluez.Adapter1");
//                }
////                foreach (QVariant key , arg1) {
////                    qDebug() << key;

////                }
//            }

//        }
//    }
//    else
//    {
//        qDebug() << "Buba";
//    }
}


void ObjectManager::InterfacesAdded(InterfaceList) {
    qDebug() << "Interface added";
}

void ObjectManager::getManagedObjectsCallback(ManagedObjectList objs) {
    foreach (QDBusObjectPath path, objs.keys())
        qDebug() << path.path();
}

QString ObjectManager::getServiceName() const {
    return "org.bluez";
}

QString ObjectManager::getObjectPath() const {
    return "/";
}

QString ObjectManager::getInterfaceName() const {
    return "org.freedesktop.DBus.ObjectManager";
}


} //namespace DBus
} //namespace freedesktop
} //namespace org
