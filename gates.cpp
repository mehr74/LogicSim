#include <iostream>
#include <sstream>
using namespace std;
#include "gates.h"
#include "wires.h"

WireFactory * Gate::ourWireFactory = new WireFactory;

Wire* Gate::WireByNumber(int num)
{
    Wire * w = ourWireFactory->GetWire(num);
    return w;
}

ostream& operator << (ostream& out, const Gate& g)
{
    out << g.tostring();
    return out;
}

void Connect(Wire * w1, Wire * w2)
{
    if (w1 != 0 && w2 != 0)
    {
        Connector * con = new Connector(w1,w2);
    }
}

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

NMGate::NMGate(int number, const string& name)
  : myNumber(number),
    myName(name)
{

}

void NMGate::Init(const vector<Wire *>& in, const vector<Wire *>& out)
{
   myIns = in;
   myOuts = out;
   unsigned int k;
   for(k=0; k < in.size(); k++)
   {
       in[k]->AddGate(this);
   }
}

string NMGate::deepString() const
{
   ostringstream out;
   out << *this << "\n\tin ";
   unsigned int k;
   for(k=0; k < myIns.size(); k++)
   {   out << *myIns[k] << " ";
   }
   out << "\tout ";
   for(k=0; k < myOuts.size(); k++)
   {   out << *myOuts[k] << " ";
   }
   out << "\n----";
   return out.str();
}




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

void GateTester::Test(Gate * gate)
{
    int inputs = gate->InCount();
    int outputs = gate->OutCount();
    int limit = 1 << inputs; // 2^# inputs
    int j,k;
    cout << "testing " << gate->tostring() << endl;
    cout << "-----" << endl;
    for(k=0; k < limit; k++)
    {   for(j=0; j < inputs; j++)
        {   if ( ((k >> j) & 1) == 1)
            {   gate->InWire(j)->SetSignal(true);
                cout << "1 ";
            }
            else
            {   gate->InWire(j)->SetSignal(false);
                cout << "0 ";
            }
        }
        cout << "\t : \t";
        for(j=0; j < outputs;j++)
        {   cout << (gate->OutWire(j)->GetSignal() ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << "------" << endl;
}

Probe::Probe(Wire * w)
  : myWire(w)
{
    myWire->AddGate(this);
}

void Probe::Act()
{
    cout << *myWire << "\t signal= " << myWire->GetSignal() << endl;
}
string Probe::tostring() const
{
    return "probe " + myWire->tostring();
}
