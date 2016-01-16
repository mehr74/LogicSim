#include "voltmeter.h"

int VoltMeter::ourCount = 0;

VoltMeter::VoltMeter(Wire * w)
  : myWire(w), myNumber(ourCount)
{
    myWire->AddGate(this);
    ourCount++;
}

void VoltMeter::Act()
{
    cout << *myWire << "\t signal= " << myWire->GetSignal() << endl;
    emit signalChanged(myWire->GetSignal(), myNumber);
}

string VoltMeter::tostring() const
{
    return "voltmeter " + myWire->tostring();
}

