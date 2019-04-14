#ifndef POKEMONS_POKEMON_H
#define POKEMONS_POKEMON_H
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <memory>

#define pokemonId int

enum pokType {  Normal,
                Fighting,
                Flying,
                Poison,
                Ground,
                Rock,
                Bug,
                Ghost,
                Steel,
                Fire,
                Water,
                Grass,
                Electric,
                Psychic,
                Ice,
                Dragon,
                Fairy,
                Dark,
                Unknown};

inline const char* toString(pokType t) {
    switch(t) {
        case Normal:    return "Normal";
        case Fighting:  return "Fighting";
        case Flying:    return "Flying";
        case Poison:    return "Poison";
        case Ground:    return "Ground";
        case Rock:      return "Rock";
        case Bug:       return "Bug";
        case Ghost:     return "Ghost";
        case Steel:     return "Steel";
        case Fire:      return "Fire";
        case Water:     return "Water";
        case Grass:     return "Grass";
        case Electric:  return "Electric";
        case Psychic:   return "Psychic";
        case Ice:       return "Ice";
        case Dragon:    return "Dragon";
        case Fairy:     return "Fairy";
        case Dark:      return "Dark";
        default:   return "Unknown";
    }
}

inline pokType toPokType(const std::string& s) {
    if(s == "Normal") return Normal;
    if(s == "Fighting") return Fighting;
    if(s == "Flying") return Flying;
    if(s == "Poison") return Poison;
    if(s == "Ground") return Ground;
    if(s == "Rock") return Rock;
    if(s == "Bug") return Bug;
    if(s == "Ghost") return Ghost;
    if(s == "Steel") return Steel;
    if(s == "Fire") return Fire;
    if(s == "Water") return Water;
    if(s == "Grass") return Grass;
    if(s == "Electric") return Electric;
    if(s == "Psychic") return Psychic;
    if(s == "Ice") return Ice;
    if(s == "Dragon") return Dragon;
    if(s == "Fairy") return Fairy;
    if(s == "Dark") return Dark;
    return Unknown;
}

class Pokemon {
private:
    std::string name;
    pokemonId id, nextPokemon;
    int level, maxLevel;
    int hp, maxHp, attack, defense, spAttack, spDefense, speed;
    std::vector<pokType> types;
public:
    Pokemon(): name(""), id(0), nextPokemon(0), level(0), maxLevel(0), hp(0), maxHp(0), attack(0), defense(0), spAttack(0), spDefense(0), speed(0) {};
    Pokemon(const Pokemon& __pokemon){
        name = __pokemon.name;
        id = __pokemon.id;
        nextPokemon = __pokemon.nextPokemon;
        level = __pokemon.level;
        maxLevel = __pokemon.maxLevel;
        hp = __pokemon.hp;
        maxHp = __pokemon.maxHp;
        attack = __pokemon.attack;
        defense = __pokemon.defense;
        spAttack = __pokemon.spAttack;
        spDefense = __pokemon.spDefense;
        speed = __pokemon.speed;
        types = std::vector<pokType>(__pokemon.types);
    }

    int getId() const {return id;}
    const std::string &getName() const {return name;}
    int getNextPokemon() const {return nextPokemon;}
    int getLevel() const {return level;}
    int getMaxLevel() const {return maxLevel;}
    int getHp() const {return hp;}
    int getMaxHp() const {return maxHp;}
    int getAttack() const {return attack;}
    int getDefense() const {return defense;}
    int getSpAttack() const {return spAttack;}
    int getSpDefense() const {return spDefense;}
    int getSpeed() const {return speed;}
    std::vector<pokType> getTypes() const {return types;}

    void setId(int __id) {id = __id;}
    void setName(const std::string& __name) {name = __name;}
    void setNextPokemon(int __nextPokemon) {nextPokemon = __nextPokemon;}
    void setLevel(int __level) {level = __level;}
    void setMaxLevel(int __maxLevel) {maxLevel = __maxLevel;}
    void setHp(int __health) {hp = __health;}
    void setMaxHp(int __maxHealth) {maxHp = __maxHealth;}
    void setAttack(int __attack) {attack = __attack;}
    void setDefense(int __defense) {defense = __defense;}
    void setSpAttack(int __spAttack) {spAttack = __spAttack;}
    void setSpDefense(int __spDefense) {spDefense = __spDefense;}
    void setSpeed(int __speed) {speed = __speed;}
    void addType(pokType __type) {types.emplace_back(__type);}

