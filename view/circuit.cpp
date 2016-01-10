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
}
