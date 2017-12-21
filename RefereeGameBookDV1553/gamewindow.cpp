#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "games.h"
#include "referees.h"
#include <QMessageBox>

GameWindow::GameWindow(Games* games,Referees* referees,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    this->games=games;
    this->referees=referees;
}

GameWindow::~GameWindow()
{
    delete ui;
}

void GameWindow::on_pushButton_addGame_clicked()
{
    QString homeTeam= ui->lineEdit_add_homeTeam->text();
    QString guestTeam= ui->lineEdit_add_guestTeam->text();
    QDate date= ui->dateEdit_addGame->date();
    QString refFirstName=ui->lineEdit_add_referee_Fn->text();
    QString refSurName=ui->lineEdit_add_referee_SN->text();

    int refId=referees->RetRefId(refFirstName,refSurName);

    games->AddGame(homeTeam,guestTeam,date,refId);

    ui->lineEdit_add_homeTeam->clear();
    ui->lineEdit_add_guestTeam->clear();
    ui->lineEdit_add_referee_Fn->clear();
    ui->lineEdit_add_referee_SN->clear();
    ui->dateEdit_addGame->clear();
}

void GameWindow::on_pushButton_changeRef_clicked()
{
    QString homeTeam= ui->lineEdit_changeRef_homeTeam->text();
    QString guestTeam= ui->lineEdit_changeRef_guestTeam->text();
    QDate date= ui->dateEdit_ChangeRef->date();

    QString refFirstName=ui->lineEdit_changeRef_referee_FN->text();
    QString refSurName=ui->lineEdit_changeRef_referee_SN->text();

    int refId=referees->RetRefId(refFirstName,refSurName);

    games->ChangeReferee(homeTeam,guestTeam,date,refId);

    ui->lineEdit_changeRef_homeTeam->clear();
    ui->lineEdit_changeRef_guestTeam->clear();
    ui->lineEdit_changeRef_referee_FN->clear();
    ui->lineEdit_changeRef_referee_SN->clear();
    ui->dateEdit_ChangeRef->clear();
}

void GameWindow::on_pushButton_removeGame_clicked()
{
    QString homeTeam= ui->lineEdit_remove_homeTeam->text();
    QString guestTeam= ui->lineEdit_remove_guestTeam->text();
    QDate date= ui->dateEdit_RemoveGame->date();

    games->RemoveGame(homeTeam,guestTeam,date);

    ui->lineEdit_remove_homeTeam->clear();
    ui->lineEdit_remove_guestTeam->clear();
    ui->dateEdit_RemoveGame->clear();
}

void GameWindow::on_pushButton_addGAtt_clicked()
{
    QString homeTeam= ui->lineEdit_addGAtt_homeTeam->text();
    QString guestTeam= ui->lineEdit_addGAtt_guestTeam->text();
    QDate date= ui->dateEdit_AddGAtt->date();
    int pMin= ui->spinBox_Pmin->value();
    int pShot= ui->spinBox_PShot->value();
    int goals= ui->spinBox_Goals->value();

    games->AddGoalsAndPenalties(homeTeam, guestTeam,date, pMin, pShot, goals);

    ui->lineEdit_addGAtt_homeTeam->clear();
    ui->lineEdit_addGAtt_guestTeam->clear();
    ui->dateEdit_AddGAtt->clear();
    ui->spinBox_Goals->clear();
    ui->spinBox_Pmin->clear();
    ui->spinBox_PShot->clear();
}

void GameWindow::on_pushButton_show_clicked()
{
    if(ui->radioButton_showAll->isChecked())
    {
       QString print= games->ToStringReadableAll();
       ui->textBrowser->setText(print);
       ui->radioButton_showAll->setAutoExclusive(false);
       ui->radioButton_showAll->setChecked(false);
       ui->radioButton_showAll->setAutoExclusive(true);
    }

    if(ui->radioButton_showOne->isChecked())
    {
        QString homeTeam= ui->lineEdit_ShowOneHName->text();
        QString guestTeam= ui->lineEdit_showOneGName->text();
        QDate date= ui->dateEdit_ShowOneDate->date();

        QString print= games->ToStringReadableOne(homeTeam,guestTeam,date);

        if(print!="Does not exist")
        {
            ui->textBrowser->setText(print);
        }

        else
        {
            QMessageBox::warning(this,"Game does not exist", "The given game does not exist in Referee GameBook...");

        }

        ui->lineEdit_ShowOneHName->clear();
        ui->lineEdit_showOneGName->clear();
        ui->dateEdit_ShowOneDate->clear();
        ui->radioButton_showOne->setAutoExclusive(false);
        ui->radioButton_showOne->setChecked(false);
        ui->radioButton_showOne->setAutoExclusive(true);

    }
}

void GameWindow::on_pushButton_goBackToStart_clicked()
{
    this->close();
    parentWidget()->show();
}
