### UnixSignalHandlerPlugin

This plugin implements the [LifeCycleProtocol](https://github.com/mcmihail/BlueAgent/blob/dev/pub/LifeCycleProtocol.h) in order to control the BlueAgent app. It's main focus is on stopping the app using Unix signals `SIGINT` and `SIGTERM`. The other two methods: `start()` and `pause()` are not implemented since this plugin serves also as an example and it does not intended to provide full functionality (... at least for the moment).

For more information about unix signals please refer to the following link:
 - [Man7.org Signal Man Page](http://man7.org/linux/man-pages/man7/signal.7.html)
