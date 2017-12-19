#ifndef GAMES_H
#define GAMES_H
#include "game.h"
#include <vector>


struct PenaltyInfo
{
    int refID;
    int totalPenatlies;
};

struct PenaltyShotInfo
{
    int refId;
    int totalPShots;
};

struct GoalsInfo
{
    int refId;
    int totalGoals;
};


class Games
{
private:
    int count;
    int capacity;
    Game** games;
    int FindGame(const Game& game) const;
    void Expand();
    Referees* referees;
public:
    Games(Referees* referees);
    ~Games();

    Games(const Games& other);
    Games& operator=(const Games& other);

    bool AddGame(const QString& homeTeam, const QString& guestTeam, QDate date, int refID=-1, int penaltiesMin=0,int penaltyShots=0, int goals=0);
    bool RemoveGame(const QString& homeTeam, const QString& guestTeam, QDate date);
    void AddGoalsAndPenalties(const QString &homeTeam, const QString &guestTeam, QDate date, int penaltiesMin,int penaltyShots, int goals);
    void ChangeReferee(const QString &homeTeam, const QString &guestTeam, QDate date,int refId);
    int GetNrOfGames()const;
    int GetMonthlyPMin(int refID, int month)const;
    int GetMonthlyPShot(int refID, int month)const;
    int GetMonthlyGoals(int refID, int month)const;

    std::vector<PenaltyInfo> GetMonthlyPMin(int month)const;
    std::vector<PenaltyShotInfo> GetMonthlyPShot(int month)const;
    std::vector<GoalsInfo> GetMonthlyGoals(int month)const;

    QString ToStringSaveable()const;
    QString ToStringReadableOne(const QString& homeTeam, const QString& guestTeam, QDate date)const;
    QString ToStringReadableAll()const;


    void ReadFromFile(const QString& fileName);
    void SaveToFile(const QString& fileName)const;

    void Clear();
};

#endif // GAMES_H
