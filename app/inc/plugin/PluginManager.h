#ifndef PLUGINMANAGER_H
#define PLUGINMANAGER_H

#include <QList>
#include "settings/Settings.h"
#include "plugin/LifeCyclePlugin.h"


class PluginManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginManager(QObject *parent = 0);
    virtual ~PluginManager();

    virtual void addPlugin(Plugin *p);

private:
    Settings mSettings;

    LifeCyclePlugin *mLifeCyclePlugin;
    QList<Plugin *> mManagedPlugins;
};

#endif // PLUGINMANAGER_H
