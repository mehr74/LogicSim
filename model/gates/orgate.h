#ifndef ORGATE_H
#define ORGATE_H

#include "nmgate.h"

class OrGate : public NMGate
{
  public:
    OrGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    OrGate(const string& name = "");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};

#endif // ORGATE_H
