#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "model/gates/gate.h"

class VoltMeter : public Gate
{
  public:
    VoltMeter (Wire * w);
    virtual void Act( );
    virtual string tostring() const;

    int InCount() const {return 1;}
    int OutCount() const {return 1;}
    Wire * InWire(int n) const {return myWire;}
    Wire * OutWire(int n) const {return myWire;}
    Gate * clone() {return this;}

  protected:
    Wire * myWire;

};

#endif // VOLTMETER_H
