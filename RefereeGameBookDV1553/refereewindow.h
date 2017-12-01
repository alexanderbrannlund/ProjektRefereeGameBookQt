#ifndef REFEREEWINDOW_H
#define REFEREEWINDOW_H
#include "referees.h"
#include <QDialog>

namespace Ui {
class RefereeWindow;
}

class RefereeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RefereeWindow(Referees referees,QWidget *parent = 0);
    ~RefereeWindow();

private slots:
    void on_Add_clicked();

    void on_Show_clicked();

    void on_Remove_clicked();

private:
    Ui::RefereeWindow *ui;
    Referees referees;
};

#endif // REFEREEWINDOW_H
