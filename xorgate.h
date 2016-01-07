#ifndef XORGATE_H
#define XORGATE_H

#include "nmgate.h"

class XorGate : public NMGate
{
  public:
    XorGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    XorGate(const string& name="");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};

#endif // XORGATE_H
