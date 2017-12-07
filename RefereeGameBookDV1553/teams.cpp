#include "teams.h"
#include <QFile>
#include<QTextStream>

int Teams::FindTeam(const Team &team) const
{
    int index = -1;
    for(int i=0; i<count; i++)
    {
        if(team==*teams[i])
        {
            index=i;
            i=count;
        }
    }
    return index;
}

void Teams::Expand()
{
    capacity+=5;

    Team** temp=new Team*[capacity];
    for(int i=0; i<count; i++)
    {
        temp[i]=teams[i];
    }

    delete[] teams;
    teams=temp;
}

Teams::Teams()
{
    this->count=0;
    this->capacity=12;
    teams=new Team*[capacity];
}

Teams::~Teams()
{
    Clear();
    delete[] teams;
}

bool Teams::AddTeam(const QString &teamName, const QString &homeArena)
{
    Team toAdd(teamName,homeArena);


    int index=FindTeam(toAdd);
    if(index==-1)
    {
        if(count==capacity)
        {
            Expand();
        }

        teams[count++]=new Team(toAdd);
    }

    return index==-1;
}

bool Teams::RemoveTeam(const QString &teamName)
{
    Team toRemove(teamName,"ArenaName");
    int index=FindTeam(toRemove);
    if(index!=-1)
    {
       delete teams[index];
        teams[index]=teams[--count];
        teams[count]=nullptr;


    }

    return index!=-1;
}

int Teams::GetNrOfTeams() const
{
    return this->count;
}

QString Teams::ToStringSaveable() const
{
    QString retStr="";

     for(int i=0; i<count; i++)
     {
         retStr+=teams[i]->ToStringSaveable();
     }

     return retStr;

}

QString Teams::ToStringReadableOne(const QString &teamName) const
{
    QString retStr="";
    Team toPrint(teamName,"ArenaName");


    int index=FindTeam(toPrint);
    if(index==-1)
    {
       retStr="Does not exist";
    }
    else
    {
        retStr=teams[index]->ToStringReadable();
    }

    return retStr;
}

QString Teams::ToStringReadableAll() const
{
    QString retStr="";

    for(int i=0; i<count; i++)
    {
        retStr+=teams[i]->ToStringReadable();
    }


    return retStr;
}

void Teams::ReadFromFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream in(&file);
    int teamsInFile=in.readLine().toInt();

    for(int i=0; i<teamsInFile; i++)
    {
        QString teamName=in.readLine();
        QString arenaName= in.readLine();

        AddTeam(teamName, arenaName);
    }

    file.close();
}

void Teams::SaveToFile(const QString &fileName) const
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream out(&file);
    out<<GetNrOfTeams()<<"\n";
    out<<ToStringSaveable();
    file.flush();
    file.close();
}

void Teams::Clear()
{
    for(int i=0; i<count; i++)
    {
        delete teams[i];
    }
    count=0;
}
