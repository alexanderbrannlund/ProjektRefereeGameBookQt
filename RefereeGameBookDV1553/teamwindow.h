#ifndef TEAMWINDOW_H
#define TEAMWINDOW_H
#include"teams.h"

#include <QDialog>

namespace Ui {
class TeamWindow;
}

class TeamWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TeamWindow(Teams* teams, QWidget *parent = 0);
    ~TeamWindow();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_Remove_clicked();

    void on_pushButton_Show_clicked();

    void on_pushButton_clicked();

private:
    Ui::TeamWindow *ui;
    Teams* teams;
};

#endif // TEAMWINDOW_H
