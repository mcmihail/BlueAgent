#ifndef AGENTMANAGER1_H
#define AGENTMANAGER1_H

#include <QObject>
#include <QDBusObjectPath>

namespace org {
namespace bluez {

class AgentManager1 : public QObject
{
    Q_OBJECT
public:
    explicit AgentManager1(QObject *parent = 0);

    void RegisterAgent(QDBusObjectPath agent, QString capability);
    void UnregisterAgent(QDBusObjectPath agent);

private:
    static const QString SERIVCE_NAME;
    static const QString INTERFACE_NAME;
    static const QString OBJECT_PATH;
};

} // namespace bluez
} // namespace org
#endif // AGENTMANAGER1_H
