#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Referee test(1,"Test", "Testsson");
    QMessageBox::information(this,"Test", test.ToStringReadable());
    QMessageBox::information(this,"Test", test.ToStringSaveable());
    QMessageBox::information(this,"Test", test.GetFirstName());
    test.SetTotalPenalties(23);
    test.SetTotalGoals(2);
    test.SetTotalPenaltyShots(5);

    QMessageBox::information(this,"Test", test.ToStringReadable());
    QMessageBox::information(this,"Test", test.ToStringSaveable());

    Referee test2(2,"Test", "Testsson");
    Referee test3(3,"Testa", "Allt");

    if(!(test==test3))
    {
      QMessageBox::information(this,"Test", "De är inte lika!!!");
    }

    if(test==test2)
    {
        QMessageBox::information(this,"Test", "De är lika!!!");
    }


}

void MainWindow::on_pushButton_2_clicked()
{
    Referees refGB;
    refGB.AddReferee("Test1","Testsson",0,0,0,-1);
    refGB.AddReferee("Test2","Testsson",0,0,0,1);
    refGB.AddReferee("Test3","Testsson",0,0,0,-1);
    refGB.AddReferee("Test4","Testsson",0,0,0,-1);
    refGB.AddReferee("Test5","Testsson",0,0,0,-1);

    if(refGB.AddReferee("Test3","Testsson",0,0,0,-1)==false)
    {
        QMessageBox::warning(this,"Ref already exist","The ref does already exist in Referee Gamebook");
    }

    refGB.AddReferee("Test6","Testsson",0,0,0,-1);

    if(refGB.RemoveReferee("Test2","Testsson"))
    {
        QMessageBox::information(this, "Removed", "Referee was removed");
    }
    QMessageBox::information(this,"ToString", refGB.ToStringSaveable());

    QMessageBox::information(this,"Save","Saving to file");

    refGB.SaveToFile("C:/Users/brann/Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/testRefGB.txt");

    QMessageBox::information(this,"Clear","Clearing RefGB");
    refGB.Clear();

    QMessageBox::information(this,"ToString", refGB.ToStringSaveable());

    QMessageBox::information(this,"Read","Reading from file");

    refGB.ReadFromFile("C:/Users/brann/Qt projekt/RefereeGameBook Projekt/RefereeGameBookQt/testRefGB.txt");


    QMessageBox::information(this,"ToString", refGB.ToStringSaveable());



}

void MainWindow::on_pushButton_3_clicked()
{
    refereeWindow= new RefereeWindow(referees,this);
    hide();
    refereeWindow->show();

}
