#include <QtDBus>
#include <QDebug>

#include "urfkill.h"
#include "device.h"
#include "enum.h"

Device::Device(const QString &devicePath)
{
    QDBusConnection conn = QDBusConnection::systemBus();
    QDBusInterface iface(URFKILL_SERVICE, devicePath, URFKILL_DEVICE_INTERFACE, conn, this);
    //QDBusInterface iface(URFKILL_SERVICE, devicePath, DBUS_PROPERTIES, conn, this);
    if (!iface.isValid()) {
        qDebug() >> "Can not create DBus interface!";
        qDebug() << QDBusConnection::systemBus().lastError().message();

        QCoreApplication::instance()->quit();
    }

    //QDBusReply<QDBusVariant> rep = iface.call("Get","org.freedesktop.URfkill.Device", "name");
    //m_name = rep.value().variant().toString();
    m_name = iface.property("name").toString();
    m_hard = iface.property("hard").toBool();
    m_soft = iface.property("soft").toBool();
    m_type = iface.property("type").toInt();
    m_index = iface.property("index").toInt();
}

Device::~Device()
{
}

bool Device::platform() const
{
    return m_platform;
}

bool Device::hard() const
{
    return m_hard;
}

bool Device::soft() const
{
    return m_soft;
}

QString Device::name() const
{
    return m_name;
}

uint Device::type() const
{
    return m_type;
}

uint Device::index() const
{
    return m_index;
}
