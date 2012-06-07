#include <QDebug>

#include "test.h"

Test::Test()
{

}

void Test::gotDeviceChanged()
{
    qDebug() << "device property changed!";
}

void Test::gotKillswitchChanged()
{
    qDebug() << "killswitch state changed!";
}

void Test::gotDeviceAdded(QString device)
{
    qDebug() << "device " << device << " added!";
}

void Test::gotDeviceChanged(QString device)
{
    qDebug() << "device " << device << " changed!";
}

void Test::gotDeviceRemoved(QString device)
{
    qDebug() << "device " << device << " removed!";
}
