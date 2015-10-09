#include "BlueAgent.h"
#include <QDebug>
#include "plugin/Plugin.h"

BlueAgent::BlueAgent(QObject *parent) :
    QObject(parent),
    mSettings(parent) {
}

void BlueAgent::init() {
    qDebug() << "Closing plugin:" << mSettings.getClosingPluginName();
    Plugin p(mSettings.getClosingPluginName());
}
