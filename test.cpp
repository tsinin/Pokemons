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
    class PokemonTest : public testing::Test {
    };

    class RealPokemonTest : public testing::Test {
    };

    class AbilityTest : public testing::Test {
    private:

    public:
        AbilityTest() {
        }
    };

    class PlayerTest : public testing::Test {
    };

    class LocationTest : public testing::Test {
    private:
        std::ifstream in;
        std::streambuf *cinbuf;
        std::ofstream out;
        std::streambuf *coutbuf;
    public:
        LocationTest() {
            in.open("in.txt");
            cinbuf = cin.rdbuf(); //save old buf
            cin.rdbuf(in.rdbuf()); //redirect std::cin to in.txt!

            out.open("out.txt");
            coutbuf = cout.rdbuf(); //save old buf
            cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
        }
        ~LocationTest() {

        }
    };

    class GameTest : public testing::Test {
    };

    class BattleTest : public testing::Test {
    };
};


TEST_F(PokemonTest, PokemonDefaultConstructorTest) {
    Pokemon *pokemon = new Pokemon;
    ASSERT_EQ(pokemon->getId(), 0);
    ASSERT_EQ(pokemon->getExp(), 0);
    ASSERT_EQ(pokemon->getMaxExp(), 0);
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
    ASSERT_EQ(pokemon->getTypeConst(), 1);
    ASSERT_TRUE(pokemon->getTypes().empty());
    ASSERT_TRUE(pokemon->getAbilities().empty());
}

TEST_F(PokemonTest, PokemonIdSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setId(2);
    ASSERT_EQ(pokemon->getId(), 2);
}

TEST_F(PokemonTest, PokemonExpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setExp(3);
    ASSERT_EQ(pokemon->getExp(), 3);
}

TEST_F(PokemonTest, PokemonMaxExpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxExp(4);
    ASSERT_EQ(pokemon->getMaxExp(), 4);
}

TEST_F(PokemonTest, PokemonNameSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setName("The best pokemon");
    ASSERT_EQ(pokemon->getName(), "The best pokemon");
}

TEST_F(PokemonTest, PokemonNextPokemonSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setNextPokemon(3);
    ASSERT_EQ(pokemon->getNextPokemon(), 3);
}

TEST_F(PokemonTest, PokemonLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setLevel(100);
    ASSERT_EQ(pokemon->getLevel(), 100);
}

TEST_F(PokemonTest, PokemonMaxLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxLevel(100);
    ASSERT_EQ(pokemon->getMaxLevel(), 100);
}

TEST_F(PokemonTest, PokemonHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setHp(100500);
    ASSERT_EQ(pokemon->getHp(), 100500);
}

TEST_F(PokemonTest, PokemonMaxHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxHp(100500);
    ASSERT_EQ(pokemon->getMaxHp(), 100500);
}

TEST_F(PokemonTest, PokemonAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setAttack(100500);
    ASSERT_EQ(pokemon->getAttack(), 100500);
}

TEST_F(PokemonTest, PokemonDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setDefense(100500);
    ASSERT_EQ(pokemon->getDefense(), 100500);
}

TEST_F(PokemonTest, PokemonSpAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpAttack(100500);
    ASSERT_EQ(pokemon->getSpAttack(), 100500);
}

TEST_F(PokemonTest, PokemonSpDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpDefense(100500);
    ASSERT_EQ(pokemon->getSpDefense(), 100500);
}

TEST_F(PokemonTest, PokemonSpeedSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpeed(100500);
    ASSERT_EQ(pokemon->getSpeed(), 100500);
}

TEST_F(PokemonTest, PokemonAddExpTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->addExp(100500);
    ASSERT_EQ(pokemon->getExp(), 0);
}

TEST_F(PokemonTest, PokemonTypeAddGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->addType(Normal);
    ASSERT_EQ(pokemon->getTypes(), std::vector<pokType>(1, Normal));
}

TEST_F(PokemonTest, PokemonPokTypeToStringTest) {
    ASSERT_EQ(toString(Poison), "Poison");
}

TEST_F(PokemonTest, PokemonStringToPokTypeTest1) {
    ASSERT_EQ(toPokType("Poison"), Poison);
}

