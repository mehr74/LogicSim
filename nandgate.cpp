#include <iostream>
#include <sstream>
using namespace std;
#include "nandgate.h"
#include "wires.h"

int NandGate::ourCount = 0;

NandGate::NandGate(Wire * in, Wire* in2, Wire * out, const string& name)
  : NMGate(ourCount, name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = in;
    ins[1] = in2;
    outs[0] = out;
    NMGate::Init(ins,outs);
    ourCount++;
}

NandGate::NandGate(const string& name)
  : NMGate(ourCount,name)
{
    vector<Wire *> ins(2), outs(1);
    ins[0] = ourWireFactory->MakeWire(myName);
    ins[1] = ourWireFactory->MakeWire(myName);
    outs[0] = ourWireFactory->MakeWire(myName);
    NMGate::Init(ins,outs);
    ourCount++;
}

Gate * NandGate::clone()
{
    return new NandGate(myName);
}


void NandGate::Act()
{
    myOuts[0]->SetSignal(!(myIns[0]->GetSignal() && myIns[1]->GetSignal()));
}

string NandGate::tostring() const
{
    ostringstream out;
    out << "nand (" << myNumber << ") " << myName;
    return out.str();
}
