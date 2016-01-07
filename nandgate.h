#ifndef NANDGATE_H
#define NANDGATE_H

#include "nmgate.h"

class NandGate : public NMGate
{
  public:
    NandGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    NandGate(const string& name="");
    virtual void Act();
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};


#endif // NANDGATE_H
