#ifndef INVERTER_H
#define INVERTER_H

#include "model/model.h"

class Inverter : public Gate
{
  public:
    Inverter(Wire * in, Wire * out, const string& name="");
    Inverter(const string& name="");
    virtual void Act( );
    virtual string tostring() const;

    int InCount()  const {return 1;}
    int OutCount() const {return 1;}
    Wire * InWire(int n)  const {return myIn;}
    Wire * OutWire(int n) const {return myOut;}
    Gate * clone();

    virtual string deepString() const;

  private:
    Wire * myIn;
    Wire * myOut;
    string myName;
    int    myNumber;
    static int ourCount;
};

#endif // INVERTER_H
