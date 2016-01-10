#include <iostream>
#include <sstream>
using namespace std;
#include "gates.h"
#include "wires.h"

WireFactory * Gate::ourWireFactory = new WireFactory;

Wire* Gate::WireByNumber(int num)
{
    Wire * w = ourWireFactory->GetWire(num);
    return w;
}

ostream& operator << (ostream& out, const Gate& g)
{
    out << g.tostring();
    return out;
}

void Connect(Wire * w1, Wire * w2)
{
    if (w1 != 0 && w2 != 0)
    {
        Connector * con = new Connector(w1,w2);
    }
}
