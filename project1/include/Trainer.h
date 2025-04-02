#ifndef TRAINER_H
#define TRAINER_H

#include <string>
#include "iostream"
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
    void addTeam(const std::string& teamName);
    Team& operator[](const std::string& teamName);
    void printEmptyTeams() const;
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

    friend std::ostream& operator<<(std::ostream& os, const Trainer& tr)
    {
        TeamNode* cur = tr.head;
        os << "Trainer: " << tr.name << " teams: ";
        while (cur)
        {
            os << cur->data.getName();
            cur = cur->next;
            if (cur)
                os << ", ";
        }
        os << std::endl;
        return os;
    }
};

#endif