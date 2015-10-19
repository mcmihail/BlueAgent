#ifndef LIFECYCLEPROTOCOL
#define LIFECYCLEPROTOCOL

#define EXPORT_C    extern "C" __attribute__((visibility("default")))

/*!
 * \brief The LifeCycleHook struct is used by the plugin to
 * control the application.
 */
struct LifeCycleHook {
    void (* start)();
    void (* pause)();
    void (* stop)();
};

/*!
 * \brief createPluging is used to pass the hook to the plugin
 * and instruct the plugin to call it's internal initialisation
 * procedures
 * \param hook - the hook to be used by the plugin
 */
EXPORT_C void createPlugin(LifeCycleHook *hook);

/*!
 * \brief destroyPlugin is used to instruct the plugin to call it's
 * internal destruction procedures.
 */
EXPORT_C void destroyPlugin();

#endif // LIFECYCLEPROTOCOL

