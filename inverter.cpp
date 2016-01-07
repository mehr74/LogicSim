#include "inverter.h"
#include <sstream>

int Inverter::ourCount = 0;

Inverter::Inverter(Wire* in, Wire* out, const string& name)
  : myIn(in), myOut(out), myName(name), myNumber(ourCount)
{
    ourCount++;
    in->AddGate(this);
}

Inverter::Inverter(const string& name)
  : myIn(ourWireFactory->MakeWire(name)),
    myOut(ourWireFactory->MakeWire(name)),
    myName(name),
    myNumber(ourCount)
{
    ourCount++;
    myIn->AddGate(this);
}

void Inverter::Act()
{
    myOut->SetSignal(! myIn->GetSignal());
}

string Inverter::tostring() const
{
    ostringstream out;
    out << "inv (" << myNumber << ") " << myName;
    return out.str();
}

Gate * Inverter::clone()
{
    return new Inverter(myName);
}

string Inverter::deepString() const
{
    ostringstream out;
    out << *this << "\n\tin" << *myIn << "\tout" << *myOut;
    out << "\n----";
    return out.str();
}


