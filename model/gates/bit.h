#ifndef BIT_H
#define BIT_H

#include "model/model.h"

class Bit : public Gate
{
  public:
    Bit(bool value, Wire * out, const string& name="");
    Bit(bool value, const string& name="");
    virtual void Act( );
    virtual string tostring() const;

    int InCount()  const {return 0;}
    int OutCount() const {return 1;}
    Wire * OutWire(int n) const {return myOut;}
    Gate * clone();

    virtual string deepString() const;

  private:
    bool myValue;
    Wire * myOut;
    string myName;
    int    myNumber;
    static int ourCount;
};

#endif // BIT_H
