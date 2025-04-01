#include "Trainer.h"
#include "Team.h"
#include "iostream"

void Trainer::addTeam(Team &t)
{
    TeamNode *newNode = new TeamNode(t);

    if (!head)
    {
        tail = newNode;
        head = tail;
    }
    else 
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void Trainer::printTeams() const
{
    TeamNode *cur = head;

    if (!cur)
        return;

    std::cout << "Trainer: " << name << std::endl;
    while (cur)
    {
        std::cout << " - " << cur->data.getName() << std::endl;
        cur = cur->next;
    }
}