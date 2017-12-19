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

    Referees(const Referees& other);
    Referees& operator=(const Referees& other);

    bool AddReferee(const QString& firstName, const QString& surName,int totalPenalties, int totalPenaltyShots,int totalGoals, int refID);
    bool RemoveReferee(const QString& firstName, const QString& surName);
    int GetNrOfRef()const;
    int RetRefId(const QString& firstName, const QString& surName)const;
    int FindRefereeById(int refId)const;
    void AddGameToRef(int index, int addPMin, int addPShot, int addGoals);
    int GetPminAtIndex(int index)const;
    int GetPShotAtIndex(int index)const;
    int GetGoalsAtIndex(int index)const;
    int GetRefId(int index)const;


    QString ToStringLbAllPmin() const;
    QString ToStringLbAllPShot() const;
    QString ToStringLbAllGoals() const;

    QString ToStringSaveable()const;
    QString ToStringReadableOne(const QString& firstName, const QString& surName)const;
    QString ToStringReadableAll()const;
    QString ToStringForGame(int index)const;


    void ReadFromFile(const QString& fileName);
    void SaveToFile(const QString& fileName)const;

    void Clear();


};

#endif // REFEREES_H
