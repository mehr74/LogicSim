#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "model/model.h"
#include <vector>

class Circuit
{
public:
    Circuit();
    int InCount(int gateType) const;
    int addGate(int gateType);

private:
    vector<AndGate * > andGates;
    vector<OrGate * > orGates;
    vector<XorGate * > xorGates;
    vector<NandGate *> nandGates;
    vector<Inverter *> inverterGates;
    vector<NorGate *> norGates;
    vector<XnorGate *> xnorGates;
};



#endif // CIRCUIT_H
