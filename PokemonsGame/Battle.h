#ifndef POKEMONS_BATTLE_H
#define POKEMONS_BATTLE_H

#include "Player.h"
#include <cmath>

class Battle {
private:
    Player* player;
    Pokemon* pokemon;
public:
    Battle(): player(nullptr), pokemon(nullptr){}
    Battle(Player* __player, Pokemon* __pokemon): player(__player), pokemon(__pokemon){}

    ~Battle() = default;

	Player* getPlayer() const {return player;}
	Pokemon* getPokemon() const {return pokemon;}

    bool run() {
        cout << "Your current pokemon is: \n";
        player->getPokemons()[0]->print();
        cout << "\nYour opponent is: \n";
        pokemon->print();
        cout << "\nYou have " << player->getPokemons()[0]->getAbilities().size() << " attacks:\n";
        for(int i = 0; i < player->getPokemons()[0]->getAbilities().size(); i++) {
            cout << i + 1 << ": ";
            AbilityBank::instance()[player->getPokemons()[0]->getAbilities()[i]]->print();
        }

        while(true) {
            cout << "\nYour current pokemon is: \n";
            player->getPokemons()[0]->print();
            cout << "\nYour opponent is: \n";
            pokemon->print();

            Ability* enemyAbility = new Ability(*AbilityBank::instance()[rand() % 2]);
            enemyAbility->setObj(pokemon);
            enemyAbility->setSubj(player->getPokemons()[0]);

            Ability* playerAbility = nullptr;

            bool end = false;
            cout << "\nWrite number of attack you'd like to choose or write 0 to throw a pokeball." << '\n';
            while(!end) {
                std::string t;
                std::cout.flush();
                cin >> t;
                for(int i = 0; i < player->getPokemons()[0]->getAbilities().size(); i++)
                    if(t == std::to_string(i + 1)) {
                        playerAbility = new
                                Ability(*AbilityBank::instance()[player->getPokemons()[0]->getAbilities()[i]]);
                        playerAbility->setObj(player->getPokemons()[0]);
                        playerAbility->setSubj(pokemon);
                        end = true;
                        break;
                    }
                if(t == "0") {
                    if(!player->getPokeballs()) {
                        cout << "You can't do it, you have no pokeballs!" << '\n';
                    } else {
                        int rd = rand() % 101;
                        player->setPokeballs(player->getPokeballs() - 1);
                        if(rd >= pokemon->getLevel() && rd <= pokemon->getLevel() + 60 &&
                        5 * pokemon->getHp() <= pokemon->getMaxHp()) {
                            auto p = PokemonPrototype::clone(pokemon->getId(), pokemon->getLevel());
                            player->addPokemon(new RealPokemon(p));
                            cout << "Yess!! You've just cought this pokemon: \n";
                            player->getPokemons()[player->getPokemons().size() - 1]->print();
                            cout << '\n';
                            return true;
                        }
                        end = true;
                    }
                }
                if(!end && t != "0")
                    cout << "Incorrect number, try again." << '\n';
            }
            Ability *p1 = playerAbility, *p2 = enemyAbility;
            if(player->getPokemons()[0]->getSpeed() < pokemon->getSpeed())
                std::swap(p1, p2);
            if(player->getPokemons()[0]->getSpeed() != pokemon->getSpeed()) {
                p1->execute();
                if(p1->getSubj()->getHp())
                    p2->execute();
            } else {
                p1->execute();
                p2->execute();
            }
            delete enemyAbility, delete playerAbility;
            if(player->getPokemons()[0]->getHp() > 0 && pokemon->getHp() == 0) {
                cout << "You won! You've got money and exp.\n";
                return true;
            }
            else if(player->getPokemons()[0]->getHp() == 0 and pokemon->getHp() > 0) {
                cout << "You are defeated! Repair your pokemons and try again :).\n";
                return false;
            }
            else if(player->getPokemons()[0]->getHp() == 0 && pokemon->getHp() == 0) {
                cout << "You're defeated but you won. Here is your money and exp but your pokemon\n"
                        "is defeated, heal it before next battle.\n";
                return true;
            }
        }
    }
};


#endif //POKEMONS_BATTLE_H
