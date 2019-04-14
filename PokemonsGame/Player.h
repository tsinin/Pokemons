#ifndef POKEMONS_PLAYER_H
#define POKEMONS_PLAYER_H
#include "Inventory.h"
#include "Pokemon.h"

class Player{
public:

private:
    std::string name;
    Inventory* inventory;
    Pokemon* pokemons[6];
};

#endif //POKEMONS_PLAYER_H
