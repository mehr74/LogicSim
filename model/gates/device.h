#ifndef DEVICE_H
#define DEVICE_H

#include <QObject>
#include <iostream>
#include <string>
#include <vector>
#include "model/wires/wires.h"

class Device : public QObject
{
  public:
    virtual ~Device() {}
    virtual void Act() = 0;
    virtual string tostring() const = 0;
    virtual int InCount()  const = 0;
    virtual int OutCount() const = 0;
    virtual Wire * InWire(int n)  const = 0;
    virtual Wire * OutWire(int n) const = 0;
    virtual Gate * clone() = 0;

    virtual string deepString() const {return tostring();}
};

#endif // DEVICE_H
