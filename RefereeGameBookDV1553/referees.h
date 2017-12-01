#ifndef REFEREES_H
#define REFEREES_H
#include "referee.h"

class Referees
{
private:
    int count;
    int capacity;
    Referee** referees;
    int FindReferee(const Referee& ref) const;
    void Expand();

public:
    Referees();
    ~Referees();

    bool AddReferee(const QString& firstName, const QString& surName,int totalPenalties, int totalPenaltyShots,int totalGoals, int refID);
    bool RemoveReferee(const QString& firstName, const QString& surName);
    int GetNrOfRef()const;

    QString ToStringSaveable()const;
    QString ToStringReadableOne(const QString& firstName, const QString& surName)const;
    QString ToStringReadableAll()const;


    void ReadFromFile(QString fileName);
    void SaveToFile(QString fileName);

    void Clear();


};

#endif // REFEREES_H
