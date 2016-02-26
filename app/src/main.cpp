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

    return a.exec();
}

