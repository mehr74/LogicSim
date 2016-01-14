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
    if(gateType == AND_GATE)
    {
        AndGate *tmpGate = new AndGate();
        andGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW and gate #" << andGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return andGates.size()-1;
    }
    else if(gateType == OR_GATE)
    {
        OrGate *tmpGate = new OrGate();
        orGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW or gate #" << orGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return orGates.size()-1;
    }
    else if(gateType == XOR_GATE)
    {
        XorGate *tmpGate = new XorGate();
        xorGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW xor gate #" << xorGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return xorGates.size()-1;
    }
    else if(gateType == NAND_GATE)
    {
        NandGate *tmpGate = new NandGate();
        nandGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW nand gate #" << nandGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return inverterGates.size()-1;
    }
    else if(gateType == INVERTER)
    {
        Inverter *tmpGate = new Inverter();
        inverterGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW inverter gate #" << inverterGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return inverterGates.size()-1;
    }
    else if(gateType == NOR_GATE)
    {
        NorGate *tmpGate = new NorGate();
        norGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW nor gate #" << norGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return norGates.size()-1;
    }
    else if(gateType == XNOR_GATE)
    {
        XnorGate *tmpGate = new XnorGate();
        xnorGates.push_back(tmpGate);

        cout << "*******************************************************" << endl;
        cout << "* NEW xnor gate #" << norGates.size() << endl;
        cout << "*******************************************************\n" << endl;
        return norGates.size()-1;
    }

    return 0;
}


