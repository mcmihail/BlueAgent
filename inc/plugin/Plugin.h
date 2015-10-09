#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>

class Plugin : public QObject
{
    Q_OBJECT
public:
    explicit Plugin(const QString &name, QObject *parent = 0);

protected:
    QString mName;
    void *mLibrary;
};

#endif // PLUGIN_H
