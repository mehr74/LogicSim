#ifndef XNORGATE_H
#define XNORGATE_H

#include "nmgate.h"

class XnorGate : public NMGate
{
  public:
    XnorGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    XnorGate(const string& name="");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};


#endif // XNORGATE_H
