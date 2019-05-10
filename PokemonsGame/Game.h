#ifndef POKEMONS_GAME_H
#define POKEMONS_GAME_H
#include <stdlib.h>
#include <time.h>
#include "Location.h"
#include "Pokemon.h"
#include "Player.h"
#include "Battle.h"


class Game {
private:
    Location *location;
    bool inGame, canHeal, canFight, canBuyPokeball;
    Player *player;
public:
    Game(): player(new Player()), location(LocationBank::instance()[0]), inGame(false),
    canHeal(false), canFight(false), canBuyPokeball(false) {}
    ~Game() {
        delete player;
        for(auto t: Pokedex::instance())
            delete t.second;
        for(auto t: LocationBank::instance())
            delete t.second;
        for(auto t: AbilityBank::instance())
            delete t.second;
    }

    Location* getLocation() {return location;}
    Player* getPlayer() {return player;}

    void setLocation(Location* __location) {location = __location;}
    void setPlayer(Player* __player) {player = __player;}
    void gameOver() {inGame = false;}
    void setCanHeal(bool __canHeal) {canHeal = __canHeal;}
    void setCanFight(bool __canFight) {canFight = __canFight;}
    void setCanBuyPokeball(bool __canBuyPokeball) {canBuyPokeball = __canBuyPokeball;}

    bool getCanHeal() {return canHeal;}
    bool getCanFight() { return canFight;}
    bool getCanBuyPokeball() { return canBuyPokeball;}

    void run();
};


class HealDetectObserver: public IObserver {
public:
    void handleAction(Player* p, Game* g) override {
        g->setCanHeal(p->getMoney() >= 10 && g->getLocation()->getName() == "Home");
    }
};

class FightDetectObserver: public IObserver {
    void handleAction(Player* p, Game* g) override {
        g->setCanFight(p->getPokemons()[0]->getHp() > 0 && !g->getLocation()->getLocalPokemons().empty());
    }
};

class BuyPokeballDetectObserver: public IObserver {
    void handleAction(Player* p, Game* g) override {
        g->setCanBuyPokeball(p->getMoney() >= 30 && g->getLocation()->getName() == "Home");
    }
};

class Command{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
protected:
    explicit Command(Game* g): game(g) {}
    Game* game;
};

class RegPlayerCommand: public Command {
public:
    explicit RegPlayerCommand(Game* g): Command(g) {};
    void execute() override {
        cout << "Hello, young poke-trainer!\n"
                "What's your name?\n";
        {
            std::string name;
            std::cout.flush();
            cin >> name;
            game->getPlayer()->setName(name);
        }
        cout << "Now it's time to choose your first pokemon!\n"
                "There are some for you: \n";
        Pokemon* pokemon;
        {
            Pokemon* p1 = PokemonPrototype::clone(1, 5);
            Pokemon* p2 = PokemonPrototype::clone(5, 5);
            Pokemon* p3 = PokemonPrototype::clone(10, 5);
            p1->print();
            p2->print();
            p3->print();
            bool end = false;
            cout << "Write ID-number of pokemon you'd like to choose.\n";
            while(!end) {
                std::string t;
                std::cout.flush();
                cin >> t;
                if(t == "1") {pokemon = p1; delete p2; delete p3; end = true;}
                else if(t == "5") {pokemon = p2; delete p1; delete p3; end = true;}
                else if(t == "10") {pokemon = p3; delete p1; delete p2; end = true;}
                else cout << "Incorrect number, try again.\n";
            }
        }
        game->getPlayer()->addPokemon(new RealPokemon(pokemon));

        game->getPlayer()->addObserver(new HealDetectObserver());
        game->getPlayer()->addObserver(new FightDetectObserver());
        game->getPlayer()->addObserver(new BuyPokeballDetectObserver());

        game->getPlayer()->setGame(game);
        game->getPlayer()->setMoney(100);
        game->getPlayer()->setPokeballs(1);
        cout << "Good choice! Also you'll be given a pokeball and 100 coins.\n\n"
                "Now you can explore the world, fight with pokemons and catch them.\n"
                "If you're staying at the location with pokemons and you want to fight with them\n"
                "you should wait. Different locations have different pokemons and different\n"
                "average level of them. Be cautious!\n";
    }
};

class ChangeLocationCommand: public Command {
public:
    explicit ChangeLocationCommand(Game* g): Command(g) {};
    void execute() override {
        cout << "The nearest locations are:\n";
        game->getLocation()->printNeighbours();

        bool end = false;
        cout << "Write number of location you'd like to choose.\n";
        while(!end) {
            std::string t;
            std::cout.flush();
            cin >> t;
            for(int i = 0; i < game->getLocation()->getNeighbours().size(); i++)
                if(t == std::to_string(i + 1)) {
                    game->setLocation(game->getLocation()->getNeighbours()[i]);
                    end = true;
                    break;
                }
            if(!end)
                cout << "Incorrect number, try again.\n";
        }
        game->getPlayer()->notificate();
    }
};

