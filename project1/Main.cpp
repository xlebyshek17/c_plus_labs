// Proszę dopisać kod, dodać nowe pliki, tak aby program wykonywał się,
// a wynik jego działania był taki sam jak podany na końcu tego pliku.
//
// Celem zadania jest rozszerzenie kodu źródłowego projektu z implementacją systemu
// zarządzania drużynami Pokémonów, gdzie dane powinny być przechowywane w listach dwukierunkowych,
// bez użycia kontenerów STL, takich jak `std::vector` czy `std::list`
// Założenia do ogólnej struktury projektu:
// - PokemonNode powinien być zdefiniowany w tym samym pliku co klasa Pokemon
// - TeamNode powinien być zdefiniowany w tym samym pliku co klasa Team
// 
// Zadaniem w ramach zajęć są tematy:
// - niejawna konwersja typów
// - różne operatory, operator przypisania kopiującego
// - niestandardowy konstruktor kopiujący 
// UWAGA: co potrzebne proszę wywnioskować z treści funkcji main

// Jeśli wystarczy czasu, proszę przeanalizować ostatnią cześć
// rozróżniającą T(){} od konstruktora trywialnego

// Proszę zadbać o dobre zarządzanie pamięcią.
// Plik Main.cpp w przesłanym rozwiązaniu powinien być niezmodyfikowany.
// Struktura programu powinna być oparta o definicję zawartą w pliku CMakeLists.txt
//
// Ostateczny program powinien być przyjazny dla programisty (mieć czytelny i dobrze napisany kod),
// oraz powinna być spełniona zasada D.R.Y. - Don't Repeat Yourself.

#include "Trainer.h"
#include "Team.h"
#include "Pokemon.h"
#include <type_traits>
#include <iostream>

class Pokeball {};

class GreatBall {
public:
    GreatBall(){} // Brak domyślnego konstruktora?
};

class UltraBall {
public:
    UltraBall(int effectiveness) {} // Brak domyślnego konstruktora
};

int main() {
    Trainer ash("Ash Ketchum");

    // Tworzymy i dodajemy drużyny do trenera
    ash.addTeam("Hoenn Team");   // Niejawna konwersja typów
    ash.addTeam("Sinnoh Team");
    ash.addTeam("Unova Team");

    Team& hoenn = ash["Hoenn Team"];
    const Team& unova = ash["Unova Team"];

    // Dodajemy Pokémony
    Pokemon p1("Grovyle", &hoenn);
    Pokemon p2("Infernape", &(ash["Sinnoh Team"]));

    // Wypisujemy drużyny trenera
    std::cout << ash << std::endl; // Skorzystać z wcześniejszej metody printTeams

    // Wypisujemy drużyny bez Pokémonów
    ash.printEmptyTeams(); 
    
    p1.printInfo();
    Pokemon p3 = hoenn[0]; // UWAGA: Pokémon p3 NIE należy do Hoenn Team
    p3.printInfo();

    auto printMsgDefaultConstructible = [](const std::string& className, bool isDefaultConstr) {
        std::cout << "Is " << className << " default constructible? " 
                  << std::boolalpha << isDefaultConstr << std::endl;
    };

    printMsgDefaultConstructible("Pokeball", std::is_trivially_default_constructible<Pokeball>::value);
    printMsgDefaultConstructible("UltraBall", std::is_trivially_default_constructible<UltraBall>::value);
    printMsgDefaultConstructible("GreatBall", std::is_trivially_default_constructible<GreatBall>::value);
    printMsgDefaultConstructible("GreatBall", std::is_default_constructible<GreatBall>::value); // Jaka jest różnica względem is_trivially_default_constructible?

    return 0;
}

/* wynik działania:
Trainer: Ash Ketchum teams: Hoenn Team, Sinnoh Team, Unova Team,
Trainer: Ash Ketchum teams (empty): Unova Team,
Pokemon: Grovyle (Team: Hoenn Team)
Pokemon: Grovyle
Is Pokeball default constructible? true
Is UltraBall default constructible? false
Is GreatBall default constructible? false
Is GreatBall default constructible? true
*/