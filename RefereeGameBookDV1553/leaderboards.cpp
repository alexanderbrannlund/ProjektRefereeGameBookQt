#include "leaderboards.h"
#include <QFile>
#include <QTextStream>


Leaderboards::Leaderboards(Referees referees, Games games, Team teams): games(games)
{
    this->referees=referees;
    this->teams=teams;
}

Leaderboards::~Leaderboards()
{

}

void Leaderboards::SortRefereesByPMin(Referees *referees)
{
    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int smallestIndex=i;

        for(int k=i+1; k<referees->GetNrOfRef(); k++)
        {
            if(referees->GetPminAtIndex(i)<referees->GetPminAtIndex(smallestIndex))
            {
                smallestIndex=k;
            }
        }
        std::swap(referees[smallestIndex], referees[i]);
    }

}

void Leaderboards::SortRefereesByPShots(Referees *referees)
{
    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int smallestIndex=i;

        for(int k=i+1; k<referees->GetNrOfRef(); k++)
        {
            if(referees->GetPShotAtIndex(i)<referees->GetPShotAtIndex(smallestIndex))
            {
                smallestIndex=k;
            }
        }
        std::swap(referees[smallestIndex], referees[i]);
    }

}

void Leaderboards::SortRefereesByGoals(Referees *referees)
{
    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int smallestIndex=i;

        for(int k=i+1; k<referees->GetNrOfRef(); k++)
        {
            if(referees->GetGoalsAtIndex(i)<referees->GetGoalsAtIndex(smallestIndex))
            {
                smallestIndex=k;
            }
        }
        std::swap(referees[smallestIndex], referees[i]);
    }

}

QString Leaderboards::ShowAllseasonLbByMin() const
{
    QString retString="All season Leaderbord by penalty minuts: \n\n";


    SortRefereesByPMin(&this->referees);

    retString+=referees.ToStringLbAllPmin();

    return retString;
}

QString Leaderboards::ShowMontlyLbByMin(int month) const
{
    QDate date;
    date.shortMonthName(month);
    QString toString="";
    QString retString=date.toString("MMM")+ ":s Leaderbord by penalty minuts: \n\n";

    std::vector<PenaltyInfo> pVec=games.GetMonthlyPMin(month);
    for(int i=0; i<pVec.size(); i++)
    {
        int index=referees.FindRefereeById(pVec[i].refID);
        retString+=referees.ToStringForGame(index)+ "n";
        retString+="Penalty minuts: " + toString.setNum(pVec[i].totalPenatlies);
    }

    return retString;


}

QString Leaderboards::ShowAllseasonLbByPShots() const
{
    QString retString="All season Leaderbord by penalty shots: \n\n";


    SortRefereesByPShots(&this->referees);

    retString+=referees.ToStringLbAllPShot();

    return retString;
}

QString Leaderboards::ShowMontlyLbByPShots(int month) const
{
    QDate date;
    date.shortMonthName(month);
    QString toString="";
    QString retString=date.toString("MMM")+ ":s Leaderbord by penalty shots: \n\n";

    std::vector<PenaltyShotInfo> pSVec=games.GetMonthlyPShot(month);
    for(int i=0; i<pSVec.size(); i++)
    {
        int index=referees.FindRefereeById(pSVec[i].refId);
        retString+=referees.ToStringForGame(index)+ "n";
        retString+="Penalty shots: " + toString.setNum(pSVec[i].totalPShots);
    }

    return retString;

}

QString Leaderboards::ShowAllseasonLbByGoals() const
{
    QString retString="All season Leaderbord by goals: \n\n";


    SortRefereesByGoals(&this->referees);

    retString+=referees.ToStringLbAllGoals();

    return retString;
}

QString Leaderboards::ShowMontlyLbByGoals(int month) const
{
    QDate date;
    date.shortMonthName(month);
    QString toString="";
    QString retString=date.toString("MMM")+ ":s Leaderbord by penalty minuts: \n\n";

    std::vector<GoalsInfo> gVec=games.GetMonthlyGoals(month);
    for(int i=0; i<gVec.size(); i++)
    {
        int index=referees.FindRefereeById(gVec[i].refId);
        retString+=referees.ToStringForGame(index)+ "n";
        retString+="Goals: " + toString.setNum(gVec[i].totalGoals);
    }

    return retString;

}

void Leaderboards::SaveLeaderboardsToFile(int saveingAlt,const QString &fileName, int date) const
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream out(&file);

    if(saveingAlt==1)
    {
        out<<ShowAllseasonLbByMin()+"\n\n\n";
        out<<ShowAllseasonLbByPShots()+ "\n\n\n";
        out<<ShowAllseasonLbByGoals() + "\n\n\n";
    }

    if(saveingAlt==2)
    {
        out<<ShowMontlyLbByMin(date)+"\n\n\n";
        out<<ShowMontlyLbByPShots(date)+"\n\n\n";
        out<<ShowMontlyLbByGoals(date)+"\n\n\n";

    }

    if(saveingAlt==3)
    {
        out<<ShowAllseasonLbByMin()+"\n\n\n";
    }
    if(saveingAlt==4)
    {
        out<<ShowAllseasonLbByPShots()+ "\n\n\n";
    }
    if(saveingAlt==5)
    {
        out<<ShowAllseasonLbByGoals() + "\n\n\n";
    }
    if(saveingAlt==6)
    {
        out<<ShowMontlyLbByMin(date)+"\n\n\n";
    }
    if(saveingAlt==7)
    {
        out<<ShowMontlyLbByPShots(date)+"\n\n\n";
    }
    if(saveingAlt==8)
    {
        out<<ShowMontlyLbByGoals(date)+"\n\n\n";
    }


    file.flush();
    file.close();
}
