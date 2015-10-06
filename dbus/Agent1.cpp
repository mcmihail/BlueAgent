#include "dbus/Agent1.h"
#include <QDebug>

namespace org {
namespace bluez {

Agent1::Agent1(QObject *parent) :QObject(parent) {
}

const QString Agent1::OBJECT_PATH = "/agent";

void Agent1::Release() {
}

QString Agent1::RequestPinCode(QDBusObjectPath device) {
    qDebug() << "Agent1::RequestPinCode method was called";
    qDebug() << device.path();
    return "0000";
}

void Agent1::DisplayPinCode(QDBusObjectPath device,
                            QString pincode) {
    qDebug() << "Agent1::DisplayPinCode method was called";
    qDebug() << device.path();
    qDebug() << pincode;
}

quint32 Agent1::RequestPasskey(QDBusObjectPath device) {
    qDebug() << "Agent1::RequestPasskey method was called";
    qDebug() << device.path();
    return 0;
}

void Agent1::DisplayPasskey(QDBusObjectPath device,
                            quint32 passkey,
                            quint16 entered) {
    qDebug() << "Agent1::DisplayPasskey method was called";
    qDebug() << device.path();
    qDebug() << passkey;
    qDebug() << entered;
}

void Agent1::RequestConfirmation(QDBusObjectPath device,
                                 quint32 passkey) {
    qDebug() << "Agent1::RequestConfirmation method was called";
    qDebug() << device.path();
    qDebug() << passkey;
}

void Agent1::RequestAuthorization(QDBusObjectPath device) {
    qDebug() << "Agent1::RequestAuthorization method was called";
    qDebug() << device.path();
}

void Agent1::AuthorizeService(QDBusObjectPath device,
                              QString uuid) {
    qDebug() << "Agent1::AuthorizeService method was called";
    qDebug() << device.path();
    qDebug() << uuid;

}

void Agent1::Cancel() {
    qDebug() << "Agent1::Cancel method was called";
}


} //namespace bluez
} //namespace org

