#include <KCmdLineArgs>
#include <kuniqueapplication.h>
#include <KAboutData>
#include <KDebug>

#include <liburfkill-qt/device.h>
#include <liburfkill-qt/killswitch.h>
#include <liburfkill-qt/client.h>

#include "test.h"

int main(int argc, char *argv[])
{
    KAboutData aboutData("ks", "ks", ki18n("ks"), "0.1", ki18n("ks is an frontend graphic tool for URfkill"),
            KAboutData::License_GPL, ki18n("(c) 2012, Max Lin"));

    aboutData.addAuthor(ki18n("Max Lin"), ki18n("Developer"), "max.lin@gmx.com", "http://maxlin.tumblr.com");

    KCmdLineArgs::init(argc, argv, &aboutData);

    KUniqueApplication app;
    app.setQuitOnLastWindowClosed(false);

    if (!Client::isUrfkillRunning()){
        kDebug() << "URfkill Daemon not running!";

        kDebug() << "Try to start URfkill daemon...";
        Client::daemonLaunch();
        kDebug() << "Please re-launch program!";
        exit(1);
    }   

    Client *client = new Client;
    Killswitch *ks = new Killswitch(URF_ENUM_TYPE_BLUETOOTH);
    Test *test = new Test;
    QObject::connect(ks, SIGNAL(triggerStateChanged()), test, SLOT(gotKillswitchChanged()));

    QList<QDBusObjectPath> devices = client->enumerateDevices();
    kDebug() << "Found " << devices.count() << " devices!!";
    foreach(QDBusObjectPath udi, devices) {
        Device *device = new Device(udi.path());
        QObject::connect(device, SIGNAL(triggerPropertyChanged()), test, SLOT(gotDeviceChanged()));
        kDebug() << "index: " << device->index() << " hard: " << device->hard() << " soft: " << device->soft();
        kDebug() << "Found the device:" << udi.path();
    }

    return app.exec();
}
