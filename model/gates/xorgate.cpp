#include <iostream>
#include <sstream>
using namespace std;
#include "xorgate.h"


int XorGate::ourCount = 0;

XorGate::XorGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

XorGate::XorGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}

Gate * XorGate::clone()
{
    return new XorGate(myName);
}


void XorGate::Act( )
{
    myOuts[0]->SetSignal(((!myIns[0]->GetSignal()) && myIns[1]->GetSignal())
                        ||(myIns[0]->GetSignal() && (!myIns[1]->GetSignal())));
}

string XorGate::tostring() const
{
    ostringstream out;
    out << "xor (" << myNumber << ") " << myName;
    return out.str();
}