TEST_F(PokemonTest, PokemonStringToPokTypeTest2) {
    ASSERT_EQ(toPokType("The type that is not exist"), Unknown);
}

TEST_F(PokemonTest, PokedexCloneTest) {
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

TEST_F(PokemonTest, PokemonCopyConstructorTest) {
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

TEST_F(PokemonTest, PokemonIncreaseLevelTest1) {
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

TEST_F(PokemonTest, PokemonIncreaseLevelTest2) {
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





/// RealPokemon Test!!






TEST_F(LocationTest, LocationDefaultConstructorTest) {
    Location* location = new Location();
    ASSERT_EQ(location->getName(), "");
    ASSERT_EQ(location->getDescription(), "");
    ASSERT_EQ(location->getAverageLevel(), 0);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({}));
    ASSERT_EQ(location->getProbability(), std::vector<int>(0));
    ASSERT_EQ(location->getNeighbours().size(), 0);
    ASSERT_EQ(location->getSumProbability(), 0);
}

TEST_F(LocationTest, LocationNameSetGetTest) {
    Location* location = new Location();
    location->setName("123abc");
    ASSERT_EQ(location->getName(), "123abc");
}

TEST_F(LocationTest, LocationDescriptionSetGetTest) {
    Location* location = new Location();
    location->setDescription("123abc");
    ASSERT_EQ(location->getDescription(), "123abc");
}

TEST_F(LocationTest, LocationAverageLevelSetGetTest) {
    Location* location = new Location();
    location->setAverageLevel(42);
    ASSERT_EQ(location->getAverageLevel(), 42);
}

TEST_F(LocationTest, LocationLocalPokemonsSetGetTest) {
    Location* location = new Location();
    location->setLocalPokemons(std::vector<pokemonId>({1, 3, 5}));
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({1, 3, 5}));
}

TEST_F(LocationTest, LocationProbabilitySetGetTest) {
    Location* location = new Location();
    location->setProbability(std::vector<int>({1, 3, 5}));
    ASSERT_EQ(location->getProbability(), std::vector<int>({1, 3, 5}));
}

TEST_F(LocationTest, LocationSumProbabilitySetGetTest) {
    Location* location = new Location();
    location->setSumProbability(9);
    ASSERT_EQ(location->getSumProbability(), 9);
}

TEST_F(LocationTest, LocationNeighboursSetGetTest) {
    Location* location = LocationBank::instance()[0];
    location->addNeighbour(nullptr);
    ASSERT_EQ(location->getNeighbours(), std::vector<Location*>({LocationBank::instance()[1], nullptr}));
}

TEST_F(LocationTest, LocationGetRandomPokemonTest) {

}

TEST_F(LocationTest, LocationPrintTest) {

}

TEST_F(LocationTest, LocationPrintNeighboursTest) {
    Location* location = LocationBank::instance()[0];
    location->printNeighbours();
    std::ifstream in("out.txt");
    std::string s;
    getline(in, s);
    ASSERT_EQ(s, "1. Light forest");
}

TEST_F(LocationTest, LocationLibraryTest1) {
    Location* location = LocationBank::instance()[0];
    ASSERT_EQ(location->getName(), "Home");
    ASSERT_EQ(location->getDescription(), "Here are no aggressive pokemons but you can repair your pokemons here.");
    ASSERT_EQ(location->getAverageLevel(), 0);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>(0));
    ASSERT_EQ(location->getProbability(), std::vector<int>(0));
    ASSERT_EQ(location->getNeighbours()[0]->getName(), "Light forest");
    ASSERT_EQ(location->getSumProbability(), 0);
}

TEST_F(LocationTest, LocationLibraryTest2) {
    Location* location = LocationBank::instance()[1];
    ASSERT_EQ(location->getName(), "Light forest");
    ASSERT_EQ(location->getDescription(), "Here you can start to grind, pokemons are really weak.");
    ASSERT_EQ(location->getAverageLevel(), 3);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({14, 17, 21}));
    ASSERT_EQ(location->getProbability(), std::vector<int>({3, 3, 1}));
    ASSERT_EQ(location->getNeighbours()[0]->getName(), "Home");
    ASSERT_EQ(location->getNeighbours()[1]->getName(), "Evening meadow");
    ASSERT_EQ(location->getSumProbability(), 7);
}