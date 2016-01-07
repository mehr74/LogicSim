#ifndef _GATES_H
#define _GATES_H

#include <iostream>
#include <string>
#include <vector>
#include "andgate.h"
using namespace std;

class Wire;
class WireFactory;
class Gate
{
  public:
    virtual ~Gate() {}
    virtual void Act() = 0;
    virtual string tostring() const = 0;
    virtual int    InCount()  const = 0;
    virtual int    OutCount() const = 0;
    virtual Wire * InWire(int n)  const = 0;
    virtual Wire * OutWire(int n) const = 0;
    virtual Gate * clone() = 0;

    virtual string deepString() const { return tostring();}

    static Wire * WireByNumber(int num);

  protected:
    static WireFactory * ourWireFactory;
};

ostream& operator << (ostream& out, const Gate& g);

class Connector : public Gate
{
  public:
    Connector(Wire * in, Wire * out);
    virtual void Act();
    virtual string tostring() const;
    int InCount()   const {return 1;}
    int OutCount()  const {return 1;}
    Wire * InWire(int n)   const {return myIn;}
    Wire * OutWire(int n)  const {return myOut;}
    Gate * clone();
  private:
    Wire * myIn;
    Wire * myOut;
};

class Inverter : public Gate
{
  public:
    Inverter(Wire * in, Wire * out, const string& name="");
    Inverter(const string& name="");
    virtual void Act( );
    virtual string tostring() const;

    int InCount()  const {return 1;}
    int OutCount() const {return 1;}
    Wire * InWire(int n)  const {return myIn;}
    Wire * OutWire(int n) const {return myOut;}
    Gate * clone();

    virtual string deepString() const;

  private:
    Wire * myIn;
    Wire * myOut;
    string myName;
    int    myNumber;
    static int ourCount;
};

class NMGate : public Gate
{
  public:

    virtual void Act( ) = 0;
    virtual string tostring() const = 0;

    int InCount()  const {return myIns.size();}
    int OutCount() const {return myOuts.size();}

    Wire * InWire(int n)  const {return myIns[n];}
    Wire * OutWire(int n) const {return myOuts[n];}

    virtual string deepString() const;

  protected :

    NMGate(int number=0, const string& name="generic");

    void Init(const vector<Wire *>& in, const vector<Wire *>& out);
    vector<Wire *> myIns;
    vector<Wire *> myOuts;
    int    myNumber;
    string myName;
};

class OrGate : public NMGate
{
  public:
    OrGate(Wire * in, Wire * in2, Wire * out, const string& name ="");
    OrGate(const string& name = "");
    virtual void Act( );
    virtual string tostring() const;
    Gate * clone();
  private:
    static int ourCount;
};

class Probe : public Gate
{
  public:
    Probe (Wire * w);
    virtual void Act( );
    virtual string tostring() const;

    int InCount() const {return 1;}
    int OutCount() const {return 1;}
    Wire * InWire(int n) const {return myWire;}
    Wire * OutWire(int n) const {return myWire;}
    Gate * clone() {return this;}

  protected:
    Wire * myWire;

};

class GateTester
{
  public:
   static void Test(Gate * gate);
};

void Connect(Wire * w1, Wire * w2);

#endif
