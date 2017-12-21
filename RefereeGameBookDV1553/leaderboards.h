#ifndef LEADERBOARDS_H
#define LEADERBOARDS_H
#include "games.h"
#include "teams.h"


class Leaderboards
{
private:
    Referees referees;
    Games games;
    //Teams teams;

public:
    Leaderboards(Referees referees, Games games);
    ~Leaderboards();

    void SortRefereesByPMin(Referees* referees)const;
    void SortRefereesByPShots(Referees* referees)const;
    void SortRefereesByGoals(Referees* referees)const;

    QString ShowAllseasonLbByMin();
    QString ShowMontlyLbByMin(QDate month)const;

    QString ShowAllseasonLbByPShots();
    QString ShowMontlyLbByPShots(QDate month)const;

    QString ShowAllseasonLbByGoals();
    QString ShowMontlyLbByGoals(QDate month)const;

    //void SaveAllLeaderboardsToFile(const QString& fileName)const;
    void SaveLeaderboardsToFile(int saveingAlt, const QString& fileName, QDate date=QDate());
};

#endif // LEADERBOARDS_H
