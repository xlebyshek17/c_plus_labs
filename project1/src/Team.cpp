#include "Team.h"
#include "Pokemon.h"
#include <stdexcept>

void Team::addPokemon(Pokemon& p)
{
    PokemonNode *newNode = new PokemonNode(p);

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

void Team::removePokemon(std::string name)
{
    PokemonNode* cur = head;
    while (cur && cur->data.getName() != name)
        cur = cur->next;

    if (!cur)
        return;

    if (cur == head) {
        head = cur->next;
        if(head)
            head->prev = nullptr;
    } else 
        cur->prev->next = cur->next;
        
    if (cur == tail) {
        tail = cur->prev;
        if (tail)
            cur->prev->next = nullptr;
    } else
        if (cur->next)
            cur->next->prev = cur->prev;

    delete cur;
}

void Team::printPokemonsForward() const
{
    PokemonNode *cur = head;

    if (!cur)
        return;

    while (cur) {
        cur->data.printInfo();
        cur = cur->next;
    }
}

void Team::printPokemonsBackward() const
{
    PokemonNode *cur = tail;

    if (!cur)
        return;

    while (cur) {
        cur->data.printInfo();
        cur = cur->prev;
    }
}

Pokemon& Team::operator[](int index) const 
{
    PokemonNode *cur = head;
    int count = 0;

    while(cur)
    {
        if (count++ == index)
            return cur->data;
        cur = cur->next;
    }

    throw std::out_of_range("Index out of range in Team::operator[]");
}

