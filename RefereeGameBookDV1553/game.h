#ifndef GAME_H
#define GAME_H
#include <QString>
#include <QDate>

class Game
{
private:
    QString homeTeam;
    QString guestTeam;
    QDate date;
    int refID;
    int penaltiesMin;
    int penaltyShots;
    int goals;

public:
    Game(const QString& homeTeam, const QString& guestTeam, QDate date, int refID=-1, int penaltiesMin=0,int penaltyShots=0, int goals=0);
    ~Game();

   /* QString GetHomeTeam()const;
    QString GetGuestTeam()const;
    int GetRefID()const;
    int GetPenaltiesMin()const;
    int Ge*/

    void SetRefID(int refID);
    void SetPenaltiesMin(int pMin);
    void SetPenaltyShots(int pShots);
    void SetGoals(int goals);

    QString ToStringReadable();
    QString ToStringSaveable();
    bool operator ==(const Game& other)const;
};

#endif // GAME_H