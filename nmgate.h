#ifndef NMGATE_H
#define NMGATE_H

#include "gate.h"

class NMGate : public Gate
{
  public:

    virtual void Act( ) = 0;
    virtual string tostring() const = 0;

    int InCount()  const {return myIns.size();}
    int OutCount() const {return myOuts.size();}

    Wire * InWire(int n)  const {return myIns[n];}
    Wire * OutWire(int n) const {return myOuts[n];}

    virtual string deepString() const;

  protected :

    NMGate(int number=0, const string& name="generic");

    void Init(const vector<Wire *>& in, const vector<Wire *>& out);
    vector<Wire *> myIns;
    vector<Wire *> myOuts;
    int    myNumber;
    string myName;
};

#endif // NMGATE_H
