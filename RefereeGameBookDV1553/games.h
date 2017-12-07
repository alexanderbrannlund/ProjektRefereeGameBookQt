#ifndef GAMES_H
#define GAMES_H
#include "game.h"



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

    bool AddGame(const QString& homeTeam, const QString& guestTeam, QDate date, int refID=-1, int penaltiesMin=0,int penaltyShots=0, int goals=0);
    bool RemoveGame(const QString& homeTeam, const QString& guestTeam, QDate date);
    void AddGoalsAndPenalties(const QString &homeTeam, const QString &guestTeam, QDate date, int penaltiesMin,int penaltyShots, int goals);
    void ChangeReferee(const QString &homeTeam, const QString &guestTeam, QDate date,int refId);
    int GetNrOfGames()const;

    QString ToStringSaveable()const;
    QString ToStringReadableOne(const QString& homeTeam, const QString& guestTeam, QDate date)const;
    QString ToStringReadableAll()const;


    void ReadFromFile(const QString& fileName);
    void SaveToFile(const QString& fileName)const;

    void Clear();
};

#endif // GAMES_H
