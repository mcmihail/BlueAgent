#ifndef SYSTEMBUSINTERFACE_H
#define SYSTEMBUSINTERFACE_H

#include <QObject>
#include <QDBusMessage>

class SystemBusInterface : public QObject
{
    Q_OBJECT
public:
    SystemBusInterface(QObject *parent = 0);

protected:
    QDBusMessage call(const QString &methodName);
    QDBusMessage call(const QString &methodName, QVariantList arguments);
    bool connect(const QString &signal, const char* slot);
    bool hasReplied(const QDBusMessage &message);

private:
    virtual QString getServiceName() const = 0;
    virtual QString getObjectPath() const = 0;
    virtual QString getInterfaceName() const = 0;
};

#endif // SYSTEMBUSINTERFACE_H
