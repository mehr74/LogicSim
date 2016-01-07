#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "gate.h"

class Connector : public Gate
{
  public:
    Connector(Wire * in, Wire * out);
    virtual void Act();
    virtual string tostring() const;
    int InCount()   const {return 1;}
    int OutCount()  const {return 1;}
    Wire * InWire(int n)   const {return myIn;}
    Wire * OutWire(int n)  const {return myOut;}
    Gate * clone();
  private:
    Wire * myIn;
    Wire * myOut;
};


#endif // CONNECTOR_H
