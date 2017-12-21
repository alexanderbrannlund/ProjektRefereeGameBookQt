#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), games(&referees)
{
    ui->setupUi(this);
    referees.ReadFromFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/RefereesTest.txt");
    games.ReadFromFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/GamesTest.txt");
    teams.ReadFromFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/TeamsTest.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
    referees.SaveToFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/RefereesTest.txt");
    games.SaveToFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/GamesTest.txt");
    teams.SaveToFile("C:/Users/brann/Projekt i DV1553/ProjektRefereeGameBookQt/RefereeGameBookDV1553/TeamsTest.txt");
}

void MainWindow::on_actionReferees_triggered()
{
    refereeWindow= new RefereeWindow(&referees,this);
    hide();
    refereeWindow->show();
}

void MainWindow::on_actionTeams_triggered()
{
    teamWindow=new TeamWindow(&teams, this);
    hide();
    teamWindow->show();
}

void MainWindow::on_actionGames_triggered()
{
    gameWindow=new GameWindow(&games,&referees,this);
    hide();
    gameWindow->show();
}

void MainWindow::on_actionQuit_application_triggered()
{
    this->close();
}

void MainWindow::on_actionGo_To_Leaderboards_triggered()
{
    leaderboardsWindow= new LeaderbordsWindow(referees,games,this);
    hide();
    leaderboardsWindow->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    refereeWindow= new RefereeWindow(&referees,this);
    hide();
    refereeWindow->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    teamWindow=new TeamWindow(&teams, this);
    hide();
    teamWindow->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    gameWindow=new GameWindow(&games,&referees,this);
    hide();
    gameWindow->show();
}

void MainWindow::on_pushButton_clicked()
{
    leaderboardsWindow= new LeaderbordsWindow(referees,games,this);
    hide();
    leaderboardsWindow->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    this->close();
}
