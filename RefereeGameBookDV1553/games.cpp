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

Games::Games(const Games &other)
{
    this->count=other.count;
    this->capacity=other.capacity;
    this->games=new Game*[this->capacity];
    this->referees=other.referees;

    for(int i=0; i<count; i++)
    {
        this->games[i]= new Game(*other.games[i]);
    }
}

Games &Games::operator=(const Games &other)
{
    if(this != &other)
    {
        for(int i= 0; i<this->count; i++)
        {
            delete this->games[i];
        }
        delete[] this->games;

        this->count=other.count;
        this->capacity=other.capacity;
        this->games=new Game*[this->capacity];
        this->referees=other.referees;

        for(int i=0; i<count; i++)
        {
            this->games[i]= new Game(*other.games[i]);
        }
    }
    return *this;
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

        referees->AddGameToRef(referees->FindRefereeById(games[index]->GetRefID()),penaltiesMin,penaltyShots, goals);

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

int Games::GetMonthlyPMin(int refID, QDate month) const
{
   int pMinCount=0;
   for(int i=0; i<count; i++)
   {
       if(games[i]->GetDate().month()==month.month())
       {
           if(games[i]->GetRefID()==refID)
           {
               pMinCount+=games[i]->GetPenaltiesMin();
           }
       }
   }
   return pMinCount;
}

int Games::GetMonthlyPShot(int refID, QDate month) const
{
    int pShotCount=0;
    for(int i=0; i<count; i++)
    {
        if(games[i]->GetDate().month()==month.month())
        {
            if(games[i]->GetRefID()==refID)
            {
                pShotCount+=games[i]->GetPenaltyShots();
            }
        }
    }
    return pShotCount;
}

int Games::GetMonthlyGoals(int refID, QDate month) const
{
    int goalsCount=0;
    for(int i=0; i<count; i++)
    {
        if(games[i]->GetDate().month()==month.month())
        {
            if(games[i]->GetRefID()==refID)
            {
                goalsCount+=games[i]->GetGoals();
            }
        }
    }
    return goalsCount;
}

std::vector<PenaltyInfo> Games::GetMonthlyPMin(QDate month)const
{
    std::vector<PenaltyInfo> pVec;

    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int refid=referees->GetRefId(i);
        int pMin=GetMonthlyPMin(refid,month);
        PenaltyInfo ref;
        ref.refID=refid;
        ref.totalPenatlies=pMin;

        pVec.push_back(ref);
    }
    for(int i=0; i<pVec.size()-1; i++)
    {
        int highestIndex=i;
        for(int k=i; k<pVec.size(); k++)
        {
            if(pVec[k].totalPenatlies>pVec[highestIndex].totalPenatlies)
            {
                highestIndex=k;
            }
        }
        std::swap(pVec[highestIndex],pVec[i]);
    }
    return pVec;
}

std::vector<PenaltyShotInfo> Games::GetMonthlyPShot(QDate month)const
{
    std::vector<PenaltyShotInfo> pSVec;
    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int refid=referees->GetRefId(i);
        int pShots=GetMonthlyPShot(refid,month);
        PenaltyShotInfo ref;
        ref.refId=refid;
        ref.totalPShots=pShots;

        pSVec.push_back(ref);
    }
    for(int i=0; i<pSVec.size()-1; i++)
    {
        int highestIndex=i;
        for(int k=i; k<pSVec.size(); k++)
        {
            if(pSVec[k].totalPShots>pSVec[highestIndex].totalPShots)
            {
                highestIndex=k;
            }
        }
        std::swap(pSVec[highestIndex],pSVec[i]);
    }
    return pSVec;
}

std::vector<GoalsInfo> Games::GetMonthlyGoals(QDate month)const
{
    std::vector<GoalsInfo> gVec;
    for(int i=0; i<referees->GetNrOfRef()-1; i++)
    {
        int refid=referees->GetRefId(i);
        int goals=GetMonthlyGoals(refid,month);
        GoalsInfo ref;
        ref.refId=refid;
        ref.totalGoals=goals;

        gVec.push_back(ref);
    }
    for(int i=0; i<gVec.size()-1; i++)
    {
        int highestIndex=i;
        for(int k=i; k<gVec.size(); k++)
        {
            if(gVec[k].totalGoals>gVec[highestIndex].totalGoals)
            {
                highestIndex=k;
            }
        }
        std::swap(gVec[highestIndex],gVec[i]);
    }
    return gVec;
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
        retStr+=games[i]->ToStringReadable(referees)+"\n";
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
       QString date=in.readLine();
       int refId=in.readLine().toInt();
       int penaltieMins=in.readLine().toInt();
       int penaltyShots=in.readLine().toInt();
       int goals=in.readLine().toInt();

       QDate toDate=QDate::fromString(date,"yyyy-MM-dd");

       AddGame(homeTeam, guestTeam,toDate,refId,penaltieMins,penaltyShots,goals);
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
