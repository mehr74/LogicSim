#include <iostream>
#include <sstream>
using namespace std;
#include "andgate.h"


int AndGate::ourCount = 0;

AndGate::AndGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

AndGate::AndGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}

Gate * AndGate::clone()
{
    return new AndGate(myName);
}


void AndGate::Act( )
{
    myOuts[0]->SetSignal(myIns[0]->GetSignal() && myIns[1]->GetSignal());
}

string AndGate::tostring() const
{
    ostringstream out;
    out << "and (" << myNumber << ") " << myName;
    return out.str();
}
