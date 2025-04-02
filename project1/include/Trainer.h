#ifndef TRAINER_H
#define TRAINER_H

#include "string"
#include "Team.h"

class Trainer
{
  private:
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