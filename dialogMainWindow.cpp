#include "dialogMainWindow.h"
#include "ui_dialogMainWindow.h"

dialogMainWindow::dialogMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dialogMainWindow)
{
    ui->setupUi(this);
}

dialogMainWindow::~dialogMainWindow()
{
    delete ui;
}
