#ifndef __DEVICE_H
#define __DEVICE_H

#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtDBus/QDBusInterface>

#include "enum.h"

class Device
{
    public:
    Device(const QString &devicePath);
    ~Device();

    bool platform() const;
    bool hard() const;
    bool soft() const;
    QString name() const;
    uint type() const;
    uint index() const;
private:
    bool m_platform;
    bool m_hard;
    bool m_soft;
    QString m_name;
    uint m_type;
    uint m_index;
};

#endif
