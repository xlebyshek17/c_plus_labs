#include "Pokemon.h"
#include "Team.h"
#include "iostream"

Pokemon::Pokemon(const std::string& _name, Team* _team) : Pokemon(name)
{
    if (team)
        team->addPokemon(*this);
    }

void Pokemon::printInfo() const
{
    std::cout << "Pokemon: " << name << " (Type: " << type << ")" << std::endl;
}