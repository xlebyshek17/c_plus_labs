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

void Trainer::addTeam(const std::string& teamName)
{
    Team t(teamName);
    addTeam(t);
}

Team& Trainer::operator[](const std::string& teamName)
{
    TeamNode* cur = head;
    while (cur)
    {
        if (cur->data.getName() == teamName)
            return cur->data;
        cur = cur->next;
    }

    throw std::runtime_error("Team not found");
}

void Trainer::printEmptyTeams() const
{
    TeamNode *cur = head;

    if (!cur)
        return;

    std::cout << "Trainer: " << name << " teams (empty): ";
    while (cur)
    {
        if (cur->data.isEmpty())
            std::cout << cur->data.getName();
        cur = cur->next;
        if (cur)
            std::cout << ", ";
    }
    std::cout << std::endl;
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