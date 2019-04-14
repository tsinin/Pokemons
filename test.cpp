//
// Created by Tsinin on 27.10.2018.
//
#include <ctime>
#include <set>
#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "PokemonsGame/Game.h"

using testing::Eq;

namespace {
    class testFixture : public testing::Test {
    };
}

TEST_F(testFixture, PokemonDefaultConstructorTest) {
    Pokemon *pokemon = new Pokemon;
    ASSERT_EQ(pokemon->getId(), 0);
    ASSERT_EQ(pokemon->getName(), "");
    ASSERT_EQ(pokemon->getNextPokemon(), 0);
    ASSERT_EQ(pokemon->getLevel(), 0);
    ASSERT_EQ(pokemon->getMaxLevel(), 0);
    ASSERT_EQ(pokemon->getHp(), 0);
    ASSERT_EQ(pokemon->getMaxHp(), 0);
    ASSERT_EQ(pokemon->getAttack(), 0);
    ASSERT_EQ(pokemon->getDefense(), 0);
    ASSERT_EQ(pokemon->getSpAttack(), 0);
    ASSERT_EQ(pokemon->getSpDefense(), 0);
    ASSERT_EQ(pokemon->getSpeed(), 0);
    ASSERT_TRUE(pokemon->getTypes().empty());
}

TEST_F(testFixture, PokemonIdSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setId(2);
    ASSERT_EQ(pokemon->getId(), 2);
}

TEST_F(testFixture, PokemonNameSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setName("The best pokemon");
    ASSERT_EQ(pokemon->getName(), "The best pokemon");
}

TEST_F(testFixture, PokemonNextPokemonSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setNextPokemon(3);
    ASSERT_EQ(pokemon->getNextPokemon(), 3);
}

TEST_F(testFixture, PokemonLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setLevel(100);
    ASSERT_EQ(pokemon->getLevel(), 100);
}

TEST_F(testFixture, PokemonMaxLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxLevel(100);
    ASSERT_EQ(pokemon->getMaxLevel(), 100);
}

TEST_F(testFixture, PokemonHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setHp(100500);
    ASSERT_EQ(pokemon->getHp(), 100500);
}

TEST_F(testFixture, PokemonMaxHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxHp(100500);
    ASSERT_EQ(pokemon->getMaxHp(), 100500);
}

TEST_F(testFixture, PokemonAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setAttack(100500);
    ASSERT_EQ(pokemon->getAttack(), 100500);
}

TEST_F(testFixture, PokemonDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setDefense(100500);
    ASSERT_EQ(pokemon->getDefense(), 100500);
}

TEST_F(testFixture, PokemonSpAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpAttack(100500);
    ASSERT_EQ(pokemon->getSpAttack(), 100500);
}

TEST_F(testFixture, PokemonSpDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpDefense(100500);
    ASSERT_EQ(pokemon->getSpDefense(), 100500);
}

TEST_F(testFixture, PokemonSpeedSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpeed(100500);
    ASSERT_EQ(pokemon->getSpeed(), 100500);
}

TEST_F(testFixture, PokemonTypeAddGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->addType(Normal);
    ASSERT_EQ(pokemon->getTypes(), std::vector<pokType>(1, Normal));
}

TEST_F(testFixture, PokemonPokTypeToStringTest) {
    ASSERT_EQ(toString(Poison), "Poison");
}

TEST_F(testFixture, PokemonStringToPokTypeTest1) {
    ASSERT_EQ(toPokType("Poison"), Poison);
}

TEST_F(testFixture, PokemonStringToPokTypeTest2) {
    ASSERT_EQ(toPokType("The type that is not exist"), Unknown);
}

TEST_F(testFixture, PokedexCloneTest) {
    Pokemon *pokemon = nullptr;
    pokemon = PokemonPrototype::clone(1, 10);
    ASSERT_EQ(pokemon->getId(), 1);
    ASSERT_EQ(pokemon->getName(), "Bulbasaur");
    ASSERT_EQ(pokemon->getNextPokemon(), 2);
    ASSERT_EQ(pokemon->getLevel(), 10);
    ASSERT_EQ(pokemon->getMaxLevel(), 15);
    ASSERT_EQ(pokemon->getHp(), 45);
    ASSERT_EQ(pokemon->getMaxHp(), 45);
    ASSERT_EQ(pokemon->getAttack(), 49);
    ASSERT_EQ(pokemon->getDefense(), 49);
    ASSERT_EQ(pokemon->getSpAttack(), 65);
    ASSERT_EQ(pokemon->getSpDefense(), 65);
    ASSERT_EQ(pokemon->getSpeed(), 45);
    std::vector<pokemonId> types;
    types.push_back(Grass);
    types.push_back(Poison);
    for(int i = 0; i < types.size(); i++)
        ASSERT_EQ(pokemon->getTypes()[i], types[i]);
}

