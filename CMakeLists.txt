cmake_minimum_required(VERSION 3.10)
project(Pokemons)

SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin" CACHE PATH "Single output directory for building all executables." FORCE)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(google-tests/googletest-master)
include_directories(google-tests/googletest-master/googletest/include)
include_directories(google-tests/googletest-master/googlemock/include)

add_executable(Pokemons main.cpp Pokemons/Game.h Pokemons/World.h Pokemons/Location.h Pokemons/Player.h Pokemons/Inventory.h Pokemons/Pokemon.h test.cpp)
target_link_libraries(Pokemons gtest gtest_main)
