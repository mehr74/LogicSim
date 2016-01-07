#include <iostream>
#include "connector.h"
using namespace std;

Connector::Connector(Wire * in, Wire * out)
  : myIn(in), myOut(out)
{
   in->AddGate(this);
}

void Connector::Act()
{
    myOut->SetSignal(myIn->GetSignal());
}

string Connector::tostring() const
{
    return "connector " + myIn->tostring() + " to " + myOut->tostring();
}

Gate * Connector::clone()
{
    return new Connector(myIn,myOut);
}
