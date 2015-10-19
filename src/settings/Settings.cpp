#include "settings/Settings.h"
#include <QDebug>
#include <QCoreApplication>
#include <QStringList>

const QString Settings::DEFAULT_FILE = ".blueagent.conf";

typedef struct Tuple {
    QString key;
    QString defaultValue;
}Tuple;

static const Tuple PLUGIN_PATH = {"Path", "./plugins/"};
static const Tuple CLOSING_PLUGIN = { "Closing", "UnixSignalHandler" };


Settings::Settings(QObject *parent) :
    QObject(parent),
    mSettings(DEFAULT_FILE, QSettings::NativeFormat, parent)
{
    QStringList args = QCoreApplication::arguments();
    if(args.contains("--reset-settings")) {
        resetToDefaultValues();
    }

    if(mSettings.allKeys().empty()) {
        setDefaultValues();
    }
}

void Settings::resetToDefaultValues() {
    mSettings.clear();
    setDefaultValues();
}

void Settings::setDefaultValues() {

    mSettings.beginGroup("Plugins");
    mSettings.setValue(PLUGIN_PATH.key, CLOSING_PLUGIN.defaultValue);
    mSettings.setValue(CLOSING_PLUGIN.key, CLOSING_PLUGIN.defaultValue);
    mSettings.endGroup();
}

QString Settings::getClosingPluginName() {
    return mSettings.value(CLOSING_PLUGIN.key, CLOSING_PLUGIN.defaultValue)
            .toString();
}

void Settings::setClosingPluginName(const QString &name) {
    mSettings.setValue(CLOSING_PLUGIN.key, name);
}
