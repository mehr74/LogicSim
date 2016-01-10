#ifndef _GATES_H
#define _GATES_H

#include <iostream>
#include <string>
#include <vector>
#include "model/wires/wires.h"
using namespace std;
class WireFactory;
class Gate
{
  public:
    virtual ~Gate() {}
    virtual void Act() = 0;
    virtual string tostring() const = 0;
    virtual int InCount()  const = 0;
    virtual int OutCount() const = 0;
    virtual Wire * InWire(int n)  const = 0;
    virtual Wire * OutWire(int n) const = 0;
    virtual Gate * clone() = 0;

    virtual string deepString() const {return tostring();}

    static Wire * WireByNumber(int num);

  protected:
    static WireFactory * ourWireFactory;
};

ostream& operator << (ostream& out, const Gate& g);

void Connect(Wire * w1, Wire * w2);

#endif
