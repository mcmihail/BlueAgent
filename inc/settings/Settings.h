#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);

    void resetToDefaultValues();
    QString getClosingPluginName();
    void setClosingPluginName(const QString &name);

private:
    void setDefaultValues();

    static const QString DEFAULT_FILE;

    QSettings mSettings;
};

#endif // SETTINGS_H
