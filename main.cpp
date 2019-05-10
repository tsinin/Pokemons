#include <iostream>
#include "PokemonsGame/Game.h"


int main(int argc, char* argv[]) {
    Game* game = new Game();
    game->run();
    delete game;
}