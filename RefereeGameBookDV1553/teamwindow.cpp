#include "teamwindow.h"
#include "ui_teamwindow.h"

TeamWindow::TeamWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);
}

TeamWindow::~TeamWindow()
{
    delete ui;
}
