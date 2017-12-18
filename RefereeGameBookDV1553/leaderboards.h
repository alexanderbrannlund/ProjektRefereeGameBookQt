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
    QString ShowMontlyLbByMin(QDate month)const;

    QString ShowAllseasonLbByPShots()const;
    QString ShowMontlyLbByPShots(QDate month)const;

    QString ShowAllseasonLbByGoals()const;
    QString ShowMontlyLbByGoals(QDate month)const;

    //void SaveAllLeaderboardsToFile(const QString& fileName)const;
    void SaveLeaderboardsToFile(int saveingAlt, const QString& fileName)const;
};

#endif // LEADERBOARDS_H