    void print() {
        std::cout << "#"  << id << " " << name << ", level " << level << ".\nTypes: ";
        for(int i = 0; i < types.size() - 1; i++)
            std::cout << types[i] << ", ";
        std::cout << types[types.size() - 1] << '\n';
    }

    Pokemon* increaseLevel();
};


/// The next is a pattern "Singleton"
/// for keeping library of pokemons (Pokedex).

<<<<<<< HEAD:PokemonsGame/Pokemon.h
typedef std::unordered_map<pokemonId, Pokemon*> Library;
class Pokedex {
private:
    static Library p_instance;
public:
    Pokedex() = delete;
    ~Pokedex() = delete;
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
    static Library& instance() {                     /// I have parsed database ("pokedex.txt") and I wanted to
        if(p_instance.empty()){                      /// have an opportunity to change pokemon stats
            std::ifstream in;                        /// in new game but I also didn't want to have an opportunity
            in.open("../sources/pokedex.txt");       /// to change stats during the game so I create a "Singleton"
            for(pokemonId i = 1; i <= 926; i++){     /// Pokedex for the case if someone change smth during the game.
                std::string s;
                getline(in, s);
                std::stringstream pokemon(s);
                std::string text;

                auto p = new Pokemon();
=======
/// There were problems with undefined references
/// (or using members of declared but undefined class)
/// when I wrote "Singleton" in class-style
/// so here is a realization in function-style

Library& Pokedex() {
    static Library _instance;                    /// I have parsed database ("pokedex.txt") and I wanted to
    if(_instance.empty()){                       /// have an opportunity to change pokemon stats
        std::ifstream in;                        /// in new game but I also didn't want to have an opportunity
        in.open("PokemonsGame/pokedex.txt");      /// to change stats during the game so I create a "Singleton"
        for(pokemonId i = 1; i <= 926; i++){     /// Pokedex for the case if someone change smth during the game.
            std::string s;
            getline(in, s);
            std::stringstream pokemon(s);
            std::string text;

            auto p = new Pokemon();
            pokemon >> text;
            p->setName(text);
            int num;
            pokemon >> num;
            for(int j = 0; j < num; j++) {
>>>>>>> c7e8dad7d00ddc51f67093c8ab4a34858e9090d6:PokemonsGame/Pokemon.h
                pokemon >> text;
                p->setName(text);
                int num;
                pokemon >> num;
                for(int j = 0; j < num; j++) {
                    pokemon >> text;
                    p->addType(toPokType(text));
                }
                pokemon >> num >> num;
                p->setHp(num);
                p->setMaxHp(num);
                pokemon >> num;
                p->setAttack(num);
                pokemon >> num;
                p->setDefense(num);
                pokemon >> num;
                p->setSpAttack(num);
                pokemon >> num;
                p->setSpDefense(num);
                pokemon >> num;
                p->setSpeed(num);
                pokemon >> num;
                p->setNextPokemon(num);
                pokemon >> num;
                p->setMaxLevel(num);
                p->setLevel(0);
                p->setId(i);
                p_instance.insert({i, p});
            }
        }
        return p_instance;
    }
};

Library Pokedex::p_instance = Library();


/// The next class PokemonPrototype realizes a "Prototype" pattern;
/// I create a big library (near 900 positions) of pokemons
/// and then in every situation when I need to create a pokemon
/// I will clone the existing prototype and then assign it a given level.
/// In total: it is a class that is responsible for
/// realising a pattern "Prototype"
/// with parameterized pokemonId and level.

class PokemonPrototype {
public:
    PokemonPrototype() = delete;
    ~PokemonPrototype() = delete;
    PokemonPrototype(const PokemonPrototype&) = delete;
    PokemonPrototype& operator=(const PokemonPrototype&) = delete;

    static Pokemon* clone(pokemonId id, int level){
        auto p = new Pokemon(*(Pokedex::instance())[id]);
        p->setLevel(level);
        return p;
    }
};

Pokemon* Pokemon::increaseLevel() {
    if (level != maxLevel) {
        level++;
        return this;
    } else {
        auto p = PokemonPrototype::clone(nextPokemon, level + 1);
        delete this;
        return p;
    }
}


#endif //POKEMONS_POKEMON_H
