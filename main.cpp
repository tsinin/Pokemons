#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "PokemonsGame/Game.h"


int main(int argc, char* argv[]) {
    /*Game* game = new Game();
    game->run();
    delete game;*/
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}