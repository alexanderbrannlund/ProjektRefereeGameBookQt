#ifndef LEADERBOARDS_H
#define LEADERBOARDS_H
#include "games.h"

class Leaderboards
{
private:
    Referees referees;
    Games games;


public:
    Leaderboards(Referees referees, Games games);
    ~Leaderboards();

    void SortRefereesByPMin(Referees* referees)const;
    void SortRefereesByPShots(Referees* referees)const;
    void SortRefereesByGoals(Referees* referees)const;

    QString ShowAllseasonLbByMin();
    QString ShowMonthlyLbByMin(QDate month)const;

    QString ShowAllseasonLbByPShots();
    QString ShowMonthlyLbByPShots(QDate month)const;

    QString ShowAllseasonLbByGoals();
    QString ShowMonthlyLbByGoals(QDate month)const;


    void SaveLeaderboardsToFile(int saveingAlt, const QString& fileName, QDate date=QDate());
};

#endif // LEADERBOARDS_H
