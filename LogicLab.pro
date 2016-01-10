TEMPLATE = app

CONFIG += console
CONFIG += qt

QT += widgets

INCLUDEPATH += .
DEPENDPATH += .

SOURCES += main.cpp \
    wires.cpp \
    andgate.cpp \
    connector.cpp \
    gatetester.cpp \
    inverter.cpp \
    nmgate.cpp \
    orgate.cpp \
    gate.cpp \
    nandgate.cpp \
    xorgate.cpp \
    norgate.cpp \
    voltmeter.cpp \
    mainwindow.cpp \
    gatelist.cpp \
    gatesmodel.cpp \
    circuit.cpp

HEADERS += \
    wires.h \
    andgate.h \
    connector.h \
    gatetester.h \
    inverter.h \
    nmgate.h \
    orgate.h \
    gate.h \
    gates.h \
    nandgate.h \
    xorgate.h \
    norgate.h \
    voltmeter.h \
    mainwindow.h \
    gatelist.h \
    gatesmodel.h \
    gatetextures.h \
    circuit.h

OTHER_FILES +=

RESOURCES += \
    logiclab.qrc

FORMS += \
    mainwindow.ui

