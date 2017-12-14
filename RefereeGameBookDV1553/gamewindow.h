#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "games.h"
#include "referees.h"

#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(Games* games,Referees* referees, QWidget *parent = 0);
    ~GameWindow();

private slots:
    void on_pushButton_addGame_clicked();

    void on_pushButton_changeRef_clicked();

    void on_pushButton_removeGame_clicked();

    void on_pushButton_addGAtt_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_goBackToStart_clicked();

private:
    Ui::GameWindow *ui;
    Games* games;
    Referees* referees;
};

#endif // GAMEWINDOW_H
