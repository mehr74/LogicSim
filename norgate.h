#ifndef NORGATE_H
#define NORGATE_H

#include "nmgate.h"

class NorGate : public NMGate
{
  public:
    NorGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    NorGate(const string& name="");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};

#endif // NORGATE_H
