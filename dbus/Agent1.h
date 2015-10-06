#ifndef AGENT1_H
#define AGENT1_H

#include <QObject>
#include <QtDBus/QDBusObjectPath>

namespace org {
namespace bluez {

class Agent1 : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.bluez.Agent1")
public:
    explicit Agent1(QObject *parent = 0);
    static const QString OBJECT_PATH;

public slots:
    void Release();
    QString RequestPinCode(QDBusObjectPath device);
    void DisplayPinCode(QDBusObjectPath device,
                        QString pincode);
    quint32 RequestPasskey(QDBusObjectPath device);
    void DisplayPasskey(QDBusObjectPath device,
                        quint32 passkey,
                        quint16 entered);
    void RequestConfirmation(QDBusObjectPath device,
                             quint32 passkey);
    void RequestAuthorization(QDBusObjectPath device);
    void AuthorizeService(QDBusObjectPath device,
                          QString uuid);
    void Cancel();

private:
};

} //namespace bluez
} //namespace org
#endif // AGENT1_H
