#include "leaderboards.h"
#include <QFile>
#include <QTextStream>


Leaderboards::Leaderboards(Referees referees, Games games, Team teams)
{
    this->referees=referees;
    this->games=games;
    this->teams=teams;
}

Leaderboards::~Leaderboards()
{

}

void Leaderboards::SortRefereesByPMin(Referees *referees)
{

}

void Leaderboards::SortRefereesByPShots(Referees *referees)
{

}

void Leaderboards::SortRefereesByGoals(Referees *referees)
{

}

QString Leaderboards::ShowAllseasonLbByMin() const
{
    QString retString="All season Leaderbord by penalty minuts: \n\n";


    SortRefereesByPMin(&this->referees);

    retString+=referees.ToStringLbAllPmin();

    return retString;
}

QString Leaderboards::ShowMontlyLbByMin(QDate month) const
{
    QString retString= month.toString("MMM")+":s Leaderbord by penalty minuts: \n\n";
}

QString Leaderboards::ShowAllseasonLbByPShots() const
{
    QString retString="All season Leaderbord by penalty shots: \n\n";


    SortRefereesByPShots(&this->referees);

    retString+=referees.ToStringLbAllPShot();

    return retString;
}

QString Leaderboards::ShowMontlyLbByPShots(QDate month) const
{

}

QString Leaderboards::ShowAllseasonLbByGoals() const
{
    QString retString="All season Leaderbord by goals: \n\n";


    SortRefereesByGoals(&this->referees);

    retString+=referees.ToStringLbAllGoals();

    return retString;
}

QString Leaderboards::ShowMontlyLbByGoals(QDate month) const
{

}

void Leaderboards::SaveLeaderboardsToFile(int saveingAlt,const QString &fileName) const
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream out(&file);
    if(saveingAlt=1)
    {
        out<<ShowAllseasonLbByMin()+"\n\n\n";
        out<<ShowAllseasonLbByPShots()+ "\n\n\n";
        out<<ShowAllseasonLbByGoals() + "\n\n\n";
    }

    if(saveingAlt=2)
    {

    }

    file.flush();
    file.close();
}
