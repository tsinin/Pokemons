#ifndef POKEMONS_POKEMON_H
#define POKEMONS_POKEMON_H
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <memory>
#include <sstream>

using std::cin;
using std::cout;

class Ability;

#define pokemonId int
#define NUMBER_OF_POKEMONS 926

enum pokType {  Normal,
                Fire,
                Water,
                Electric,
                Grass,
                Ice,
                Fighting,
                Poison,
                Ground,
                Flying,
                Psychic,
                Bug,
                Rock,
                Ghost,
                Dragon,
                Dark,
                Steel,
                Fairy,
                Unknown};

inline std::string toString(pokType t) {
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
    if(s == "Normal")   return Normal;
    if(s == "Fighting") return Fighting;
    if(s == "Flying")   return Flying;
    if(s == "Poison")   return Poison;
    if(s == "Ground")   return Ground;
    if(s == "Rock")     return Rock;
    if(s == "Bug")      return Bug;
    if(s == "Ghost")    return Ghost;
    if(s == "Steel")    return Steel;
    if(s == "Fire")     return Fire;
    if(s == "Water")    return Water;
    if(s == "Grass")    return Grass;
    if(s == "Electric") return Electric;
    if(s == "Psychic")  return Psychic;
    if(s == "Ice")      return Ice;
    if(s == "Dragon")   return Dragon;
    if(s == "Fairy")    return Fairy;
    if(s == "Dark")     return Dark;
    return Unknown;
}

class Pokemon{
protected:
    const double TYPE_CONST;
    std::string name;
    pokemonId id, nextPokemon;
    int exp, maxExp, level, maxLevel, hp, maxHp;
    double attack, defense, spAttack, spDefense, speed;
    std::vector<pokType> types = std::vector<pokType>(0);
    std::vector<int> abilities = std::vector<int>(0);
public:
    Pokemon(): exp(0), maxExp(0), name(""), id(0), nextPokemon(0), level(0), maxLevel(0), hp(0), maxHp(0), attack(0), defense(0), spAttack(0), spDefense(0), speed(0), TYPE_CONST(1){};
    Pokemon(const Pokemon& __pokemon): TYPE_CONST(__pokemon.TYPE_CONST) {
        exp = __pokemon.exp;
        maxExp = __pokemon.maxExp;
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
        abilities = std::vector<int>(__pokemon.abilities);
    }

    virtual int getExp() const {return exp;}
    virtual int getMaxExp() const {return maxExp;}
    virtual int getId() const {return id;}
    virtual const std::string &getName() const {return name;}
    virtual int getNextPokemon() const {return nextPokemon;}
    virtual int getLevel() const {return level;}
    virtual int getMaxLevel() const {return maxLevel;}
    virtual int getHp() const {return hp;}
    virtual int getMaxHp() const {return maxHp;}
    virtual double getAttack() const {return attack;}
    virtual double getDefense() const {return defense;}
    virtual double getSpAttack() const {return spAttack;}
    virtual double getSpDefense() const {return spDefense;}
    virtual double getSpeed() const {return speed;}
    virtual double getTypeConst() const {return TYPE_CONST;}
    virtual std::vector<pokType> getTypes() const {return types;}
    virtual std::vector<int> getAbilities() const {return abilities;}

    virtual void setExp(int __exp) {exp = __exp;}
    virtual void setMaxExp(int __maxExp) {maxExp = __maxExp;}
    virtual void setId(int __id) {id = __id;}
    virtual void setName(const std::string& __name) {name = __name;}
    virtual void setNextPokemon(int __nextPokemon) {nextPokemon = __nextPokemon;}
    virtual void setLevel(int __level) {level = __level;}
    virtual void setMaxLevel(int __maxLevel) {maxLevel = __maxLevel;}
    virtual void setHp(int __health) {hp = __health;}
    virtual void setMaxHp(int __maxHealth) {maxHp = __maxHealth;}
    virtual void setAttack(double __attack) {attack = __attack;}
    virtual void setDefense(double __defense) {defense = __defense;}
    virtual void setSpAttack(double __spAttack) {spAttack = __spAttack;}
    virtual void setSpDefense(double __spDefense) {spDefense = __spDefense;}
    virtual void setSpeed(double __speed) {speed = __speed;}
    virtual void addType(pokType __type) {types.emplace_back(__type);}
    virtual void addAbility(int __ability) {abilities.emplace_back(__ability);}

    virtual void addExp(int) {}

    virtual void print() {
        std::cout << "#"  << id << " " << name << ", level " << level << ".\nTypes: ";
        for(int i = 0; i < types.size() - 1; i++)
            std::cout << toString(types[i]) << ", ";
        std::cout << toString(types[types.size() - 1]) << '\n';
        std::cout.flush();
    }

    virtual Pokemon* increaseLevel();
};


/// The next is a pattern "Singleton"
/// for keeping library of pokemons (Pokedex).

typedef std::unordered_map<pokemonId, Pokemon*> PokemonLibrary;
class Pokedex {
private:
    static PokemonLibrary p_instance;
public:
    Pokedex() = delete;
    ~Pokedex() = delete;
    Pokedex(const Pokedex&) = delete;
    Pokedex& operator=(const Pokedex&) = delete;
    static PokemonLibrary& instance() {                             /// I have parsed database ("pokedex.txt") and I wanted to
        if(p_instance.empty()){                                     /// have an opportunity to change pokemon stats
            std::ifstream in;                                       /// in new game but I also didn't want to have an opportunity
            in.open("../sources/pokedex.txt");                      /// to change stats during the game so I create a "Singleton"
            for(pokemonId i = 1; i <= NUMBER_OF_POKEMONS; i++){     /// Pokedex for the case if someone change smth during the game.
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
                pokemon >> num;
                for(int k = 0; k < num; k++) {
                    int t;
                    pokemon >> t;
                    p->addAbility(t);
                }
                p->setLevel(0);
                p->setId(i);
                p_instance.insert({i, p});
            }
        }
        return p_instance;
    }
};

