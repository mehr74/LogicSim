#ifndef ANDGATE_H
#define ANDGATE_H

#include "nmgate.h"

class AndGate : public NMGate
{
  public:
    AndGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    AndGate(const string& name="");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};

#endif // ANDGATE_H
