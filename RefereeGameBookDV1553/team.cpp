#include "team.h"


Team::Team(const QString &teamName, const QString &homeArena)
{
   this->teamName=teamName;
   this->homeArena=homeArena;
}

Team::~Team()
{
    //Tom. Inget dynamiskt allocerat minne i Referee
}

QString Team::GetTeamName() const
{
    return this->teamName;
}

QString Team::GetHomeArenaName() const
{
    return this->homeArena;
}

void Team::SetHomeArenaName(const QString &newName)
{
    this->homeArena=newName;
}

QString Team::ToStringReadable() const
{
    QString ret="";
    ret+="Team name: " + this->teamName + "\n";
    ret+= "Home arena: " + this->homeArena + "\n \n";

    return ret;
}

QString Team::ToStringSaveable() const
{
    QString ret="";
    ret+= this->teamName + "\n";
    ret+= this->homeArena + "\n \n";

    return ret;
}

bool Team::operator ==(const Team &other) const
{
    return this->teamName==other.teamName;
}
