#include <QCoreApplication>
#include <QDebug>
#include <QtDBus>

#include "device.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    if (!QDBusConnection::systemBus().isConnected()) {
        qDebug() << "Cannot connect to the D-Bus session bus.";
        return 1;
    }

    Device *device = new Device("/org/freedesktop/URfkill/devices/0");
    qDebug() << device->name();
    qDebug() << device->hard();
    qDebug() << device->soft();
    qDebug() << device->index();
    qDebug() << device->type();
    qDebug() << device->platform();

    app.exec();
}
