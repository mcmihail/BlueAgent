#include "LifeCycleProtocol.h"
#include <signal.h>

static LifeCycleHook *gHook = 0;

static void closeHandler(int signal) {
    if(gHook &&
            gHook->stop &&
            (SIGINT == signal || SIGTERM == signal)) {
        gHook->stop();
    }
}

void createPlugin(LifeCycleHook *hook) {
    gHook = hook;
    signal(SIGINT, closeHandler);
    signal(SIGTERM, closeHandler);
}

void destroyPlugin() {
    gHook = 0;
}

