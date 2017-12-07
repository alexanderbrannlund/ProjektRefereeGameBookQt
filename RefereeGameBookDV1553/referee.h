#ifndef REFEREE_H
#define REFEREE_H
#include <QString>

class Referee
{
private:
    int refID;
    QString firstName;
    QString surName;
    int totalPenalties;
    int totalPenaltyShots;
    int totalGoals;

public:
    //Referee();
    Referee(int refID, const QString& firstName, const QString& surName,int totalPenalties=0, int totalPenaltyShots=0,int totalGoals=0);
    ~Referee();


    int GetRefID() const;
    QString GetFirstName()const;
    QString GetSurName()const;
    int GetTotalPenalties()const;
    int GetTotalPenaltyShots()const;
    int GetTotalGoals()const;
    QString ToStringReadable()const;
    QString ToStringSaveable()const;


    void SetTotalPenalties(int minToAdd);
    void SetTotalPenaltyShots(int toAdd);
    void SetTotalGoals(int goalsToAdd);

    bool operator==(const Referee& other)const;





};

#endif // REFEREE_H
