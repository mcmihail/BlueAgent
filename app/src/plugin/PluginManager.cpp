#include "plugin/PluginManager.h"
#include "plugin/LifeCyclePlugin.h"
#include <QString>
#include <QCoreApplication>

PluginManager::PluginManager(QObject *parent) :
    QObject(parent)
{
    QString library;
//    library.append(mSettings.getPluginsPath()).append(mSettings.getClosingPluginName()).append("/lib").append(mSettings.getClosingPluginName()).append(".so");
    mLifeCyclePlugin = new LifeCyclePlugin(library);
    if(NULL != mLifeCyclePlugin) {
        mLifeCyclePlugin->init();
    } else {
        QCoreApplication::exit(-1);
    }
}

PluginManager::~PluginManager() {
    if(NULL != mLifeCyclePlugin) {
        delete mLifeCyclePlugin;
    }
}

void PluginManager::addPlugin(Plugin *p)
{
    if(NULL != p) {
        mManagedPlugins.append(p);
    }
}
