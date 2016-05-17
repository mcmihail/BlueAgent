#ifndef SYSTEMBUSINTERFACE_H
#define SYSTEMBUSINTERFACE_H

#include <QObject>
#include <QDBusMessage>

/*!
 * \brief The SystemBusInterface class - abstract class for a dbus interface
 * exposed on System Bus
 */
class SystemBusInterface : public QObject
{
    Q_OBJECT
public:
    /*!
     * \brief SystemBusInterface - constructs a new systembus interface
     * \param parent - the parent of the constructed object
     */
    SystemBusInterface(QObject *parent = 0);

protected:
    QDBusMessage call(const QString &methodName);
    QDBusMessage call(const QString &methodName, QVariantList arguments);
    bool connect(const QString &signal, QObject *receiver, const char* slot);
    bool hasReplied(const QDBusMessage &message);

    /*!
     * \brief getServiceName - method to get the service name,
     *  since we connect to one server we overload the function
     *  only where it makes sense
     * \return "org.bluez"
     */
    virtual QString getServiceName() const;

private:
    /*!
     * \brief getObjectPath - method to return the object path of the
     *  dbus interface
     * \return the object path
     */
    virtual QString getObjectPath() const = 0;


    virtual QString getInterfaceName() const = 0;
};

#endif // SYSTEMBUSINTERFACE_H
