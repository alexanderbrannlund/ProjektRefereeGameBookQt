#ifndef TEAM_H
#define TEAM_H
#include<QString>


class Team
{
private:
    QString teamName;
    QString homeArena;

public:
    Team(const QString& teamName, const QString& homeArena);
    ~Team();

    QString GetTeamName()const;
    QString GetHomeArenaName()const;
    void SetHomeArenaName(const QString& newName);

    QString ToStringReadable()const;
    QString ToStringSaveable()const;

    bool operator ==(const Team& other)const;
};

#endif // TEAM_H
