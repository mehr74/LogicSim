#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class GateList;
class GatesModel;
class QListView;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

private:
    void setupWidgets();
    QListView *piecesList;
    Ui::MainWindow *ui;
    GateList *gateList;
    GatesModel *model;
};


#endif // MAINWINDOW_H
