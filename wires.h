#ifndef _WIRES_H
#define _WIRES_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Gate;
class Connector;

class Wire
{
  public:
    Wire(const string& name="");
    virtual ~Wire();
    virtual bool   GetSignal() const;       // true/false, on/off
    virtual string tostring()  const;       // for I/O

    virtual void   SetSignal(bool signal);  // set signal, propagate
    virtual void   AddGate(Gate * g);       // g monitors this wire
    virtual void   RemoveGate(Gate * g);    // g stops monitoring
    virtual int    Number() const;          // which wire is this?

    friend class ConnectorIterator;         // access myGates

  private:

    vector<Gate *>      myGates;
    bool                 mySignal;
    string               myName;
    int                  myNumber;
    static int           ourCount;           // class wide, keeps count
};

ostream& operator << (ostream& out, const Wire& w);

class WireFactory
{
  public:
    WireFactory();
    virtual ~WireFactory();
    virtual Wire * MakeWire(const string& name="wire"); // create anew
    virtual Wire * GetWire(int num) const;              // get by number
  private:
    vector<Wire *> myWires;
};

// standard tapestry iterator for iterating over all
// connectors attached to a wire

class ConnectorIterator
{
  public:
    ConnectorIterator(Wire* w);
    void Init();
    bool HasMore();
    void Next();
    Connector * Current();
  private:
    Wire *      myWire;
    Connector * myConnector;
    int         myIndex;
};

#endif
