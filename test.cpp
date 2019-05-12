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
    class PokemonTest : public testing::Test {};

    class AbilityTest : public testing::Test  {
    public:
        std::ifstream in;
        std::ofstream out;
        std::ifstream myin;
        std::ofstream myout;
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        void openMy() {

            myin.open("in.txt");
            myout.open("out.txt");
        }
        void closeMy() {
            myin.close();
            myout.close();
        }
        void openInner() {
            in.open("out.txt");
            cinbuf = std::cin.rdbuf();
            cin.rdbuf(in.rdbuf());

            out.open("in.txt");
            coutbuf = std::cout.rdbuf();
            cout.rdbuf(out.rdbuf());
        }
        void closeInner() {

            std::cin.rdbuf(cinbuf);   //reset to standard input again
            std::cout.rdbuf(coutbuf);
            in.close();
            out.close();

        }
    };

    class PlayerTest : public testing::Test  {
    public:
        std::ifstream in;
        std::ofstream out;
        std::ifstream myin;
        std::ofstream myout;
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        void openMy() {

            myin.open("in.txt");
            myout.open("out.txt");
        }
        void closeMy() {
            myin.close();
            myout.close();
        }
        void openInner() {
            in.open("out.txt");
            cinbuf = std::cin.rdbuf();
            cin.rdbuf(in.rdbuf());

            out.open("in.txt");
            coutbuf = std::cout.rdbuf();
            cout.rdbuf(out.rdbuf());
        }
        void closeInner() {

            std::cin.rdbuf(cinbuf);   //reset to standard input again
            std::cout.rdbuf(coutbuf);
            in.close();
            out.close();

        }
    };

    class LocationTest : public testing::Test  {
    public:
        std::ifstream in;
        std::ofstream out;
        std::ifstream myin;
        std::ofstream myout;
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        void openMy() {

            myin.open("in.txt");
            myout.open("out.txt");
        }
        void closeMy() {
            myin.close();
            myout.close();
        }
        void openInner() {
            in.open("out.txt");
            cinbuf = std::cin.rdbuf();
            cin.rdbuf(in.rdbuf());

            out.open("in.txt");
            coutbuf = std::cout.rdbuf();
            cout.rdbuf(out.rdbuf());
        }
        void closeInner() {

            std::cin.rdbuf(cinbuf);   //reset to standard input again
            std::cout.rdbuf(coutbuf);
            in.close();
            out.close();

        }
    };

    class GameTest : public testing::Test  {
    public:
        std::ifstream in;
        std::ofstream out;
        std::ifstream myin;
        std::ofstream myout;
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        void openMy() {

            myin.open("in.txt");
            myout.open("out.txt");
        }
        void closeMy() {
            myin.close();
            myout.close();
        }
        void openInner() {
            in.open("out.txt");
            cinbuf = std::cin.rdbuf();
            cin.rdbuf(in.rdbuf());

            out.open("in.txt");
            coutbuf = std::cout.rdbuf();
            cout.rdbuf(out.rdbuf());
        }
        void closeInner() {

            std::cin.rdbuf(cinbuf);   //reset to standard input again
            std::cout.rdbuf(coutbuf);
            in.close();
            out.close();

        }
    };

    class BattleTest : public testing::Test {
    public:
        std::ifstream in;
        std::ofstream out;
        std::ifstream myin;
        std::ofstream myout;
        std::streambuf *cinbuf;
        std::streambuf *coutbuf;
        void openMy() {

            myin.open("in.txt");
            myout.open("out.txt");
        }
        void closeMy() {
            myin.close();
            myout.close();
        }
        void openInner() {
            in.open("out.txt");
            cinbuf = std::cin.rdbuf();
            cin.rdbuf(in.rdbuf());

            out.open("in.txt");
            coutbuf = std::cout.rdbuf();
            cout.rdbuf(out.rdbuf());
        }
        void closeInner() {

            std::cin.rdbuf(cinbuf);   //reset to standard input again
            std::cout.rdbuf(coutbuf);
            in.close();
            out.close();

        }
    };
    
    class ObserverTest : public testing::Test {
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
    delete pokemon;
}

