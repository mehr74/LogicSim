#ifndef GATETEXTURES_H
#define GATETEXTURES_H

enum LogicObject
{
    AND_GATE = 0,
    OR_GATE,
    INVERTER,
    NAND_GATE,
    NOR_GATE,
    XOR_GATE,
    XNOR_GATE,
    ON_BIT,
    OFF_BIT,
    EMPTY,
    CONNECTOR,
    CONNECTOR_HOVERED,
    CONNECTOR_USED,
    PROBE_ON,
    PROBE_OFF,
    VOLTMETER,
    LAST_LOGIC_OBJ
};

enum GateStuff
{
    INPUT_CONNECTOR1,
    INPUT_CONNECTOR2,
    OUTPUT_CONNECTOR
};

static char objectPics[LAST_LOGIC_OBJ][100] = {
    ":src/andgate.jpg",
    ":src/orgate.jpg",
    ":src/inverter.jpg",
    ":src/nandgate.jpg",
    ":src/norgate.jpg",
    ":src/xorgate.jpg",
    ":src/xnorgate.jpg",
    ":src/onbit.jpg",
    ":src/offbit.jpg",
    ":src/empty.jpg",
    ":src/connector.jpg",
    ":src/connectorh.jpg",
    ":src/connectoru.jpg",
    ":src/probeOn.jpg",
    ":src/probeOff.jpg"
};

static char objectNames[LAST_LOGIC_OBJ][100] = {
    "And Gate",
    "Or Gate",
    "Inverter",
    "Nand Gate",
    "Nor Gate",
    "Xor Gate",
    "Xnor Gate",
    "On bit",
    "Off bit",
    "Voltmeter",
    "Empty",
    "Connector",
    "Connector2",
    "Connector3"
};

#endif // GATETEXTURES_H
