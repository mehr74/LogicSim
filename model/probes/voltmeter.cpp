#include "voltmeter.h"

VoltMeter::VoltMeter(Wire * w)
  : myWire(w)
{
    myWire->AddGate(this);
}

void VoltMeter::Act()
{
    cout << *myWire << "\t signal= " << myWire->GetSignal() << endl;
}
string VoltMeter::tostring() const
{
    return "voltmeter " + myWire->tostring();
}

