#include "circuit.h"
#include "model/gatetextures.h"

Circuit::Circuit()
{
}

int Circuit::InCount(int gateType) const
{
    switch(gateType)
    {
    case AND_GATE:
    case OR_GATE:
    case XOR_GATE:
    case NAND_GATE:
    case NOR_GATE:
    case XNOR_GATE:
        return 2;

    case INVERTER:
    case VOLTMETER:
        return 1;

    case ON_BIT:
    case OFF_BIT:
        return 0;

    }
    return 0;
}

int Circuit::addGate(int gateType)
{
    cout << "\n-----------------------" << endl;
    switch(gateType)
    {
    case AND_GATE:
        gates.push_back(new AndGate());
        break;
    case OR_GATE:
        gates.push_back(new OrGate());
        break;
    case INVERTER:
        gates.push_back(new Inverter());
        break;
    case NAND_GATE:
        gates.push_back(new NandGate());
        break;
    case NOR_GATE:
        gates.push_back(new NorGate());
        break;
    case XOR_GATE:
        gates.push_back(new XorGate());
        break;
    case XNOR_GATE:
        gates.push_back(new XnorGate());
        break;
    case ON_BIT:
        gates.push_back(new Bit(true));
        break;
    case OFF_BIT:
        gates.push_back(new Bit(false));
        break;
    }
    cout << "NEW GATE" << endl;
    cout << gates.back()->deepString() << endl;
    VoltMeter *volt = new VoltMeter(gates.back()->OutWire(0));
    voltMeters.push_back(volt);
    QObject::connect(voltMeters.back(), SIGNAL(signalChanged(bool,int)),
                    this, SLOT(updateSignal(bool,int)));
    signalVolt.push_back(gates.back()->OutWire(0)->GetSignal());

    return gates.size()-1;
}

int Circuit::addConnection(int gateId1, int gateId2, int connectorType1, int connectorType2)
{
    cout << "\n**********************" << endl;
    cout << "Add connection" << endl;


    Wire *start;
    Wire *end;

    if(connectorType1 == OUTPUT_CONNECTOR)
        start = gates[gateId1]->OutWire(0);
    else
        start = gates[gateId1]->InWire(connectorType1);

    if(connectorType2 == OUTPUT_CONNECTOR)
        end = gates[gateId2]->OutWire(0);
    else
        end = gates[gateId2]->InWire(connectorType2);

    cout << *gates[gateId1] << *start
         << "  <=====>  "
         << *gates[gateId2] << *end
         << endl;
    cout << "**********************" << endl;

    Connect(start, end);



    return 0;
}
void Circuit::updateSignal(bool signal, int index)
{
    signalVolt[index] = signal;
}

bool Circuit::getSignal(int index)
{
    return signalVolt[index];
}


