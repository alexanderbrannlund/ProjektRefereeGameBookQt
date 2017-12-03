#ifndef TEAMS_H
#define TEAMS_H
#include "team.h"


class Teams
{
private:
    int count;
    int capacity;
    Team** teams;
    int FindTeam(const Team& team) const;
    void Expand();
public:
    Teams();
    ~Teams();

    bool AddTeam(const QString& teamName, const QString& homeArena);
    bool RemoveTeam(const QString& teamName);
    int GetNrOfTeams()const;

    QString ToStringSaveable()const;
    QString ToStringReadableOne(const QString& teamName)const;
    QString ToStringReadableAll()const;


    void ReadFromFile(const QString& fileName);
    void SaveToFile(const QString& fileName)const;

    void Clear();

};

#endif // TEAMS_H
