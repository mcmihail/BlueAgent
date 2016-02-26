#ifndef PLUGIN_H
#define PLUGIN_H

#include <QObject>

class Plugin : public QObject
{
    Q_OBJECT
public:
    explicit Plugin(const QString &name, QObject *parent = 0);

    /*!
     * \brief init called to initilize the plugin. If this fail, the plugin will not be used.
     * \return true if the initialization was successfull, false otherwise.
     */
    virtual bool init() = 0;

protected:
    QString mName;
    void *mLibrary;
};


#endif // PLUGIN_H
