#include "Pokemon.h"
#include "Team.h"
#include "iostream"

Pokemon::Pokemon(const std::string& _name, Team* _team) : Pokemon(_name)
{
    team = _team;
    if (team)
        team->addPokemon(*this);
    }

void Pokemon::printInfo() const
{
    if (team)
        std::cout << "Pokemon: " << name << " (Team: " << team->getName() << ")\n";
    else
        std::cout << "Pokemon: " << name << std::endl;
}