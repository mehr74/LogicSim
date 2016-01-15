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
    switch(gateType)
    {
    case AND_GATE:
        cout << "NEW AND GATE ADDED!" << endl;
        gates.push_back(new AndGate());
        break;
    case OR_GATE:
        cout << "NEW OR GATE ADDED!" << endl;
        gates.push_back(new OrGate());
        break;
    case INVERTER:
        cout << "NEW INVERTER GATE ADDED!" << endl;
        gates.push_back(new Inverter());
        break;
    case NAND_GATE:
        cout << "NEW NAND GATE ADDED!" << endl;
        gates.push_back(new NandGate());
        break;
    case NOR_GATE:
        cout << "NEW NOR GATE ADDED!" << endl;
        gates.push_back(new NorGate());
        break;
    case XOR_GATE:
        cout << "NEW XOR GATE ADDED!" << endl;
        gates.push_back(new XorGate());
        break;
    case XNOR_GATE:
        cout << "NEW XNOR GATE ADDED!" << endl;
        gates.push_back(new XnorGate());
        break;
    case ON_BIT:
        cout << "NEW ON BIT ADDED!" << endl;
        gates.push_back(new Bit(true));
        break;
    case OFF_BIT:
        cout << "NEW OFF BIT ADDED!" << endl;
        gates.push_back(new Bit(false));
        break;
    case VOLTMETER:
        cout << "NEW VOLTMETER ADDED!" << endl;
        gates.push_back(new VoltMeter());
        break;
    }

    return gates.size()-1;
}

int Circuit::addConnection(int gateId1, int gateId2, int connectorType1, int connectorType2)
{
    cout << "Add connection" << endl;
    cout << *gates[gateId1] << endl;
    cout << *gates[gateId2] << endl;

    Wire *start;
    Wire *end;

    if(connectorType1 == OUTPUT_CONNECTOR)
        start = gates[gateId1]->OutWire(connectorType1);
    else
        start = gates[gateId1]->InWire(connectorType1);

    if(connectorType2 == OUTPUT_CONNECTOR)
        end = gates[gateId2]->OutWire(connectorType2);
    else
        end = gates[gateId2]->InWire(connectorType2);

    cout << *start << endl;
    cout << *end << endl;

    Connect(start, end);

    return 0;
}

void Circuit::testFunc()
{

}


