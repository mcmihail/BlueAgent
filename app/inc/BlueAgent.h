#ifndef BLUEAGENT_H
#define BLUEAGENT_H

#include <QObject>
#include "settings/Settings.h"

class BlueAgent : public QObject
{
    Q_OBJECT
public:
    explicit BlueAgent(QObject *parent = 0);

    // this is where the loading of all modules will take place
    void init();

    //this will unload the modules
    void deinit();

private:
    Settings mSettings;
//    ClosingPlugin mClosingPlugin;
};

#endif // BLUEAGENT_H
