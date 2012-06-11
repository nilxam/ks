#include <QApplication>
#include <QDebug>
#include <QtDBus>
#include <QList>
#include <QDBusObjectPath>

#include "device.h"
#include "killswitch.h"
#include "test.h"
#include "client.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Device *device = new Device("/org/freedesktop/URfkill/devices/1");
    Killswitch *ks = new Killswitch(URF_ENUM_TYPE_BLUETOOTH);
    Test *test = new Test;
    //QObject::connect(device, SIGNAL(triggerPropertyChanged()), test, SLOT(gotDeviceChanged()));
    QObject::connect(ks, SIGNAL(triggerStateChanged()), test, SLOT(gotKillswitchChanged()));
    Client *client = new Client;
    if (argv[1])
        client->setBlockIdx(1,true);
    else
        client->setBlockIdx(1,false);

    QList<QDBusObjectPath> devices = client->enumerateDevices();
    qDebug() << "Found " << devices.count() << " devices!!";
    foreach(QDBusObjectPath udi, devices) {
        Device *device = new Device(udi.path());
        QObject::connect(device, SIGNAL(triggerPropertyChanged()), test, SLOT(gotDeviceChanged()));
        qDebug() << "index: " << device->index() << " hard: " << device->hard() << " soft: " << device->soft();
        qDebug() << "Found the device:" << udi.path();
    }

    app.exec();
}
