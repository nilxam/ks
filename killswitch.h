#ifndef __KILLSWITCH_H
#define __KILLSWITCH_H

#include <QVariant>
#include <QString>

#include "enum.h"

class Killswitch
{
public:
    Killswitch(const QString &typePath);
    ~Killswitch();

    int state() const;
private:
    int m_state;
};

#endif
