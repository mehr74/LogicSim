#include <iostream>
using namespace std;

#include "gates.h"

int main()
{
    //-----------------------------------------------------
    // Testing gates solely
    //-----------------------------------------------------
    Gate *andg = new AndGate();
    Gate *org = new OrGate();
    Gate *invg = new Inverter();
    Gate *nandg = new NandGate();
    Gate *xorg = new XorGate();
    Gate *norg = new NorGate();

    GateTester::Test(andg);
    GateTester::Test(org);
    GateTester::Test(invg);
    GateTester::Test(nandg);
    GateTester::Test(xorg);
    GateTester::Test(norg);
    //-----------------------------------------------------

    //-----------------------------------------------------
    // Make question example circuit
    //-----------------------------------------------------
    Wire * in = new Wire();
    Wire * in2 = new Wire();
    Wire * in3 = new Wire();
    Wire * aout = new Wire();
    Wire * xout = new Wire();
    Wire * oout = new Wire();
    Wire * iout = new Wire();
    Wire * nout = new Wire();

    cout << *in << "\t Input #1" << endl;
    cout << *in2 << "\t Input #2" << endl;
    cout << *in3 << "\t Input #3" << endl;
    cout << *aout << "\t And output" << endl;
    cout << *xout << "\t Xor output" << endl;
    cout << *oout << "\t Or output" << endl;
    cout << *iout << "\t Inverter output" << endl;
    cout << *nout << "\t Nand output " << endl;

    Gate * andg1 = new AndGate(in, in2, aout, "And-Gate");
    Gate * xorg1 = new XorGate(in2, in3, xout, "Xor-Gate");
    Gate * org1 = new OrGate(aout, xout, oout, "Or-Gate");
    Gate * invg1 = new Inverter(xout, iout, "Inverter");
    Gate * nandg1 = new NandGate(oout, iout, nout, "Nand-Gate");
    cout << endl;

    VoltMeter *aoutv = new VoltMeter(aout);
    VoltMeter *xoutv = new VoltMeter(xout);
    VoltMeter *ooutv = new VoltMeter(oout);
    VoltMeter *ioutv = new VoltMeter(iout);
    VoltMeter *noutv = new VoltMeter(nout);

    cout << "set " << *in << " on" << endl;
    in->SetSignal(true);
    cout << "set " << *in2 << " off" << endl;
    in2->SetSignal(false);
    cout << "set " << *in3 << " on" << endl;
    in3->SetSignal(true);

    Gate * nandg2 = new NandGate("Nand gate2");
    GateTester::Test(nandg2);


    return 0;
}
