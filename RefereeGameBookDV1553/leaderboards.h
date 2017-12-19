#ifndef LEADERBOARDS_H
#define LEADERBOARDS_H
#include "games.h"
#include "teams.h"


class Leaderboards
{
private:
    Referees referees;
    Games games;
    Teams teams;

public:
    Leaderboards(Referees referees, Games games, Team teams);
    ~Leaderboards();

    void SortRefereesByPMin(Referees* referees);
    void SortRefereesByPShots(Referees* referees);
    void SortRefereesByGoals(Referees* referees);

    QString ShowAllseasonLbByMin()const;
    QString ShowMontlyLbByMin(int month)const;

    QString ShowAllseasonLbByPShots()const;
    QString ShowMontlyLbByPShots(int month)const;

    QString ShowAllseasonLbByGoals()const;
    QString ShowMontlyLbByGoals(int month)const;

    //void SaveAllLeaderboardsToFile(const QString& fileName)const;
    void SaveLeaderboardsToFile(int saveingAlt, const QString& fileName, int date=0)const;
};

#endif // LEADERBOARDS_H
