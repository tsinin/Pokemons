#ifndef POKEMONS_GAME_H
#define POKEMONS_GAME_H
#include "Location.h"
#include "Player.h"
#include "World.h"
#include "Inventory.h"
#include "Pokemon.h"

class Game{
private:
    World *world;
    Location *location;
    short time;
    bool inBattle;
    Player *player;
public:
    Game() {
        world = world->createWorld();
        location = world->startLocation;
        time = 9;
        inBattle = false;
        player = player->createPlayer();
    }
    ~Game() {
        delete world;
        delete location;
        delete player;
    }
    void run() {

    }
};

#endif //POKEMONS_GAME_H
