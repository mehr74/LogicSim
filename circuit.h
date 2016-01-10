#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "gates.h"
#include <vector>

class Circuit
{
public:
    Circuit();
    int InCount(int gateType) const;

private:
    vector<AndGate> andGates;
    vector<OrGate> orGates;
    vector<XorGate> xorGates;
    vector<NandGate> nandGates;

};



#endif // CIRCUIT_H
