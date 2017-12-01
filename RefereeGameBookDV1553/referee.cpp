#include <referee.h>

Referee::Referee(int refID, const QString &firstName, const QString &surName, int totalPenalties, int totalPenaltyShots, int totalGoals)
{
    this->refID=refID;
    this->firstName=firstName;
    this->surName=surName;
    this->totalPenalties=totalPenalties;
    this->totalPenaltyShots=totalPenaltyShots;
    this->totalGoals=totalGoals;

}

Referee::~Referee()
{
  //Tom. Inget dynamiskt allocerat minne i Referee
}

int Referee::GetRefID() const
{
    return this->refID;
}

QString Referee::GetFirstName() const
{
    return this->firstName;
}

QString Referee::GetSurName() const
{
    return this->surName;
}

int Referee::GetTotalPenalties() const
{
    return this->totalPenalties;
}

int Referee::GetTotalPenaltyShots() const
{
    return this->totalPenaltyShots;
}

int Referee::GetTotalGoals() const
{
    return this->totalGoals;
}

QString Referee::ToStringSaveable() const
{
  QString ret;
  QString convertInt;
  ret+= convertInt.setNum(this->refID)+"\n";
  ret+= this->firstName+"\n";
  ret+= this->surName+"\n";
  ret+= convertInt.setNum(this->totalPenalties)+"\n";
  ret+= convertInt.setNum(this->totalPenaltyShots)+"\n";
  ret+= convertInt.setNum(this->totalGoals)+"\n";

  return ret;
}

QString Referee::ToStringReadable() const
{
    QString ret;
    QString convertInt;
    ret+= "Ref Id: " + convertInt.setNum(this->refID)+"\n";
    ret+= "First name: " + this->firstName + "\n";
    ret+= "Surname: " + this->surName+"\n";
    ret+= "Total number of penalty minutes called: " + convertInt.setNum(this->totalPenalties)+"\n";
    ret+= "Total number of penalty shots called: " + convertInt.setNum(this->totalPenaltyShots)+"\n";
    ret+= "Total number of goals called: " + convertInt.setNum(this->totalGoals)+"\n\n";

    return ret;
}

void Referee::SetTotalPenalties(int minToAdd)
{
    this->totalPenalties+=minToAdd;
}

void Referee::SetTotalPenaltyShots(int toAdd)
{
    this->totalPenaltyShots+=toAdd;
}

void Referee::SetTotalGoals(int goalsToAdd)
{
    this->totalGoals+=goalsToAdd;
}

bool Referee::operator==(const Referee &other) const
{
   bool same=false;

   if((this->firstName==other.firstName) && (this->surName==other.surName) )
   {
       same=true;
   }

   return same;
}
