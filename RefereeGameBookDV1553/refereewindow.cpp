#include "refereewindow.h"
#include "ui_refereewindow.h"
#include <QMessageBox>

RefereeWindow::RefereeWindow(Referees referees,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RefereeWindow)
{
    ui->setupUi(this);
    this->referees=referees;
}

RefereeWindow::~RefereeWindow()
{
    delete ui;
}

void RefereeWindow::on_Add_clicked()
{
    QString firstName=ui->lineEdit_add_firstName->text();
    QString surName=ui->lineEdit_add_surName->text();

    bool added=referees.AddReferee(firstName,surName,0,0,0,-1);
    if(added==true)
    {
        ui->lineEdit_add_firstName->clear();
        ui->lineEdit_add_surName->clear();
    }

    else
    {
        QMessageBox::warning(this,"Was not added", "The referee was not added");
        ui->lineEdit_add_firstName->clear();
        ui->lineEdit_add_surName->clear();
    }

}

void RefereeWindow::on_Show_clicked()
{
    if(ui->radioButton_showAll->isChecked())
    {
       QString print= referees.ToStringReadableAll();
       ui->textEdit->setText(print);
    }
    if(ui->radioButton_showOne->isChecked())
    {
        QString firstName=ui->lineEdit_show_firstName->text();
        QString surName=ui->lineEdit_show_surName->text();

        QString print= referees.ToStringReadableOne(firstName,surName);
        if(print!="Does not exist")
        {
            ui->textEdit->setText(print);
            ui->lineEdit_show_firstName->clear();
            ui->lineEdit_show_surName->clear();
        }

        else
        {
            QMessageBox::warning(this,"Referee does not exist", "The given referee does not exist in Referee GameBook...");
            ui->lineEdit_show_firstName->clear();
            ui->lineEdit_show_surName->clear();
        }

    }
}

void RefereeWindow::on_Remove_clicked()
{
    QString firstName=ui->lineEdit_remove_firstName->text();
    QString surName=ui->lineEdit_remove_surName->text();

    bool removed=referees.RemoveReferee(firstName,surName);
    if(removed==true)
    {
        ui->lineEdit_remove_firstName->clear();
        ui->lineEdit_remove_surName->clear();
    }
    else
    {
        QMessageBox::warning(this,"Was not removed", "The referee was not removed");
        ui->lineEdit_remove_firstName->clear();
        ui->lineEdit_remove_surName->clear();
    }


}
