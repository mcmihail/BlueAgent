#include "BlueAgent.h"
#include <QDebug>
#include "plugin/LifeCyclePlugin.h"

BlueAgent::BlueAgent(QObject *parent) :
    QObject(parent),
    mSettings(parent) {
}

void BlueAgent::init() {
    qDebug() << "Closing plugin:" << mSettings.getClosingPluginName();
    LifeCyclePlugin *p = new LifeCyclePlugin(mSettings.getClosingPluginName());
    p->init();
}
