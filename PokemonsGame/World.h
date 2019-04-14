//
// Created by Lion on 18.03.2019.
//

#ifndef POKEMONS_WORLD_H
#define POKEMONS_WORLD_H

#include "Location.h"

class World{
public:
    World* createWorld() {
        return new World;
    }
    Location *startLocation;
private:
    Location **location;
};



#endif //POKEMONS_WORLD_H
