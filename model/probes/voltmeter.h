#ifndef VOLTMETER_H
#define VOLTMETER_H

#include "model/gates/gate.h"


class VoltMeter : public Gate
{
    Q_OBJECT
  public:
    VoltMeter (Wire * w);
    virtual void Act( );
    virtual string tostring() const;

    int InCount() const {return 1;}
    int OutCount() const {return 1;}
    Wire * InWire(int n) const {return myWire;}
    Wire * OutWire(int n) const {return myWire;}
    Gate * clone() {return this;}

signals:
    void signalChanged(bool signal, int number);

  protected:
    Wire * myWire;

  private:
    static int ourCount;
    int myNumber;

};

#endif // VOLTMETER_H
