#ifndef TRAINER_H
#define TRAINER_H

#include "string"
#include "Team.h"

class Trainer
{
  private:
    struct TeamNode
    {
        TeamNode *next;
        TeamNode *prev;
        Team data;

        TeamNode(Team &t) : data(t), next(nullptr), prev(nullptr) {}
    };

    std::string name;
    TeamNode *head;
    TeamNode *tail;
  public:
    Trainer(const std::string& _name): name(_name), head(nullptr), tail(nullptr) {}

    void addTeam(Team &team);
    void printTeams() const;

    ~Trainer()
    {
        TeamNode *cur = head;
        while (cur)
        {
            TeamNode *next = cur->next;
            delete cur;
            cur = next;
        }

        head = nullptr;
        tail = nullptr;
    }
};

#endif