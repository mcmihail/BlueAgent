#ifndef BLUEAGENT_H
#define BLUEAGENT_H

#include <QObject>

/*!
 * \brief The BlueAgent class - entry point for application
 */
class BlueAgent : public QObject
{
    Q_OBJECT
public:
    static void usage();
};

#endif // BLUEAGENT_H
