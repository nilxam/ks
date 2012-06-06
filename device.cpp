#include <QtDBus>
#include <QDebug>

#include "urfkill.h"
#include "device.h"
#include "enum.h"

Device::Device(const QString &devicePath)
{
    QDBusConnection conn = QDBusConnection::systemBus();
    QDBusInterface *iface = new QDBusInterface(URFKILL_SERVICE, devicePath, DBUS_PROPERTIES, conn);

    if (!iface->isValid()) {
        qDebug() << "no pass";
        qDebug() << QDBusConnection::systemBus().lastError().message();
        return;
    } else {
        qDebug() << "pass";
    }
    QDBusReply<QString> rep = iface->call("Get", URFKILL_DEVICE_INTERFACE, "name");
    if (rep.isValid())
        qDebug() << "not null";
    m_name = rep.value();
    //m_hard = iface.property("hard").toBool();
    //m_soft = iface.property("soft").toBool();
    //m_name = iface.property("name").toString();
    //m_type = iface.property("type").toInt();
    //m_index = iface.property("index").toInt();
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
