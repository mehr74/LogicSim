#include "orgate.h"
#include <sstream>

int OrGate::ourCount = 0;

OrGate::OrGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

OrGate::OrGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}


void OrGate::Act( )
{
    myOuts[0]->SetSignal(myIns[0]->GetSignal() || myIns[1]->GetSignal());
}

string OrGate::tostring() const
{
    ostringstream out;
    out << "or (" << myNumber << ") " << myName;
    return out.str();
}

Gate * OrGate::clone()
{
    return new OrGate(myName);
}
