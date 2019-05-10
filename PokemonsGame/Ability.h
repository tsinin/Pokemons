#ifndef POKEMONS_ABILITY_H
#define POKEMONS_ABILITY_H
#include "Pokemon.h"

inline double types[18][18] = {{  1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   1,   1,   1,   0,   1,   1,   1,   1},
                        {  1, 0.5,   2,   1, 0.5, 0.5,   1,   1,   2,   1,   1, 0.5,   2,   1,   1,   1, 0.5, 0.5},
                        {  1, 0.5, 0.5,   2,   2, 0.5,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1, 0.5,   1},
                        {  1,   1,   1, 0.5,   1,   1,   1,   1,   2, 0.5,   1,   1,   1,   1,   1,   1, 0.5,   1},
                        {  1,   2, 0.5, 0.5, 0.5,   2,   1,   2, 0.5,   2,   1,   2,   1,   1,   1,   1,   1,   1},
                        {  1,   2,   1,   1,   1, 0.5,   2,   1,   1,   1,   1,   1,   2,   1,   1,   1,   2,   1},
                        {  1,   1,   1,   1,   1,   1,   1,   1,   1,   2,   2, 0.5, 0.5,   1,   1, 0.5,   1,   2},
                        {  1,   1,   1,   1, 0.5,   1, 0.5, 0.5,   2,   1,   2, 0.5,   1,   1,   1,   1,   1, 0.5},
                        {  1,   1,   2,   0,   2,   2,   1, 0.5,   1,   1,   1,   1, 0.5,   1,   1,   1,   1,   1},
                        {  1,   1,   1,   2, 0.5,   2, 0.5,   1,   0,   1,   1, 0.5,   2,   1,   1,   1,   1,   1},
                        {  1,   1,   1,   1,   1,   1, 0.5,   1,   1,   1, 0.5,   2,   1,   2,   1,   2,   1,   1},
                        {  1,   2,   1,   1, 0.5,   1, 0.5,   1, 0.5,   2,   1,   1,   2,   1,   1,   1,   1,   1},
                        {0.5, 0.5,   2,   1,   2,   1,   2, 0.5,   2, 0.5,   1,   1,   1,   1,   1,   1,   2,   1},
                        {  0,   1,   1,   1,   1,   1,   0, 0.5,   1,   1,   1, 0.5,   1,   2,   1,   2,   1,   1},
                        {  0, 0.5, 0.5, 0.5, 0.5,   2,   1,   1,   1,   1,   1,   1,   1,   1,   2,   1,   1,   2},
                        {  1,   1,   1,   1,   1,   1,   2,   1,   1,   1,   0,   2,   1, 0.5,   1, 0.5,   1,   2},
                        {0.5,   2,   1,   1, 0.5, 0.5,   2,   0,   2, 0.5, 0.5, 0.5, 0.5,   1, 0.5,   1, 0.5, 0.5},
                        {  1,   1,   1,   1,   1,   1, 0.5,   2,   1,   1,   1, 0.5,   1,   1,   0, 0.5,   2,   1}};

class Ability{
private:
    std::string name;
    int attackPower;
    Pokemon *obj, *subj;
    bool special;
public:
    const std::string &getName() const {return name;}
    int getAttackPower() const {return attackPower;}
    Pokemon *getObj() const {return obj;}
    Pokemon *getSubj() const {return subj;}
    bool getSpecial() const {return special;}

    void setName(const std::string &__name) {name = __name;}
    void setAttackPower(int __attackPower) {attackPower = __attackPower;}
    void setObj(Pokemon *__obj) {obj = __obj;}
    void setSubj(Pokemon *__subj) {subj = __subj;}
    void setSpecial(bool __special) {special = __special;}

    Ability(): name(""), attackPower(0), obj(nullptr), subj(nullptr), special(false) {};

    Ability(const Ability& ability) {
        name = ability.getName();
        attackPower = ability.getAttackPower();
        obj = ability.getObj();
        subj = ability.getSubj();
        special = ability.getSpecial();
    }

    void execute() {
        int damage;
        if(!special) {
            damage = (int)((2 * obj->getLevel() + 10) * obj->getAttack() * attackPower / 250 /
                           subj->getDefense() + 2);
            for(auto t: obj->getTypes())
                for(auto p: subj->getTypes())
                    damage = (int)((double)damage * types[p][t]);
        }
        else
            damage = (int)((2 * obj->getLevel() + 10) * obj->getSpAttack() * attackPower / 250 /
                    subj->getSpDefense() + 2);
        subj->setHp(std::max(0, subj->getHp() - damage));
    }

    void print() {
        std::cout << name << ", Power = " << attackPower << '\n';
    }
};

typedef std::unordered_map<int, Ability*> AbilityLibrary;
class AbilityBank {
private:
    static AbilityLibrary a_instance;
public:
    AbilityBank() = delete;
    ~AbilityBank() = delete;
    AbilityBank(const AbilityBank&) = delete;
    AbilityBank& operator=(const AbilityBank&) = delete;
    static AbilityLibrary& instance() {
        if(a_instance.empty()){
            std::ifstream in;
            in.open("../sources/abilities.txt");
            int numOfAbilities;
            in >> numOfAbilities;
            std::string ability;
            getline(in, ability);
            for(int i = 0; i < numOfAbilities; ++i) {
                getline(in, ability);
                auto *newAbility = new Ability();
                int a = ability.find('\'');
                int b = ability.find('\'', a + 1);
                newAbility->setName(ability.substr(a + 1, b - a - 1));
                std::string temp = ability.substr(b + 1);
                std::stringstream sin(temp);
                int power;
                sin >> power;
                newAbility->setAttackPower(power);
                bool special;
                sin >> special;
                newAbility->setSpecial(special);
                a_instance.insert({i, newAbility});
            }
        }
        return a_instance;
    }
};

inline AbilityLibrary AbilityBank::a_instance = AbilityLibrary();

#endif //POKEMONS_ABILITY_H
