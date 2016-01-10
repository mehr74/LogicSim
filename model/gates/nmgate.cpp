#include "nmgate.h"
#include <sstream>

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

