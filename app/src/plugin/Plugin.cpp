#include "inc/plugin/Plugin.h"
#include <dlfcn.h>
#include <QDebug>

Plugin::Plugin(const QString &name, QObject *parent) :
    QObject(parent),
    mName(name),
    mLibrary(NULL) {
    if(mLibrary == NULL) {
        mLibrary = dlopen(name.toStdString().c_str(), RTLD_LAZY);
    }

    if(mLibrary == NULL) {
        qDebug() << "Failed to open library";
    }
}