TEST_F(PokemonTest, PokemonIdSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setId(2);
    ASSERT_EQ(pokemon->getId(), 2);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonExpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setExp(3);
    ASSERT_EQ(pokemon->getExp(), 3);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonMaxExpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxExp(4);
    ASSERT_EQ(pokemon->getMaxExp(), 4);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonNameSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setName("The best pokemon");
    ASSERT_EQ(pokemon->getName(), "The best pokemon");
    delete pokemon;
}

TEST_F(PokemonTest, PokemonNextPokemonSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setNextPokemon(3);
    ASSERT_EQ(pokemon->getNextPokemon(), 3);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setLevel(100);
    ASSERT_EQ(pokemon->getLevel(), 100);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonMaxLevelSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxLevel(100);
    ASSERT_EQ(pokemon->getMaxLevel(), 100);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setHp(100500);
    ASSERT_EQ(pokemon->getHp(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonMaxHpSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setMaxHp(100500);
    ASSERT_EQ(pokemon->getMaxHp(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setAttack(100500);
    ASSERT_EQ(pokemon->getAttack(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setDefense(100500);
    ASSERT_EQ(pokemon->getDefense(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonSpAttackSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpAttack(100500);
    ASSERT_EQ(pokemon->getSpAttack(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonSpDefenseSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpDefense(100500);
    ASSERT_EQ(pokemon->getSpDefense(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonSpeedSetGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->setSpeed(100500);
    ASSERT_EQ(pokemon->getSpeed(), 100500);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonAddExpTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->addExp(100500);
    ASSERT_EQ(pokemon->getExp(), 0);
    delete pokemon;
}

TEST_F(PokemonTest, PokemonTypeAddGetTest) {
    Pokemon *pokemon = new Pokemon;
    pokemon->addType(Normal);
    ASSERT_EQ(pokemon->getTypes(), std::vector<pokType>(1, Normal));
    delete pokemon;
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
    delete pokemon;
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
    delete pokemon1, delete pokemon2;
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
    delete pokemon;
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
    delete pokemon;
}




TEST_F(LocationTest, LocationDefaultConstructorTest) {
    Location* location = new Location();
    ASSERT_EQ(location->getName(), "");
    ASSERT_EQ(location->getDescription(), "");
    ASSERT_EQ(location->getAverageLevel(), 0);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({}));
    ASSERT_EQ(location->getProbability(), std::vector<int>(0));
    ASSERT_EQ(location->getNeighbours().size(), 0);
    ASSERT_EQ(location->getSumProbability(), 0);
    delete location;
}

TEST_F(LocationTest, LocationNameSetGetTest) {
    Location* location = new Location();
    location->setName("123abc");
    ASSERT_EQ(location->getName(), "123abc");
    delete location;
}

TEST_F(LocationTest, LocationDescriptionSetGetTest) {
    Location* location = new Location();
    location->setDescription("123abc");
    ASSERT_EQ(location->getDescription(), "123abc");
    delete location;
}

TEST_F(LocationTest, LocationAverageLevelSetGetTest) {
    Location* location = new Location();
    location->setAverageLevel(42);
    ASSERT_EQ(location->getAverageLevel(), 42);
    delete location;
}

TEST_F(LocationTest, LocationLocalPokemonsSetGetTest) {
    Location* location = new Location();
    location->setLocalPokemons(std::vector<pokemonId>({1, 3, 5}));
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({1, 3, 5}));
    delete location;
}

TEST_F(LocationTest, LocationProbabilitySetGetTest) {
    Location* location = new Location();
    location->setProbability(std::vector<int>({1, 3, 5}));
    ASSERT_EQ(location->getProbability(), std::vector<int>({1, 3, 5}));
    delete location;
}

TEST_F(LocationTest, LocationSumProbabilitySetGetTest) {
    Location* location = new Location();
    location->setSumProbability(9);
    ASSERT_EQ(location->getSumProbability(), 9);
    delete location;
}

TEST_F(LocationTest, LocationNeighboursSetGetTest) {
    Location* location = new Location(*LocationBank::instance()[0]);
    location->addNeighbour(nullptr);
    ASSERT_EQ(location->getNeighbours(), std::vector<Location*>({LocationBank::instance()[1], nullptr}));
    delete location;
}

TEST_F(LocationTest, LocationGetRandomPokemonTest) {
    Location* location = new Location(*LocationBank::instance()[1]);
    auto pok = location->getRandomPokemon();
    auto loc = location->getLocalPokemons();
    ASSERT_TRUE(std::find(loc.begin(), loc.end(), pok->getId()) != loc.end());
    ASSERT_TRUE(abs(pok->getLevel() - location->getAverageLevel()) < 5);
    delete location, delete pok;
}

TEST_F(LocationTest, LocationPrintTest) {
    Location* location = new Location(*LocationBank::instance()[0]);

    openInner();
    location->print();
    closeInner();

    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Home. Here are no aggressive pokemons but you can repair your pokemons here.");
    getline(myin, s);
    ASSERT_EQ(s, "Local pokemons are:");
    closeMy();
    delete location;
}

TEST_F(LocationTest, LocationPrintNeighboursTest) {
    Location* location = new Location(*LocationBank::instance()[0]);

    openInner();
    location->printNeighbours();
    closeInner();

    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "1. Light forest");
    closeMy();
    delete location;
}

TEST_F(LocationTest, LocationLibraryTest1) {
    Location* location = new Location(*LocationBank::instance()[0]);
    ASSERT_EQ(location->getName(), "Home");
    ASSERT_EQ(location->getDescription(), "Here are no aggressive pokemons but you can repair your pokemons here.");
    ASSERT_EQ(location->getAverageLevel(), 0);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>(0));
    ASSERT_EQ(location->getProbability(), std::vector<int>(0));
    ASSERT_EQ(location->getNeighbours()[0]->getName(), "Light forest");
    ASSERT_EQ(location->getSumProbability(), 0);
    delete location;
}

TEST_F(LocationTest, LocationLibraryTest2) {
    Location* location = new Location(*LocationBank::instance()[1]);
    ASSERT_EQ(location->getName(), "Light forest");
    ASSERT_EQ(location->getDescription(), "Here you can start to grind, pokemons are really weak.");
    ASSERT_EQ(location->getAverageLevel(), 3);
    ASSERT_EQ(location->getLocalPokemons(), std::vector<pokemonId>({14, 17, 21}));
    ASSERT_EQ(location->getProbability(), std::vector<int>({3, 3, 1}));
    ASSERT_EQ(location->getNeighbours()[0]->getName(), "Home");
    ASSERT_EQ(location->getNeighbours()[1]->getName(), "Evening meadow");
    ASSERT_EQ(location->getSumProbability(), 7);
    delete location;
}



TEST_F(AbilityTest, AbilitySetGetNameTest) {
    Ability* a = new Ability();
    a->setName("Abc");
    ASSERT_EQ(a->getName(), "Abc");
    delete a;
}

TEST_F(AbilityTest, AbilitySetGetAttackPowerTest) {
    Ability* a = new Ability();
    a->setAttackPower(100500);
    ASSERT_EQ(a->getAttackPower(), 100500);
    delete a;
}

TEST_F(AbilityTest, AbilitySetGetObjTest) {
    Ability* a = new Ability();
    a->setObj(nullptr);
    ASSERT_EQ(a->getObj(), nullptr);
    delete a;
}


TEST_F(AbilityTest, AbilitySetGetSubjTest) {
    Ability* a = new Ability();
    a->setSubj(nullptr);
    ASSERT_EQ(a->getSubj(), nullptr);
    delete a;
}

TEST_F(AbilityTest, AbilitySetGetSpecialTest) {
    Ability* a = new Ability();
    a->setSpecial(false);
    ASSERT_EQ(a->getSpecial(), false);
    delete a;
}

TEST_F(AbilityTest, AbilityDefaultConstructorTest) {
    auto p = new Ability();
    ASSERT_EQ(p->getName(), "");
    ASSERT_EQ(p->getAttackPower(), 0);
    ASSERT_EQ(p->getObj(), nullptr);
    ASSERT_EQ(p->getSubj(), nullptr);
    ASSERT_FALSE(p->getSpecial());
    delete p;
}

TEST_F(AbilityTest, AbilityCopyConstructorTest) {
    auto p = AbilityBank::instance()[0];
    auto t = new Ability(*p);
    ASSERT_EQ(t->getName(), p->getName());
    ASSERT_EQ(t->getAttackPower(), p->getAttackPower());
    ASSERT_EQ(t->getObj(), p->getObj());
    ASSERT_EQ(t->getSubj(), p->getSubj());
    ASSERT_EQ(t->getSpecial(), p->getSpecial());
    delete t;
}

TEST_F(AbilityTest, AbilityExecuteTest) {
    auto a = new Ability(*AbilityBank::instance()[0]);
    auto p1 = new RealPokemon(PokemonPrototype::clone(1, 10));
    auto p2 = new RealPokemon(PokemonPrototype::clone(1, 10));
    a->setObj(p1);
    a->setSubj(p2);
    a->execute();
    ASSERT_TRUE(p2->getHp() != p2->getMaxHp());
    delete a, delete p1, delete p2;
}

TEST_F(AbilityTest, AbilityBankTest) {
    auto a = new Ability(*AbilityBank::instance()[0]);
    ASSERT_EQ(a->getName(), "Usual attack");
    ASSERT_EQ(a->getAttackPower(), 50);
    ASSERT_EQ(a->getSpecial(), false);
    delete a;
}



TEST_F(PlayerTest, DefaultConstructorTest) {
    Player* player = new Player();
    ASSERT_EQ(player->getName(), "");
    ASSERT_EQ(player->getMoney(), 0);
    ASSERT_EQ(player->getPokeballs(), 0);
    ASSERT_EQ(player->getGame(), nullptr);
    ASSERT_TRUE(player->getPokemons().empty());
    delete player;
}


TEST_F(PlayerTest, SetGetNameTest) {
    auto p = new Player();
    p->setName("abc");
    ASSERT_EQ(p->getName(), "abc");
    delete p;
}

TEST_F(PlayerTest, SetGetPokemonsTest) {
    auto p = new Player();
    p->setPokemons(std::vector<Pokemon*>({nullptr, nullptr}));
    ASSERT_EQ(p->getPokemons(), std::vector<Pokemon*>({nullptr, nullptr}));
    delete p;
}

TEST_F(PlayerTest, SetGetPokeballsTest) {
    auto p = new Player();
    p->setPokeballs(123);
    ASSERT_EQ(p->getPokeballs(), 123);
    delete p;
}

TEST_F(PlayerTest, SetGetMoneyTest) {
    auto p = new Player();
    p->setMoney(1234);
    ASSERT_EQ(p->getMoney(), 1234);
    delete p;
}

TEST_F(PlayerTest, SetGetGameTest) {
    auto p = new Player();
    p->setGame(nullptr);
    ASSERT_EQ(p->getGame(), nullptr);
    delete p;
}

TEST_F(PlayerTest, addPokemoonTest) {
    auto p = new Player();
    p->addPokemon(nullptr);
    ASSERT_EQ(p->getPokemons(), std::vector<Pokemon*>({nullptr}));
    delete p;
}

TEST_F(PlayerTest, addMoneyTest) {
    auto p = new Player();
    p->addMoney(4);
    p->addMoney(3);
    ASSERT_EQ(p->getMoney(), 7);
    delete p;
}

TEST_F(PlayerTest, printTest) {
    auto p = new Player();
    
    openInner();
    p->print();
    closeInner();

    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "You have 0 coins and 0 pokeballs.");
    getline(myin, s);
    ASSERT_EQ(s, "Your pokemons are:");
    closeMy();
    delete p;
}



TEST_F(GameTest, DefaultConstructorTest) {
    auto g = new Game();
    ASSERT_EQ(g->getInGame(), false);
    ASSERT_EQ(g->getCanHeal(), false);
    ASSERT_EQ(g->getCanFight(), false);
    ASSERT_EQ(g->getCanBuyPokeball(), false);
    ASSERT_EQ(g->getLocation(), LocationBank::instance()[0]);
    ASSERT_TRUE(g->getPlayer() != nullptr);
    delete g;
}

TEST_F(GameTest, SetGetLocationTest) {
    auto g = new Game();
    g->setLocation(LocationBank::instance()[0]);
    ASSERT_EQ(g->getLocation(), LocationBank::instance()[0]);
    delete g;
}

TEST_F(GameTest, SetGetPlayerTest) {
    auto g = new Game();
    auto p = g->getPlayer();
    g->setPlayer(p);
    ASSERT_EQ(g->getPlayer(), p);
    delete g;
}

TEST_F(GameTest, gameOverTest) {
    auto g = new Game();
    g->gameOver();
    ASSERT_FALSE(g->getInGame());
    delete g;
}

TEST_F(GameTest, SetGetCanHealTest) {
    auto g = new Game();
    g->setCanHeal(true);
    ASSERT_TRUE(g->getCanHeal());
    g->setCanHeal(false);
    ASSERT_FALSE(g->getCanHeal());
    delete g;
}

TEST_F(GameTest, SetGetCanFightTest) {
    auto g = new Game();
    g->setCanFight(true);
    ASSERT_TRUE(g->getCanFight());
    g->setCanFight(false);
    ASSERT_FALSE(g->getCanFight());
    delete g;
}

TEST_F(GameTest, SetGetCanBuyPokeballTest) {
    auto g = new Game();
    g->setCanBuyPokeball(true);
    ASSERT_TRUE(g->getCanBuyPokeball());
    g->setCanBuyPokeball(false);
    ASSERT_FALSE(g->getCanBuyPokeball());
    delete g;
}

TEST_F(GameTest, RegPlayerCommandTest) {
    auto g = new Game();
    Command* command = new RegPlayerCommand(g);
    openMy();
    myout << "Andrew\n something_wrong\n 5\n";
    closeMy();
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Hello, young poke-trainer!");
    getline(myin, s);
    ASSERT_EQ(s, "What's your name?");
    getline(myin, s);
    ASSERT_EQ(s, "Now it's time to choose your first pokemon!");
    getline(myin, s);
    ASSERT_EQ(s, "There are some for you: ");
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    ASSERT_EQ(s, "Write ID-number of pokemon you'd like to choose.");
    getline(myin, s);
    ASSERT_EQ(s, "Incorrect number, try again.");
    getline(myin, s);
    ASSERT_EQ(s, "Good choice! Also you'll be given a pokeball and 100 coins.");
    getline(myin, s);
    getline(myin, s);
    ASSERT_EQ(s, "Now you can explore the world, fight with pokemons and catch them.");
    getline(myin, s);
    ASSERT_EQ(s, "If you're staying at the location with pokemons and you want to fight with them");
    getline(myin, s);
    ASSERT_EQ(s, "you should wait. Different locations have different pokemons and different");
    getline(myin, s);
    ASSERT_EQ(s, "average level of them. Be cautious!");
    auto p = g->getPlayer()->getPokemons()[0];
    ASSERT_EQ(p->getId(), 5);
    ASSERT_EQ(p->getLevel(), 5);
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, ChangeLocationCommandTest) {
    auto g = new Game();
    Command* command = new ChangeLocationCommand(g);
    openMy();
    myout << "something_wrong\n 1\n";
    closeMy();
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "The nearest locations are:");
    getline(myin, s);
    getline(myin, s);
    ASSERT_EQ(s, "Write number of location you'd like to choose.");
    getline(myin, s);
    ASSERT_EQ(s, "Incorrect number, try again.");

    auto l = g->getLocation();
    ASSERT_EQ(l->getName(), "Light forest");
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, ChangeMainPokemonCommand) {
    auto g = new Game();
    Command* command = new ChangeMainPokemonCommand(g);
    g->getPlayer()->addPokemon(new RealPokemon(PokemonPrototype::clone(5, 5)));
    g->getPlayer()->addPokemon(new RealPokemon(PokemonPrototype::clone(6, 6)));
    openMy();
    myout << "something_wrong\n 2\n";
    closeMy();
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    ASSERT_EQ(s, "Write a number of pokemon you want to choose.");
    getline(myin, s);
    ASSERT_EQ(s, "Incorrect number, try again.");
    auto p = g->getPlayer()->getPokemons()[0];
    ASSERT_EQ(p->getId(), 6);
    ASSERT_EQ(p->getLevel(), 6);
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, InfoCommand) {
    auto g = new Game();
    Command* command = new InfoCommand(g);
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    getline(myin, s);
    ASSERT_EQ(s, "If you want to change location, write 'change_location'");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to change main pokemon, write 'change_pokemon'");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to know more about current location and what you have, write 'info'");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to quit the game, write 'quit'");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to fight, write 'fight' and wait");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to heal your pokemons, write 'heal'. It will cost 10 coins.");
    getline(myin, s);
    ASSERT_EQ(s, "You can do it only at Home.");
    getline(myin, s);
    ASSERT_EQ(s, "If you want to buy a pokeball, write 'buy_pokeball'. It will cost 30 coins.");
    getline(myin, s);
    ASSERT_EQ(s, "You can do it only at Home.");
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, FightCommand) {
    auto g = new Game();
    g->getPlayer()->addPokemon(new RealPokemon(PokemonPrototype::clone(100, 100)));
    openMy();
    myout << "1";
    Command* command = new FightCommand(g);
    closeMy();
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Your main pokemon has no hp or you're on the location without pokemons!");
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, HealCommand) {
    auto g = new Game();
    g->getPlayer()->addPokemon(new RealPokemon(PokemonPrototype::clone(100, 100)));
    g->getPlayer()->getPokemons()[0]->setHp(0);
    g->getPlayer()->setMoney(10);
    g->setCanHeal(true);
    Command* command = new HealCommand(g);
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Done! Pokemons are healed.");
    ASSERT_EQ(g->getPlayer()->getPokemons()[0]->getHp(), g->getPlayer()->getPokemons()[0]->getMaxHp());
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, BuyPokeballCommand) {
    auto g = new Game();
    g->getPlayer()->setMoney(30);
    g->setCanBuyPokeball(true);
    Command* command = new BuyPokeballCommand(g);
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Done! +1 pokeball.");
    ASSERT_EQ(g->getPlayer()->getPokeballs(), 1);
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, QuitCommand) {
    auto g = new Game();
    Command* command = new QuitCommand(g);
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Bye!");
    closeMy();
    delete g, delete command;
}

TEST_F(GameTest, UnknownCommand) {
    auto g = new Game();
    Command* command = new UnknownCommand(g);
    openInner();
    command->execute();
    closeInner();
    openMy();
    std::string s;
    getline(myin, s);
    ASSERT_EQ(s, "Wrong input! You know what you can write :)");
    closeMy();
    delete g, delete command;
}



TEST_F(BattleTest, DefaultConstructorTest) {
	auto b = new Battle();
	ASSERT_EQ(b->getPlayer(), nullptr);
	ASSERT_EQ(b->getPokemon(), nullptr);
	delete b;
}

TEST_F(BattleTest, ConstructorTest) {
	auto pok = new RealPokemon(PokemonPrototype::clone(5, 5));
	auto pl = new Player();
	auto b = new Battle(pl, pok);
	ASSERT_EQ(b->getPlayer(), pl);
	ASSERT_EQ(b->getPokemon(), pok);
	delete pok, delete pl, delete b;
}

TEST_F(BattleTest, RunWinTest) {
	auto pok = new RealPokemon(PokemonPrototype::clone(5, 5));
	auto pl = new Player();
	pl->addPokemon(new RealPokemon(PokemonPrototype::clone(100, 100)));
	auto b = new Battle(pl, pok);
	openMy();
	myout << "0 5 1\n";
	closeMy();
	openInner();
	b->run();
	closeInner();
	openMy();
	std::string s;
	getline(myin, s);
	ASSERT_EQ(s, "Your current pokemon is: ");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "Your opponent is: ");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "You have 2 attacks:");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "Write number of attack you'd like to choose or write 0 to throw a pokeball.");
	getline(myin, s);
	ASSERT_EQ(s, "You can't do it, you have no pokeballs!");
	getline(myin, s);
	ASSERT_EQ(s, "Incorrect number, try again.");
	getline(myin, s);
	ASSERT_EQ(s, "You won! You've got money and exp.");
	closeMy();
    delete pok, delete pl, delete b;
}


TEST_F(BattleTest, RunLoseTest) {
	auto pok = new RealPokemon(PokemonPrototype::clone(100, 100));
	auto pl = new Player();
	pl->addPokemon(new RealPokemon(PokemonPrototype::clone(5, 5)));
	auto b = new Battle(pl, pok);
	openMy();
	myout << 0 << '\n' << "smth_incorrect" << '\n' << 1 << '\n';
	closeMy();
	openInner();
	b->run();
	closeInner();
	openMy();
	std::string s;
	getline(myin, s);
	ASSERT_EQ(s, "Your current pokemon is: ");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "Your opponent is: ");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "You have 2 attacks:");
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	getline(myin, s);
	ASSERT_EQ(s, "Write number of attack you'd like to choose or write 0 to throw a pokeball.");
	getline(myin, s);
	ASSERT_EQ(s, "You can't do it, you have no pokeballs!");
	getline(myin, s);
	ASSERT_EQ(s, "Incorrect number, try again.");
	getline(myin, s);
	ASSERT_EQ(s, "You are defeated! Repair your pokemons and try again :).");
	closeMy();
    delete pok, delete pl, delete b;
}



