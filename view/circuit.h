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
    int addConnection(int gateId1, int gateId2, int connectorType1, int connectorType2);
    void testFunc();

private:
    vector<Gate *> gates;
};



#endif // CIRCUIT_H
