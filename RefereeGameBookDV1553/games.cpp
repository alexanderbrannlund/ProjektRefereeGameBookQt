#include "games.h"
#include <QFile>
#include <QTextStream>



int Games::FindGame(const Game &game) const
{
    int index = -1;
    for(int i=0; i<count; i++)
    {
        if(game==*games[i])
        {
            index=i;
            i=count;
        }
    }
    return index;
}

void Games::Expand()
{
    capacity+=5;

    Game** temp=new Game*[capacity];
    for(int i=0; i<count; i++)
    {
        temp[i]=games[i];
    }

    delete[] games;
    games=temp;
}

Games::Games(Referees* referees)
{
    this->count=0;
    this->capacity=5; //för test-->öka sen
    games=new Game*[capacity];
    this->referees=referees;
}

Games::~Games()
{
    Clear();
    delete[] games;
}

bool Games::AddGame(const QString &homeTeam, const QString &guestTeam, QDate date, int refID, int penaltiesMin, int penaltyShots, int goals)
{
    Game toAdd(homeTeam, guestTeam, date, refID,penaltiesMin,penaltyShots, goals);


    int index=FindGame(toAdd);
    if(index==-1)
    {
        if(count==capacity)
        {
            Expand();
        }

        games[count++]=new Game(toAdd);
    }

    return index==-1;
}


bool Games::RemoveGame(const QString &homeTeam, const QString &guestTeam, QDate date)
{
    Game toRemove(homeTeam,guestTeam,date);
    int index=FindGame(toRemove);
    if(index!=-1)
    {
       delete games[index];
        games[index]=games[--count];
        games[count]=nullptr;


    }

    return index!=-1;
}

void Games::AddGoalsAndPenalties(const QString &homeTeam, const QString &guestTeam, QDate date, int penaltiesMin, int penaltyShots, int goals)
{
    Game toManage(homeTeam, guestTeam, date);
    int index=FindGame(toManage);

    if(index!=-1)
    {
        games[index]->SetPenaltiesMin(penaltiesMin);
        games[index]->SetPenaltyShots(penaltyShots);
        games[index]->SetGoals(goals);
    }
}

void Games::ChangeReferee(const QString &homeTeam, const QString &guestTeam, QDate date, int refId)
{
    Game toManage(homeTeam, guestTeam, date);
    int index=FindGame(toManage);

    if(index!=-1)
    {
        games[index]->SetRefID(refId);

    }
}

int Games::GetNrOfGames() const
{
    return this->count;
}

QString Games::ToStringSaveable() const
{
    QString retStr="";

     for(int i=0; i<count; i++)
     {
         retStr+=games[i]->ToStringSaveable();
     }

     return retStr;
}

QString Games::ToStringReadableOne(const QString &homeTeam, const QString &guestTeam, QDate date) const
{
    QString retStr="";
    Game toPrint(homeTeam,guestTeam,date);


    int index=FindGame(toPrint);
    if(index==-1)
    {
       retStr="Does not exist";
    }
    else
    {
        retStr=games[index]->ToStringReadable(referees);
    }

    return retStr;
}

QString Games::ToStringReadableAll() const
{
    QString retStr="";

    for(int i=0; i<count; i++)
    {
        retStr+=games[i]->ToStringReadable(referees);
    }


    return retStr;
}

void Games::ReadFromFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream in(&file);
    int gamesInFile=in.readLine().toInt();
    for(int i=0; i<gamesInFile; i++ )
    {

       QString homeTeam=in.readLine();
       QString guestTeam= in.readLine();
       QDate date=QDate::fromString(in.readLine(),"YYYY-MM-dd");
       int refId=in.readLine().toInt();
       int penaltieMins=in.readLine().toInt();
       int penaltyShots=in.readLine().toInt();
       int goals=in.readLine().toInt();
       AddGame(homeTeam, guestTeam,date,refId,penaltieMins,penaltyShots,goals);
    }
    file.close();
}

void Games::SaveToFile(const QString &fileName) const
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream out(&file);
    out<<GetNrOfGames()<<"\n";
    out<<ToStringSaveable();
    file.flush();
    file.close();
}

void Games::Clear()
{
    for(int i=0; i<count; i++)
    {
        delete games[i];
    }
    count=0;
}
