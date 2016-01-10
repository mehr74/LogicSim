#include <iostream>
#include <sstream>
using namespace std;
#include "wires.h"
#include "gates.h"


int Wire::ourCount = 0;

Wire::Wire(const string& name)
  : mySignal(false), myName(name), myNumber(ourCount)
{
    ourCount++;
}

Wire::~Wire()
{

}


bool Wire::GetSignal() const
{
    return mySignal;
}
string Wire::tostring() const
{
    ostringstream out;
    out << myName << " (wire " << myNumber << ")";
    return out.str();
}

ostream& operator << (ostream& out, const Wire& w)
{
    out << w.tostring();
    return out;
}

void Wire::SetSignal(bool signal)
{
    if (signal != mySignal)
    {   mySignal = signal;
        int k;
        for(k=0; k < myGates.size(); k++)
        {    myGates[k]->Act( );
        }
    }
}

void Wire::AddGate(Gate * g)
{
    myGates.push_back(g);
    g->Act();
}

int Wire::Number() const
{
    return myNumber;
}

void Wire::RemoveGate(Gate * g)
{
    int k;
    for(k=0; k < myGates.size(); k++)
    {   if (myGates[k] == g)
        {   myGates[k] = myGates[myGates.size() - 1];
            myGates.pop_back();
            return;
        }
    }
}

WireFactory::WireFactory()
{
}

WireFactory::~WireFactory()
{
    int k;
    for(k=0; k < myWires.size(); k++)
    {   //delete myWires[k];
    }
}

Wire * WireFactory::MakeWire(const string& name)
{
    Wire * w = new Wire(name);
    myWires.push_back(w);
    return w;
}

Wire * WireFactory::GetWire(int num) const
{   int k;
    for(k=0; k < myWires.size(); k++)
    {   if (myWires[k]->Number() == num) return myWires[k];
    }
    return 0;
}

ConnectorIterator::ConnectorIterator(Wire * w)
  : myWire(w),
    myConnector(0),
    myIndex(-1)
{

}

void ConnectorIterator::Init()
{
    myIndex = -1;
    Next();   // find first, starting after myIndex
}

bool ConnectorIterator::HasMore()
{
    return myConnector != 0;
}

void ConnectorIterator::Next()
{
    int k;
    myConnector = 0;
    for(k=myIndex+1; k < myWire->myGates.size(); k++)
    {
        Connector * c= dynamic_cast<Connector *> (myWire->myGates[k]);
        if (c != 0)
        {   myConnector = c;
            myIndex = k;
            break;
        }
    }
}

Connector * ConnectorIterator::Current()
{
    return myConnector;
}