TEST_F(testFixture, PokemonCopyConstructorTest) {
    Pokemon *pokemon1;
    pokemon1 = PokemonPrototype::clone(1, 10);
    auto *pokemon2 = new Pokemon(*pokemon1);
    ASSERT_EQ(pokemon2->getId(), 1);
    ASSERT_EQ(pokemon2->getName(), "Bulbasaur");
    ASSERT_EQ(pokemon2->getNextPokemon(), 2);
    ASSERT_EQ(pokemon2->getLevel(), 10);
    ASSERT_EQ(pokemon2->getMaxLevel(), 15);
    ASSERT_EQ(pokemon2->getHp(), 45);
    ASSERT_EQ(pokemon2->getMaxHp(), 45);
    ASSERT_EQ(pokemon2->getAttack(), 49);
    ASSERT_EQ(pokemon2->getDefense(), 49);
    ASSERT_EQ(pokemon2->getSpAttack(), 65);
    ASSERT_EQ(pokemon2->getSpDefense(), 65);
    ASSERT_EQ(pokemon2->getSpeed(), 45);
    std::vector<pokemonId> types;
    types.push_back(Grass);
    types.push_back(Poison);
    for(int i = 0; i < types.size(); i++)
        ASSERT_EQ(pokemon2->getTypes()[i], types[i]);
}

TEST_F(testFixture, PokemonIncreaseLevelTest1) {
    Pokemon* pokemon = nullptr;
    pokemon = PokemonPrototype::clone(1, 14);
    pokemon = pokemon->increaseLevel();
    ASSERT_EQ(pokemon->getId(), 1);
    ASSERT_EQ(pokemon->getName(), "Bulbasaur");
    ASSERT_EQ(pokemon->getNextPokemon(), 2);
    ASSERT_EQ(pokemon->getLevel(), 15);
    ASSERT_EQ(pokemon->getMaxLevel(), 15);
    ASSERT_EQ(pokemon->getHp(), 45);
    ASSERT_EQ(pokemon->getMaxHp(), 45);
    ASSERT_EQ(pokemon->getAttack(), 49);
    ASSERT_EQ(pokemon->getDefense(), 49);
    ASSERT_EQ(pokemon->getSpAttack(), 65);
    ASSERT_EQ(pokemon->getSpDefense(), 65);
    ASSERT_EQ(pokemon->getSpeed(), 45);
    std::vector<pokemonId> types;
    types.push_back(Grass);
    types.push_back(Poison);
    for(int i = 0; i < types.size(); i++)
        ASSERT_EQ(pokemon->getTypes()[i], types[i]);
}

TEST_F(testFixture, PokemonIncreaseLevelTest2) {
    Pokemon* pokemon = nullptr;
    pokemon = PokemonPrototype::clone(1, 15);
    pokemon = pokemon->increaseLevel();
    ASSERT_EQ(pokemon->getId(), 2);
    ASSERT_EQ(pokemon->getName(), "Ivysaur");
    ASSERT_EQ(pokemon->getNextPokemon(), 3);
    ASSERT_EQ(pokemon->getLevel(), 16);
    ASSERT_EQ(pokemon->getMaxLevel(), 31);
    ASSERT_EQ(pokemon->getHp(), 60);
    ASSERT_EQ(pokemon->getMaxHp(), 60);
    ASSERT_EQ(pokemon->getAttack(), 62);
    ASSERT_EQ(pokemon->getDefense(), 63);
    ASSERT_EQ(pokemon->getSpAttack(), 80);
    ASSERT_EQ(pokemon->getSpDefense(), 80);
    ASSERT_EQ(pokemon->getSpeed(), 60);
    std::vector<pokemonId> types;
    types.push_back(Grass);
    types.push_back(Poison);
    for(int i = 0; i < types.size(); i++)
        ASSERT_EQ(pokemon->getTypes()[i], types[i]);
}
