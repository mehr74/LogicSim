#include "gatetester.h"
#include "model/model.h"
void GateTester::Test(Gate * gate)
{
    int inputs = gate->InCount();
    int outputs = gate->OutCount();
    int limit = 1 << inputs; // 2^# inputs
    int j,k;
    cout << "testing " << gate->tostring() << endl;
    cout << "-----" << endl;
    for(k=0; k < limit; k++)
    {
        for(j=0; j < inputs; j++)
        {
            if ( ((k >> j) & 1) == 1)
            {
                gate->InWire(j)->SetSignal(true);
                cout << "1 ";
            }
            else
            {
                gate->InWire(j)->SetSignal(false);
                cout << "0 ";
            }
        }
        cout << "\t : \t";
        for(j=0; j < outputs;j++)
        {
            cout << (gate->OutWire(j)->GetSignal() ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << "------" << endl;
}

