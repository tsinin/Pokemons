//
// Created by Lion on 18.03.2019.
//

#ifndef POKEMONS_WORLD_H
#define POKEMONS_WORLD_H

class World{
public:
    World* createWorld() {
        return new World;
    }
    Location *startLocation;
private:
    Location **location;
};

class IWorldBuilder {

};


#endif //POKEMONS_WORLD_H
