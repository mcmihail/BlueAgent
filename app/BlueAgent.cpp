#include <QCoreApplication>
#include <QDebug>
#include <BlueAgent.h>

void BlueAgent::usage()
{
    qDebug() << "BlueAgent [OPTIONS]\n";
    qDebug() << "OPTIONS:";
    qDebug() << "\t-h,\t--help\t- This helpfull message";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int exitCode = 0;
    bool shouldRun = true;
    foreach(QString arg, QCoreApplication::arguments()) {
        if(arg.compare("-h") == 0 ||
                arg.compare("--help") == 0) {
            BlueAgent::usage();
            shouldRun = false;
        }
    }

    if(shouldRun)
    {
        BlueAgent agent;
        //For the moment we are not using this agent
        Q_UNUSED(agent);
        exitCode = a.exec();
    }
    return exitCode;
}
