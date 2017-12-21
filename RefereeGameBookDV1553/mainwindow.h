#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "referees.h"
#include "refereewindow.h"
#include"teamwindow.h"
#include "games.h"
#include "gamewindow.h"
#include "leaderbordswindow.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionReferees_triggered();

    void on_actionTeams_triggered();

    void on_actionGames_triggered();

    void on_actionQuit_application_triggered();

    void on_actionGo_To_Leaderboards_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    Referees referees;
    RefereeWindow* refereeWindow;
    TeamWindow* teamWindow;
    Teams teams;
    Games games;
    GameWindow* gameWindow;
    LeaderbordsWindow* leaderboardsWindow;
};

#endif // MAINWINDOW_H
