#include "game.h"
#include "referee.h" //för att hämta domarNamn????

Game::Game(const QString &homeTeam, const QString &guestTeam, QDate date, int refID, int penaltiesMin, int penaltyShots, int goals)
{
    this->homeTeam=homeTeam;
    this->guestTeam=guestTeam;
    this->date=date;
    this->refID=refID;
    this->penaltiesMin=penaltiesMin;
    this->penaltyShots=penaltyShots;
    this->goals=goals;

}

Game::~Game()
{
   //Empty
}

void Game::SetRefID(int refID)
{
    this->refID=refID;
}

void Game::SetPenaltiesMin(int pMin)
{
    this->penaltiesMin=pMin;
}

void Game::SetPenaltyShots(int pShots)
{
    this->penaltyShots=pShots;
}

void Game::SetGoals(int goals)
{
    this->goals=goals;
}

QString Game::ToStringReadable()
{
    QString ret;
    QString convertToQstring;

    ret+="Home team: "+this->homeTeam+"\n";
    ret+="Guest team: "+this->guestTeam+"\n";
    ret+="Date: " + this->date.toString("yyyy-MM-dd");
    ret+="Referee:"+
    ret+="Penalty mins: "+ convertToQstring.setNum(this->penaltiesMin);
    ret+="Penalty shots: "+ convertToQstring.setNum(this->penaltyShots);
    ret+="Goals: "+ convertToQstring.setNum(this->goals);

}

QString Game::ToStringSaveable()
{
    QString ret;
    QString convertToQstring;

    ret+=this->homeTeam+"\n";
    ret+=this->guestTeam+"\n";
    ret+=this->date.toString("yyyy-MM-dd");
    ret+=convertToQstring.setNum(this->refID);
    ret+=convertToQstring.setNum(this->penaltiesMin);
    ret+=convertToQstring.setNum(this->penaltyShots);
    ret+=convertToQstring.setNum(this->goals);
}

bool Game::operator ==(const Game &other) const
{
   return ((this->homeTeam==other.homeTeam)&&(this->guestTeam==other.guestTeam)&&(this->date==other.date));
}
