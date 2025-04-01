#include "Pokemon.h"
#include "iostream"

void Pokemon::printInfo() const
{
    std::cout << "Pokemon: " << name << " (Type: " << type << ")" << std::endl;
}