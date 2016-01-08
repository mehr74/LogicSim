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
    VOLTMETER,
    EMPTY,
    LAST_LOGIC_OBJ
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
    ":src/voltmeter.jpg",
    ":src/empty.jpg"
};

#endif // GATETEXTURES_H