TEST_F(ObserverTest, HealDetectObserverTest) {
	auto g = new Game();
    auto p = g->getPlayer();
	auto obs = new HealDetectObserver();
	p->addObserver(obs);
	g->addObserver(obs);
	g->setPlayer(p);
	p->setGame(g);
	p->addMoney(10);
	ASSERT_FALSE(g->getCanHeal());
	p->addPokemon(new RealPokemon(PokemonPrototype::clone(1, 1)));
	ASSERT_TRUE(g->getCanHeal());
	p->setMoney(0);
	ASSERT_FALSE(g->getCanHeal());
	p->addMoney(10);
	g->setLocation(LocationBank::instance()[1]);
	ASSERT_FALSE(g->getCanHeal());
	p->setMoney(0);
	ASSERT_FALSE(g->getCanHeal());
	delete g;
}


TEST_F(ObserverTest, FightDetectObserverTest) {
	auto g = new Game();
    auto p = g->getPlayer();
	auto obs = new FightDetectObserver();
	g->addObserver(obs);
	p->addObserver(obs);
	g->setPlayer(p);
	p->setGame(g);
	ASSERT_FALSE(g->getCanFight());
	p->addPokemon(new RealPokemon(PokemonPrototype::clone(1, 1)));
	ASSERT_FALSE(g->getCanFight());
	g->setLocation(LocationBank::instance()[1]);
	ASSERT_TRUE(g->getCanFight());
	delete g;
}

TEST_F(ObserverTest, BuyPokeballObserverTest) {
    auto g = new Game();
    auto p = g->getPlayer();
    auto obs = new BuyPokeballDetectObserver();
    g->addObserver(obs);
    p->addObserver(obs);
    g->setPlayer(p);
    p->setGame(g);
    ASSERT_FALSE(g->getCanBuyPokeball());
    p->addMoney(30);
    ASSERT_TRUE(g->getCanBuyPokeball());
    g->setLocation(LocationBank::instance()[1]);
    ASSERT_FALSE(g->getCanBuyPokeball());
    delete g;
}
