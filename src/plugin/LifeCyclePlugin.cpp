#include "plugin/LifeCyclePlugin.h"
#include <dlfcn.h>
#include <QCoreApplication>

LifeCyclePlugin::LifeCyclePlugin(const QString &name) : Plugin(name) {
    mHook = new LifeCycleHook();
    mHook->stop = &LifeCyclePlugin::closeCallback;
}

LifeCyclePlugin::~LifeCyclePlugin() {
    if(mHook)
        delete mHook;
    if(mDestroyPlugin)
        (*mDestroyPlugin)();
}

void LifeCyclePlugin::closeCallback() {
    QCoreApplication::exit();
}

bool LifeCyclePlugin::init() {

    if(mLibrary != NULL) {
        mCreatePlugin = (void (*)(LifeCycleHook *)) dlsym(mLibrary, "createPlugin");
        mDestroyPlugin = (void (*)()) dlsym(mLibrary, "destroyPlugin");
    }

    if(mCreatePlugin != NULL) {
        (*mCreatePlugin)(mHook);
    }

    return (mLibrary && mCreatePlugin && mDestroyPlugin);
}
