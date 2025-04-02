#ifndef POKEMON_H
#define POKEMON_H

#include <string>
class Team;

class Pokemon
{
  private:
    std::string name;
    std::string type;
    Team* team = nullptr;
    
  public:
    Pokemon(const std::string& _name="", const std::string& _type="") : name(_name), type(_type) {}
    Pokemon(const std::string& _name, Team* _team);

    void printInfo() const;

    std::string getName() const { return name; }
};

struct PokemonNode 
{
    PokemonNode *next;
    PokemonNode *prev;
    Pokemon data; 
        
    PokemonNode(const Pokemon& p) : data(p), next(nullptr), prev(nullptr) {}
};

#endif