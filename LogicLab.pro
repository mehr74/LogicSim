TEMPLATE = app

CONFIG += console
CONFIG += qt

QT += widgets

INCLUDEPATH += .
DEPENDPATH += .

SOURCES += main.cpp \
    model/gates/andgate.cpp \
    model/gates/connector.cpp \
    model/gates/gate.cpp \
    model/gates/inverter.cpp \
    model/gates/nandgate.cpp \
    model/gates/nmgate.cpp \
    model/gates/norgate.cpp \
    model/gates/orgate.cpp \
    model/gates/xorgate.cpp \
    model/probes/gatetester.cpp \
    model/probes/voltmeter.cpp \
    model/wires/wires.cpp \
    view/gatelist.cpp \
    view/gatesmodel.cpp \
    view/mainwindow.cpp \
    view/circuit.cpp \
    model/gates/xnorgate.cpp \
    model/gates/bit.cpp

HEADERS += \
    model/gates/andgate.h \
    model/gates/connector.h \
    model/gates/gate.h \
    model/gates/inverter.h \
    model/gates/nandgate.h \
    model/gates/nmgate.h \
    model/gates/norgate.h \
    model/gates/orgate.h \
    model/gates/xorgate.h \
    model/probes/gatetester.h \
    model/probes/voltmeter.h \
    model/wires/wires.h \
    model/gatetextures.h \
    model/model.h \
    view/gatelist.h \
    view/gatesmodel.h \
    view/mainwindow.h \
    view/circuit.h \
    model/gates/xnorgate.h \
    model/gates/bit.h \
    model/gates/device.h


OTHER_FILES +=

RESOURCES += \
    logiclab.qrc

FORMS += \
    view/mainwindow.ui