class ChangeMainPokemonCommand: public Command {
public:
    explicit ChangeMainPokemonCommand(Game* g): Command(g) {};
    void execute() override {
        game->getPlayer()->print();

        bool end = false;
        cout << "Write a number of pokemon you want to choose.\n";
        while(!end) {
            std::string t;
            std::cout.flush();
            cin >> t;
            for(int i = 0; i < game->getPlayer()->getPokemons().size(); i++)
                if(t == std::to_string(i + 1)) {
                    std::swap(game->getPlayer()->getPokemons()[0], game->getPlayer()->getPokemons()[i]);
                    end = true;
                    break;
                }
            if(!end)
                cout << "Incorrect number, try again.\n";
        }
        game->getPlayer()->notificate();
    }
};

class InfoCommand: public Command {
public:
    explicit InfoCommand(Game* g): Command(g) {};
    void execute() override {
        game->getLocation()->print();
        game->getPlayer()->print();
        cout << "If you want to change location, write 'change_location'\n"
                "If you want to change main pokemon, write 'change_pokemon'\n"
                "If you want to know more about current location and what you have, write 'info'\n"
                "If you want to quit the game, write 'quit'\n"
                "If you want to fight, write 'fight' and wait\n"
                "If you want to heal your pokemons, write 'heal'. It will cost 10 coins.\n"
                "You can do it only at Home.\n"
                "If you want to buy a pokeball, write 'buy_pokeball'. It will cost 30 coins.\n"
                "You can do it only at Home.\n";
    }
};

class FightCommand: public Command {
public:
    explicit FightCommand(Game* g): Command(g) {};
    void execute() override {
        if(!game->getCanFight()) {
            cout << "Your main pokemon has no hp or you're on the location without pokemons!";
            return;
        }
        clock_t timer = clock();
        while((clock() - timer) / CLOCKS_PER_SEC < 5)
            ;
        Pokemon* localPokemon = game->getLocation()->getRandomPokemon();
        auto battle = new Battle(game->getPlayer(), localPokemon);
        if(battle->run()) {
            game->getPlayer()->addMoney(localPokemon->getLevel() * 2);
            game->getPlayer()->getPokemons()[0]->addExp(localPokemon->getLevel() * localPokemon->getLevel() * localPokemon->getLevel() * 4);
        }
        delete localPokemon;
        game->getPlayer()->notificate();
    }

};

class HealCommand: public Command {
public:
    explicit HealCommand(Game* g): Command(g) {};
    void execute() override {
        if(!game->getCanHeal()) {
            cout << "You don't have enough money or location is not Home :(.\n";
            return;
        }
        game->getPlayer()->setMoney(game->getPlayer()->getMoney() - 10);
        for(auto pok:game->getPlayer()->getPokemons())
            pok->setHp(pok->getMaxHp());
        cout << "Done! Pokemons are healed.\n";
    }
};

class BuyPokeballCommand: public Command {
public:
    explicit BuyPokeballCommand(Game* g): Command(g) {};
    void execute() override {
        if(!game->getCanBuyPokeball()) {
            cout << "You don't have enough money or location is not Home :(.\n";
            return;
        }
        game->getPlayer()->setMoney(game->getPlayer()->getMoney() - 30);
        game->getPlayer()->setPokeballs(game->getPlayer()->getPokeballs() + 1);
        cout << "Done! +1 pokeball.\n";
    }
};

class QuitCommand: public Command {
public:
    explicit QuitCommand(Game* g): Command(g) {};
    void execute() override {
        cout << "Bye!\n";
        game->gameOver();
    }
};

class UnknownCommand: public Command {
public:
    explicit UnknownCommand(Game* g): Command(g) {};
    void execute() override {
        cout << "Wrong input! You know what you can write :)\n";
    }
};

inline void Game::run() {
    inGame = true;
    Command* command;
    command = new RegPlayerCommand(this);
    command->execute();
    delete command;
    command = new InfoCommand(this);
    command->execute();
    delete command;

    while(inGame) {
        cout << "To see commands and info about player and game, write 'info'\n";

        cout.flush();
        std::string query;
        cin >> query;
        if(query == "change_location") {command = new ChangeLocationCommand(this);}
        else if(query == "change_pokemon") {command = new ChangeMainPokemonCommand(this);}
        else if(query == "info") {command = new InfoCommand(this);}
        else if(query == "quit") {command = new QuitCommand(this);}
        else if(query == "fight") {command = new FightCommand(this);}
        else if(query == "heal") {command = new HealCommand(this);}
        else if(query == "buy_pokeball") {command = new BuyPokeballCommand(this);}
        else {command = new UnknownCommand(this);}

        command->execute();
        delete command;
    }
}

#endif //POKEMONS_GAME_H
