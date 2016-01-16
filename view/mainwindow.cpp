#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gatelist.h"
#include "gatesmodel.h"
#include "QListView"
#include "model/gatetextures.h"

using namespace Qt;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(this->size());
    this->setMinimumSize(this->size());
    setupWidgets();
}

void MainWindow::setupWidgets()
{
    piecesList = new QListView(this);
    piecesList->setDragEnabled(true);
    piecesList->setViewMode(QListView::IconMode);
    piecesList->setIconSize(QSize(80, 80));
    piecesList->setGridSize(QSize(130, 100));
    piecesList->setSpacing(10);
    piecesList->setMovement(QListView::Snap);
    piecesList->setAcceptDrops(true);
    piecesList->setDropIndicatorShown(true);


    model = new GatesModel();
    piecesList->setModel(model);

    gateList = new GateList(this, QSize(this->width(), this->height()));
    for(int i = 0; i < LAST_LOGIC_OBJ-7; i++)
        model->addPiece(QPixmap(objectPics[i]), i);

    ui->layout1->addWidget(piecesList);
    ui->layout2->addWidget(gateList);


}