inline PokemonLibrary Pokedex::p_instance = PokemonLibrary();


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

inline Pokemon* Pokemon::increaseLevel() {
    if (level < maxLevel) {
        level++;
        return this;
    } else {
        if(!nextPokemon)
            return this;
        Pokemon* p = PokemonPrototype::clone(nextPokemon, level + 1);
        delete this;
        return p;
    }
}


/// Next is a class of real, usual pokemon with formulas to get real stats
/// (previous has no real because they change with the level).
/// It is likely to be a pattern Decorator but not in the standard realization
/// because here will not be a lot of decorators (even in the longest development
/// maximum will be a RealPokemon, SuperPokemon and WeakPokemon) and they will
/// be able to "decorate" given pokemon by copy-constructor multiplying TYPE_CONST

class RealPokemon : public Pokemon {
private:
    const double TYPE_CONST = 1;
    double getRealStat(double __stat) const {return TYPE_CONST * __stat * 2 * m_pokemon->getLevel() / 100 + 5;}
    Pokemon* m_pokemon;
public:
    RealPokemon(): m_pokemon(nullptr), TYPE_CONST(1){};
    RealPokemon(Pokemon* __pokemon): TYPE_CONST(1 * __pokemon->getTypeConst()) {
        m_pokemon = __pokemon;
        m_pokemon->setHp(this->getMaxHp());
    }

    int getExp() const override {return m_pokemon->getExp();}
    int getMaxExp() const override {return 3 * m_pokemon->getLevel() * m_pokemon->getLevel() * m_pokemon->getLevel() / 2;}
    int getId() const override {return m_pokemon->getId();}
    const std::string &getName() const override {return m_pokemon->getName();}
    int getNextPokemon() const override {return m_pokemon->getNextPokemon();}
    int getLevel() const override {return m_pokemon->getLevel();}
    int getMaxLevel() const override {return m_pokemon->getMaxLevel();}
    int getHp() const override {return m_pokemon->getHp();}
    int getMaxHp() const override {return (int)this->getRealStat(m_pokemon->getMaxHp()) + 5 + this->getLevel();}
    double getAttack() const override {return this->getRealStat(m_pokemon->getAttack());}
    double getDefense() const override {return this->getRealStat(m_pokemon->getDefense());}
    double getSpAttack() const override {return this->getRealStat(m_pokemon->getSpAttack());}
    double getSpDefense() const override {return this->getRealStat(m_pokemon->getSpDefense());}
    double getSpeed() const override {return this->getRealStat(m_pokemon->getSpeed());}
    double getTypeConst() const override {return TYPE_CONST;}
    std::vector<pokType> getTypes() const override {return m_pokemon->getTypes();}
    std::vector<int> getAbilities() const override {return m_pokemon->getAbilities();}

    void setId(int __id) override {m_pokemon->setId(__id);}
    void setName(const std::string& __name) override {m_pokemon->setName(__name);}
    void setNextPokemon(int __nextPokemon) override {m_pokemon->setNextPokemon(__nextPokemon);}
    void setLevel(int __level) override {m_pokemon->setLevel(__level);}
    void setMaxLevel(int __maxLevel) override {m_pokemon->setMaxLevel(__maxLevel);}
    void setHp(int __health) override {m_pokemon->setHp(__health);}
    void setMaxHp(int __maxHealth) override {m_pokemon->setMaxHp(__maxHealth);}
    void setAttack(double __attack) override {m_pokemon->setAttack(__attack);}
    void setDefense(double __defense) override {m_pokemon->setDefense(__defense);}
    void setSpAttack(double __spAttack) override {m_pokemon->setSpAttack(__spAttack);}
    void setSpDefense(double __spDefense) override {m_pokemon->setSpDefense(__spDefense);}
    void setSpeed(double __speed) override {m_pokemon->setSpeed(__speed);}
    void addType(pokType __type) override {m_pokemon->addType(__type);}
    void addAbility(int __ability) override {m_pokemon->addAbility(__ability);}

    void print() override {
        std::cout << "#"  << m_pokemon->getId() << " " << m_pokemon->getName() << ", level " << m_pokemon->getLevel() << ".\nTypes: ";
        for(int i = 0; i < m_pokemon->getTypes().size() - 1; i++)
            std::cout << toString(m_pokemon->getTypes()[i]) << ", ";
        std::cout << toString(m_pokemon->getTypes()[m_pokemon->getTypes().size() - 1]) <<
        "\nHP: " << this->getHp() << " of " << this->getMaxHp() << '\n';
        std::cout.flush();
    }

    void addExp(int __add) override {
        if(__add + this->getExp() >= this->getMaxExp()) {
            int newExp = __add + this->getExp() - this->getMaxExp();
            this->increaseLevel();
            this->addExp(newExp);
        } else {
            m_pokemon->setExp(this->getExp() + __add);
        }
    }

    Pokemon* increaseLevel() override;
};

inline Pokemon* RealPokemon::increaseLevel() {
    if (m_pokemon->getLevel() < m_pokemon->getMaxLevel()) {
        m_pokemon->setLevel(m_pokemon->getLevel() + 1);
    } else {
        if(!m_pokemon->getNextPokemon())
            return this;
        Pokemon* p = PokemonPrototype::clone(m_pokemon->getNextPokemon(), m_pokemon->getLevel() + 1);
        delete m_pokemon;
        m_pokemon = p;
    }
    this->setHp(this->getMaxHp());
    this->setExp(0);
    return this;
}

#endif //POKEMONS_POKEMON_H
