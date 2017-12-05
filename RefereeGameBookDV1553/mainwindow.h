#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "referee.h" //bara för test
#include "referees.h" //bara för test
#include "team.h" //för test
#include "teams.h" //för test
#include "refereewindow.h"
#include"teamwindow.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Referees referees;
    RefereeWindow* refereeWindow;
    TeamWindow* teamWindow;
    Teams teams;
};

#endif // MAINWINDOW_H
