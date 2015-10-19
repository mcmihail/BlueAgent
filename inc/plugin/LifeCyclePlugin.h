#ifndef LIFECYCLEPLUGIN_H
#define LIFECYCLEPLUGIN_H

#include "plugin/Plugin.h"
#include "LifeCycleProtocol.h"

class LifeCyclePlugin : public Plugin {
public:
    LifeCyclePlugin(const QString &name);
    ~LifeCyclePlugin();

    virtual bool init();
private:
    void (*mCreatePlugin)(LifeCycleHook *);
    void (*mDestroyPlugin)();

    static void closeCallback();

    LifeCycleHook *mHook;
};

#endif // LIFECYCLEPLUGIN_H

