#include "voltmeter.h"

VoltMeter::VoltMeter()
  : myWire(ourWireFactory->MakeWire())
{
    myWire->AddGate(this);
}

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
    return "probe " + myWire->tostring();
}

