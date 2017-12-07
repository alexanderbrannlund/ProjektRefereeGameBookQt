#include "referees.h"
#include <QFile>
#include <QTextStream>

int Referees::FindReferee(const Referee &ref) const
{
    int index = -1;
    for(int i=0; i<count; i++)
    {
        if(ref==*referees[i])
        {
            index=i;
            i=count;
        }
    }
    return index;
}

void Referees::Expand()
{
    capacity+=5;

    Referee** temp=new Referee*[capacity];
    for(int i=0; i<count; i++)
    {
        temp[i]=referees[i];
    }

    delete[] referees;
    referees=temp;
}

Referees::Referees()
{
    this->count=0;
    this->capacity=5; //för test-->öka sen
    referees=new Referee*[capacity];

}

Referees::~Referees()
{
    Clear();
    delete[] referees;

}

bool Referees::AddReferee(const QString &firstName, const QString &surName, int totalPenalties, int totalPenaltyShots, int totalGoals,int refID)
{

    if(refID==-1){
        refID=this->count;

    }

    Referee toAdd(this->count,firstName, surName, totalPenalties, totalPenaltyShots, totalGoals);


    int index=FindReferee(toAdd);
    if(index==-1)
    {
        if(count==capacity)
        {
            Expand();
        }

        referees[count++]=new Referee(toAdd);
    }

    return index==-1;

}

bool Referees::RemoveReferee(const QString &firstName, const QString &surName)
{
    Referee toRemove(-11,firstName, surName);
    int index=FindReferee(toRemove);
    if(index!=-1)
    {
       delete referees[index];
        referees[index]=referees[--count];
        referees[count]=nullptr;


    }

    return index!=-1;


}

int Referees::GetNrOfRef() const
{
    return this->count;
}

int Referees::FindRefereeById(int refId)
{
    int index;
    for(int i=0; i<count; i++)
    {
        if(refId==referees[i]->GetRefID())
        {
            index=i;
            i=count;
        }
    }

    return index;
}

void Referees::AddGameToRef(int index, int addPMin, int addPShot, int addGoals)
{
    referees[index]->SetTotalPenalties(addPMin);
    referees[index]->SetTotalPenaltyShots(addPShot);
    referees[index]->SetTotalGoals(addGoals);
}

QString Referees::ToStringSaveable() const
{
   QString retStr="";

    for(int i=0; i<count; i++)
    {
        retStr+=referees[i]->ToStringSaveable();
    }

    return retStr;

}

QString Referees::ToStringReadableAll() const
{
    QString retStr="";

    for(int i=0; i<count; i++)
    {
        retStr+=referees[i]->ToStringReadable();
    }


    return retStr;

}

QString Referees::ToStringForGame(int index) const
{
    QString ret;

    if(index!=-1)
        ret+=referees[index]->GetFirstName()+" "+referees[index]->GetSurName();

    return ret;
}

QString Referees::ToStringReadableOne(const QString& firstName, const QString& surName) const
{
    QString retStr="";
    Referee toPrint(-11,firstName, surName, 0, 0, 0);


    int index=FindReferee(toPrint);
    if(index==-1)
    {
       retStr="Does not exist";
    }
    else
    {
        retStr=referees[index]->ToStringReadable();
    }

    return retStr;

}

void Referees::ReadFromFile(const QString& fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream out(stdout);
        out<<"Fil is not open..."<< "\n";

    }
    QTextStream in(&file);
    int refsInFile=in.readLine().toInt();
    for(int i=0; i<refsInFile; i++ )
    {
       int refId=in.readLine().toInt();
       QString firstName=in.readLine();
       QString surName= in.readLine();
       int penaltieMins=in.readLine().toInt();
       int penaltyShots=in.readLine().toInt();
       int goals=in.readLine().toInt();
       AddReferee(firstName,surName,penaltieMins,penaltyShots,goals,refId);
    }
    file.close();

}

void Referees::SaveToFile(const QString& fileName) const
{
            QFile file(fileName);
            if(!file.open(QFile::WriteOnly | QFile::Text))
            {
                QTextStream out(stdout);
                out<<"Fil is not open..."<< "\n";

            }
            QTextStream out(&file);
            out<<GetNrOfRef()<<"\n";
            out<<ToStringSaveable();
            file.flush();
            file.close();



}

void Referees::Clear()
{
    for(int i=0; i<count; i++)
    {
        delete referees[i];
    }
    count=0;

}
