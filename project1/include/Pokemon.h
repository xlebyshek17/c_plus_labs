#ifndef POKEMON_H
#define POKEMON_H

#include "string"

class Pokemon
{
  private:
    std::string name;
    std::string type;
    
  public:
    Pokemon(const std::string& _name, const std::string& _type) : name(_name), type(_type) {}

    void printInfo() const;

    std::string getName() const { return name; }
};

#endif