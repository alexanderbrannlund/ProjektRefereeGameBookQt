#ifndef TEAMWINDOW_H
#define TEAMWINDOW_H

#include <QDialog>

namespace Ui {
class TeamWindow;
}

class TeamWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TeamWindow(QWidget *parent = 0);
    ~TeamWindow();

private:
    Ui::TeamWindow *ui;
};

#endif // TEAMWINDOW_H
