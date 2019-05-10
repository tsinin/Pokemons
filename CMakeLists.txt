cmake_minimum_required(VERSION 3.10)
project(Pokemons)

set(CMAKE_CXX_STANDARD 17)

option(TEST "Build tests instead of program" OFF)

if(TEST)
    add_subdirectory(google-tests/googletest-master)
    include_directories(google-tests/googletest-master/googletest/include)
    include_directories(google-tests/googletest-master/googlemock/include)
    add_executable(Pokemons
            mainForTest.cpp
            test.cpp
            PokemonsGame/Game.h
            PokemonsGame/Location.h
            PokemonsGame/Player.h
            PokemonsGame/Pokemon.h
            PokemonsGame/Ability.h
            PokemonsGame/Battle.h)
    target_link_libraries(Pokemons gtest gtest_main)
else()
    add_executable(Pokemons
            main.cpp
            PokemonsGame/Game.h
            PokemonsGame/Location.h
            PokemonsGame/Player.h
            PokemonsGame/Pokemon.h
            PokemonsGame/Ability.h
            PokemonsGame/Battle.h)
endif()
