#include <iostream>
#include <sstream>
using namespace std;
#include "xnorgate.h"


int XnorGate::ourCount = 0;

XnorGate::XnorGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

XnorGate::XnorGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}

Gate * XnorGate::clone()
{
    return new XnorGate(myName);
}


void XnorGate::Act( )
{
    myOuts[0]->SetSignal(((!myIns[0]->GetSignal()) && myIns[1]->GetSignal())
                        ||(myIns[0]->GetSignal() && (!myIns[1]->GetSignal())));
}

string XnorGate::tostring() const
{
    ostringstream out;
    out << "xnor (" << myNumber << ") " << myName;
    return out.str();
}

