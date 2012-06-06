#include <QtCore/QCoreApplication>
#include <QtCore/QDebug>
#include <QtDBus/QtDBus>

#include "device.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);

    if (!QDBusConnection::systemBus().isConnected()) {
        qDebug() << "Cannot connect to the D-Bus session bus.";
        return 1;
    }
    QString path = "/org/freedesktop/URfkill/device/1";
    Device *device = new Device(path);
    qDebug() << device->name();

    app.exec();
}
