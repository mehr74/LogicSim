#include <iostream>
using namespace std;

#include "gates.h"
#include "wires.h"

int main()
{
    Gate *andg = new AndGate();
    Gate *org = new OrGate();
    Gate * inv = new Inverter();

    GateTester::Test(andg);
    GateTester::Test(org);
    GateTester::Test(inv);
}
