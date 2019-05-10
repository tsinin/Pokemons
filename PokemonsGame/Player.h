#ifndef POKEMONS_PLAYER_H
#define POKEMONS_PLAYER_H
#include "Ability.h"

class Player;
class Game;

/// Interface Observer which implemented in Game.h exists to
/// trace changes in game where ability of player to heal or fight is changing
/// so there are 3 observers: HealDetectObserver and FightDetectObserver
/// and BuyPokeballDetectObserver

class IObserver {
public:
    virtual void handleAction(Player* p, Game* g) = 0;
};


class Player{
private:
    std::string name;
    std::vector<Pokemon*> pokemons = std::vector<Pokemon*>(0);
    int money;
    int pokeballs;
    std::vector<IObserver*> obs = std::vector<IObserver*>(0);
    Game* game;
public:
    Player():name(""), pokeballs(0), money(0), game(nullptr) {}
    ~Player() {
        for(auto t: pokemons)
            delete t;
        for(auto t: obs)
            delete t;
    }
    const std::string &getName() const {return name;}
    std::vector<Pokemon*>& getPokemons() {return pokemons;}
    int getPokeballs() const {return pokeballs;}
    int getMoney() const {return money;}
    Game* getGame() const {return game;}

    void setName(const std::string &__name) {name = __name;}
    void setPokemons(const std::vector<Pokemon*>& __pokemons) {pokemons = __pokemons;}
    void setPokeballs(int __pokeballs) {
        pokeballs = __pokeballs;
        notificate();
    }
    void setMoney(int __money) {
        money = __money;
        notificate();
    }
    void setGame(Game* __game) {game = __game;}
    void addPokemon(Pokemon* pokemon) {pokemons.emplace_back(pokemon);}
    void addMoney(int __money) {
        money += __money;
        notificate();
    }

    void addObserver(IObserver* observer) {obs.emplace_back(observer);}
    void notificate() {
        for(auto observer: obs)
            observer->handleAction(this, game);
    }

    void print() {
        std::cout << "You have " << money << " coins and " << pokeballs << " pokeballs.\n";
        std::cout << "Your pokemons are:\n";
        for(int i = 0; i < pokemons.size(); i++) {
            std::cout << i + 1 << ": ";
            pokemons[i]->print();
        }
    }
};


#endif //POKEMONS_PLAYER_H
