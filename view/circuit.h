#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "model/model.h"
#include <vector>
#include <QObject>

class Circuit : public QObject
{
    Q_OBJECT

public:
    Circuit();
    int InCount(int gateType) const;
    int addGate(int gateType);
    int addConnection(int gateId1, int gateId2, int connectorType1, int connectorType2);
    bool getSignal(int index);

private slots:
    void updateSignal(bool signal, int index);

private:
    vector<Gate *> gates;
    vector<VoltMeter *> voltMeters;
    vector<bool> signalVolt;
};



#endif // CIRCUIT_H
