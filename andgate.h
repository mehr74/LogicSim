#ifndef ANDGATE_H
#define ANDGATE_H

#include <iostream>
#include <string>
#include <vector>
#include "gates.h"
using namespace std;

class Wire;
class Gate;


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
