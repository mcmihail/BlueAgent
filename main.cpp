#include <QCoreApplication>
#include "dbus/Agent1.h"
#include "dbus/AgentManager1.h"
#include <QtDBus/QDBusConnection>
#include <QDebug>
#include "agent1_adaptor.h"
#include "BlueAgent.h"

using namespace org;
using namespace bluez;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    BlueAgent lAgent(&a);
    lAgent.init();

    Agent1 a1(&a);

    QDBusConnection connection = QDBusConnection::sessionBus();
    if (connection.isConnected()) {
        new Agent1Adaptor(&a1);
        AgentManager1 am(&a);
        am.RegisterAgent(QDBusObjectPath(a1.OBJECT_PATH), "DisplayYesNo");
        am.RegisterAgent(QDBusObjectPath(a1.OBJECT_PATH), "DisplayYesNo");
        am.UnregisterAgent(QDBusObjectPath(a1.OBJECT_PATH));
        am.UnregisterAgent(QDBusObjectPath(a1.OBJECT_PATH));
        qDebug() << (connection.registerObject("/", &a1) ? "Registered Object" : "Failed to Register Object");
        qDebug() << (connection.registerService("org.test.Agent1") ? "Registered Service" : "Failed to Register Service");
    } else {
        qDebug() << "Failed to connect to session bus!";
    }


    return a.exec();
}

