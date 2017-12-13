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

int Game::GetRefID() const
{
    return this->refID;
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

QString Game::ToStringReadable(Referees* referees)
{
    QString ret;
    QString convertToQstring;
    if(refID!=-1)
    {
        int index=referees->FindRefereeById(refID);
        ret+="Home team: "+this->homeTeam+"\n";
        ret+="Guest team: "+this->guestTeam+"\n";
        ret+="Date: " + this->date.toString("yyyy-MM-dd")+"\n";
        ret+="Referee:" + referees->ToStringForGame(index)+"\n";
        ret+="Penalty mins: "+ convertToQstring.setNum(this->penaltiesMin)+"\n";
        ret+="Penalty shots: "+ convertToQstring.setNum(this->penaltyShots)+"\n";
        ret+="Goals: "+ convertToQstring.setNum(this->goals)+"\n";
    }

    else
    {
        ret+="Home team: "+this->homeTeam+"\n";
        ret+="Guest team: "+this->guestTeam+"\n";
        ret+="Date: " + this->date.toString("yyyy-MM-dd")+"\n";
        ret+="Referee: No referee has been given the game\n";
        ret+="Penalty mins: "+ convertToQstring.setNum(this->penaltiesMin)+"\n";
        ret+="Penalty shots: "+ convertToQstring.setNum(this->penaltyShots)+"\n";
        ret+="Goals: "+ convertToQstring.setNum(this->goals)+"\n";
    }



    return ret;

}

QString Game::ToStringSaveable()
{
    QString ret;
    QString convertToQstring;

    ret+=this->homeTeam+"\n";
    ret+=this->guestTeam+"\n";
    ret+=this->date.toString("yyyy-MM-dd")+"\n";
    ret+=convertToQstring.setNum(this->refID)+"\n";
    ret+=convertToQstring.setNum(this->penaltiesMin)+"\n";
    ret+=convertToQstring.setNum(this->penaltyShots)+"\n";
    ret+=convertToQstring.setNum(this->goals)+"\n";
    return ret;
}

bool Game::operator ==(const Game &other) const
{
   return ((this->homeTeam==other.homeTeam)&&(this->guestTeam==other.guestTeam)&&(this->date==other.date));
}
