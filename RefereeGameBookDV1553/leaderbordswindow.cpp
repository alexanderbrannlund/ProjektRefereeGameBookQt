#include "leaderbordswindow.h"
#include "ui_leaderbordswindow.h"

LeaderbordsWindow::LeaderbordsWindow(Referees referees, Games games,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LeaderbordsWindow),games(games)
{
    ui->setupUi(this);
    this->referees=referees;
}

LeaderbordsWindow::~LeaderbordsWindow()
{
    delete ui;
}

void LeaderbordsWindow::on_pushButton_show_clicked()
{
    Leaderboards lb(referees,games);
    QString toPrint;
    QDate date=ui->dateEdit_SHow->date();

    if(ui->radioButton_show_allSByPM->isChecked())
    {
        toPrint=lb.ShowAllseasonLbByMin();
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_allSByPM->setAutoExclusive(false);
        ui->radioButton_show_allSByPM->setChecked(false);
        ui->radioButton_show_allSByPM->setAutoExclusive(true);
    }

    if(ui->radioButton_show_allSByPS->isChecked())
    {
        toPrint=lb.ShowAllseasonLbByPShots();
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_allSByPS->setAutoExclusive(false);
        ui->radioButton_show_allSByPS->setChecked(false);
        ui->radioButton_show_allSByPS->setAutoExclusive(true);
    }

    if(ui->radioButton_show_allSByG->isChecked())
    {
        toPrint=lb.ShowAllseasonLbByGoals();
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_allSByG->setAutoExclusive(false);
        ui->radioButton_show_allSByG->setChecked(false);
        ui->radioButton_show_allSByG->setAutoExclusive(true);
    }

    if(ui->radioButton_show_seasAll->isChecked())
    {
        toPrint=lb.ShowAllseasonLbByMin()+"\n\n";
        toPrint+=lb.ShowAllseasonLbByPShots()+"\n\n";
        toPrint += lb.ShowAllseasonLbByGoals();
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_seasAll->setAutoExclusive(false);
        ui->radioButton_show_seasAll->setChecked(false);
        ui->radioButton_show_seasAll->setAutoExclusive(true);
    }

    if(ui->radioButton_show_mByPM->isChecked())
    {
        toPrint=lb.ShowMontlyLbByMin(date);
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_mByPM->setAutoExclusive(false);
        ui->radioButton_show_mByPM->setChecked(false);
        ui->radioButton_show_mByPM->setAutoExclusive(true);
    }

    if(ui->radioButton_show_mByPS->isChecked())
    {
        toPrint=lb.ShowMontlyLbByPShots(date);
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_mByPS->setAutoExclusive(false);
        ui->radioButton_show_mByPS->setChecked(false);
        ui->radioButton_show_mByPS->setAutoExclusive(true);
    }

    if(ui->radioButton_show_mByG->isChecked())
    {
        toPrint=lb.ShowMontlyLbByGoals(date);
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_mByG->setAutoExclusive(false);
        ui->radioButton_show_mByG->setChecked(false);
        ui->radioButton_show_mByG->setAutoExclusive(true);
    }

    if(ui->radioButton_show_mAll->isChecked())
    {
        toPrint=lb.ShowMontlyLbByMin(date)+"\n\n";
        toPrint+=lb.ShowMontlyLbByPShots(date)+"\n\n";
        toPrint+= lb.ShowMontlyLbByGoals(date);
        ui->textBrowser->setText(toPrint);

        ui->radioButton_show_mAll->setAutoExclusive(false);
        ui->radioButton_show_mAll->setChecked(false);
        ui->radioButton_show_mAll->setAutoExclusive(true);
    }

}

void LeaderbordsWindow::on_pushButton_GoBack_clicked()
{
    this->close();
    parentWidget()->show();
}

void LeaderbordsWindow::on_pushButton_Save_clicked()
{
    ui->textBrowser->clear();

    Leaderboards lb(referees,games);
    QDate date=ui->dateEdit_save->date();
    QString fileNameForMonthPM="C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/LBMonthlyPM_"+date.toString("MMM")+".txt";
    QString fileNameForMonthPS="C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/LBMonthlyPS_"+date.toString("MMM")+".txt";
    QString fileNameForMonthG="C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/LBMonthlyG_"+date.toString("MMM")+".txt";
    QString fileNameForMonthAll="C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/LBMonthlyAll_"+date.toString("MMM")+".txt";


    if(ui->radioButton_save_allSByPM->isChecked())
    {
        lb.SaveLeaderboardsToFile(3,"C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/AllSeasonLBByPmin.txt");

        ui->radioButton_save_allSByPM->setAutoExclusive(false);
        ui->radioButton_save_allSByPM->setChecked(false);
        ui->radioButton_save_allSByPM->setAutoExclusive(true);
    }

    if(ui->radioButton_save_allSByPS->isChecked())
    {
        lb.SaveLeaderboardsToFile(4,"C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/AllSeasonLBByPShot.txt");

        ui->radioButton_save_allSByPS->setAutoExclusive(false);
        ui->radioButton_save_allSByPS->setChecked(false);
        ui->radioButton_save_allSByPS->setAutoExclusive(true);
    }

    if(ui->radioButton_save_allSByG->isChecked())
    {
        lb.SaveLeaderboardsToFile(5,"C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/AllSeasonLBByGoals.txt");

        ui->radioButton_save_allSByG->setAutoExclusive(false);
        ui->radioButton_save_allSByG->setChecked(false);
        ui->radioButton_save_allSByG->setAutoExclusive(true);
    }

    if(ui->radioButton_save_allS->isChecked())
    {
        lb.SaveLeaderboardsToFile(1,"C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/AllSeasonLB.txt");

        ui->radioButton_save_allS->setAutoExclusive(false);
        ui->radioButton_save_allS->setChecked(false);
        ui->radioButton_save_allS->setAutoExclusive(true);
    }

    if(ui->radioButton_save_mByPM->isChecked())
    {
        lb.SaveLeaderboardsToFile(6,fileNameForMonthPM,date);

        ui->radioButton_save_mByPM->setAutoExclusive(false);
        ui->radioButton_save_mByPM->setChecked(false);
        ui->radioButton_save_mByPM->setAutoExclusive(true);
    }

    if(ui->radioButton_save_mByPS->isChecked())
    {
        lb.SaveLeaderboardsToFile(7,fileNameForMonthPS,date);

        ui->radioButton_save_mByPS->setAutoExclusive(false);
        ui->radioButton_save_mByPS->setChecked(false);
        ui->radioButton_save_mByPS->setAutoExclusive(true);
    }

    if(ui->radioButton_save_mByG->isChecked())
    {
        lb.SaveLeaderboardsToFile(8,fileNameForMonthG,date);

        ui->radioButton_save_mByG->setAutoExclusive(false);
        ui->radioButton_save_mByG->setChecked(false);
        ui->radioButton_save_mByG->setAutoExclusive(true);
    }

    if(ui->radioButton_save_mAll->isChecked())
    {
        lb.SaveLeaderboardsToFile(2,fileNameForMonthAll,date);

        ui->radioButton_save_mAll->setAutoExclusive(false);
        ui->radioButton_save_mAll->setChecked(false);
        ui->radioButton_save_mAll->setAutoExclusive(true);
    }
}
