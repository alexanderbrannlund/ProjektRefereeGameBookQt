#ifndef LEADERBORDSWINDOW_H
#define LEADERBORDSWINDOW_H
#include "leaderboards.h"

#include <QDialog>

namespace Ui {
class LeaderbordsWindow;
}

class LeaderbordsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderbordsWindow(Referees referees, Games games,QWidget *parent = 0);
    ~LeaderbordsWindow();

private slots:
    void on_pushButton_show_clicked();

    void on_pushButton_GoBack_clicked();

    void on_pushButton_Save_clicked();

private:
    Ui::LeaderbordsWindow *ui;
    Referees referees;
    Games games;
};

#endif // LEADERBORDSWINDOW_H
