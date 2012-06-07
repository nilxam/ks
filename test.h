#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    Test(); 
public Q_SLOTS:
    void gotDeviceChanged();
    void gotKillswitchChanged();

    void gotDeviceAdded(QString device);
    void gotDeviceChanged(QString device);
    void gotDeviceRemoved(QString device);
};
