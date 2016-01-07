#include <iostream>
#include <sstream>
using namespace std;
#include "norgate.h"


int NorGate::ourCount = 0;

NorGate::NorGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

NorGate::NorGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}

Gate * NorGate::clone()
{
    return new NorGate(myName);
}


void NorGate::Act( )
{
    myOuts[0]->SetSignal(!(myIns[0]->GetSignal() || myIns[1]->GetSignal()));
}

string NorGate::tostring() const
{
    ostringstream out;
    out << "nor (" << myNumber << ") " << myName;
    return out.str();
}
