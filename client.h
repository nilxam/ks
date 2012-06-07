#ifndef __CLIENT_H
#define __CLIENT_H

#include <QDBusInterface>
#include <QDBusObjectPath>
#include <QString>
#include <QList>

class Client : public QObject
{
    Q_OBJECT
public:
    Client();
    ~Client();

    bool setBlock(uint type, bool block);
    bool setBlockIdx(uint index, bool block);
    QList<QDBusObjectPath> enumerateDevices() const;
    bool keyControl() const;
    QString daemonVersion() const;
    uint deviceCount() const;
Q_SIGNALS:
    void deviceAdded(QString device);
    void deviceChanged(QString device);
    void deviceRemoved(QString device);
    void urfkeyPressed(int key);
protected:
    QDBusInterface *clientIface;
private:
    void refreshDevicesData();

    bool m_keyControl;
    QString m_daemonVersion;
    QList<QDBusObjectPath> m_devicesList;
    uint m_deviceCount;
private Q_SLOTS:
    void on_clientIface_DeviceAdded(QString device);
    void on_clientIface_DeviceChanged(QString device);
    void on_clientIface_DeviceRemoved(QString device);
};

#endif /* __CLIENT_H */
