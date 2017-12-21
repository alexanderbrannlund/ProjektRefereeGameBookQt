#include "teamwindow.h"
#include "ui_teamwindow.h"
#include <QMessageBox>

TeamWindow::TeamWindow(Teams* teams, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TeamWindow)
{
    ui->setupUi(this);
    this->teams=teams;
}

TeamWindow::~TeamWindow()
{
    delete ui;
}

void TeamWindow::on_pushButton_Add_clicked()
{
    QString teamName=ui->lineEdit_add_teamName->text();
    QString arenaName=ui->lineEdit_add_arenaName->text();

    bool added=teams->AddTeam(teamName,arenaName);
    if(added!=true)
    {
        QMessageBox::warning(this,"Was not added", "The team was not added");
    }

    ui->lineEdit_add_teamName->clear();
    ui->lineEdit_add_arenaName->clear();
}

void TeamWindow::on_pushButton_Remove_clicked()
{
    QString teamName=ui->lineEdit_remove_teamName->text();

    bool removed=teams->RemoveTeam(teamName);
    if(removed!=true)
    {
        QMessageBox::warning(this,"Was not removed", "The team was not removed");
    }

    ui->lineEdit_remove_teamName->clear();

}

void TeamWindow::on_pushButton_Show_clicked()
{
    if(ui->radioButton_showAll->isChecked())
    {
       QString print= teams->ToStringReadableAll();
       ui->textBrowser->setText(print);
       ui->radioButton_showAll->setAutoExclusive(false);
       ui->radioButton_showAll->setChecked(false);
       ui->radioButton_showAll->setAutoExclusive(true);
    }

    if(ui->radioButton_showOne->isChecked())
    {
        QString teamName=ui->lineEdit_showOne_teamName->text();

        QString print= teams->ToStringReadableOne(teamName);

        if(print!="Does not exist")
        {
            ui->textBrowser->setText(print);
        }

        else
        {
            QMessageBox::warning(this,"Referee does not exist", "The given referee does not exist in Referee GameBook...");

        }

        ui->lineEdit_showOne_teamName->clear();
        ui->radioButton_showOne->setAutoExclusive(false);
        ui->radioButton_showOne->setChecked(false);
        ui->radioButton_showOne->setAutoExclusive(true);

    }
}

void TeamWindow::on_pushButton_clicked()
{
    this->close();
    parentWidget()->show();

}
