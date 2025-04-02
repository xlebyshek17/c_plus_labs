#ifndef TEAM_H
#define TEAM_H

#include "string"
#include "Pokemon.h"

class Team
{
  private:
    std::string name;
    PokemonNode *head;
    PokemonNode *tail;

  public:
    Team(const std::string& _name) : name(_name), head(nullptr), tail(nullptr) {}

    void addPokemon(Pokemon& p);
    void removePokemon(std::string name);
    Pokemon& operator[](int index) const;
    void printPokemonsForward() const;
    void printPokemonsBackward() const;
    std::string getName() { return name; }

    ~Team() 
    {
        PokemonNode *cur = head;
        while (cur)
        {
            PokemonNode *next = cur->next;
            delete cur;
            cur = next;
        }

        head = nullptr;
        tail = nullptr;
    }
};

struct TeamNode
{
    TeamNode *next;
    TeamNode *prev;
    Team data;

    TeamNode(Team &t) : data(t), next(nullptr), prev(nullptr) {}
};

#endif // !TEAM_H
