#include "bit.h"
#include <sstream>

int Bit::ourCount = 0;

Bit::Bit(bool value, Wire* out, const string& name)
  : myValue(value), myOut(out), myName(name), myNumber(ourCount)
{
    ourCount++;
}

Bit::Bit(bool value, const string& name)
  : myValue(value),
    myOut(ourWireFactory->MakeWire(name)),
    myName(name),
    myNumber(ourCount)
{
    ourCount++;
    myOut->AddGate(this);
}

void Bit::Act()
{
    myOut->SetSignal(myValue);
}

string Bit::tostring() const
{
    ostringstream out;
    out << "bit (" << myNumber << ") " << myName;
    return out.str();
}

Gate * Bit::clone()
{
    return new Bit(myValue ,myName);
}

string Bit::deepString() const
{
    ostringstream out;
    out << *this << "\n\tout" << *myOut;
    out << "\n----";
    return out.str();
}
