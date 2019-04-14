#ifndef POKEMONS_LOCATION_H
#define POKEMONS_LOCATION_H

#include "Pokemon.h"

class Location {
private:
    std::string name;
    std::string description;
    int averageLevel;
    std::vector<pokemonId> localPokemons = std::vector<pokemonId>(0);
    std::vector<int> probability = std::vector<pokemonId>(0);
    int sumProbability;
public:
    Location(): name(""), description(""), averageLevel(0), sumProbability(0) {};

    void setName(const std::string &_name) {name = _name;}
    void setDescription(const std::string &_description) {description = _description;}
    void setAverageLevel(int _averageLevel) {averageLevel = _averageLevel;}
    void setLocalPokemons(const std::vector<int> &_localPokemons) {localPokemons = _localPokemons;}
    void setProbability(const std::vector<int> &_probability) {probability = _probability;}
    void setSumProbability(int _sumProbability) {sumProbability = _sumProbability;}

    const std::string &getName() const {return name;}
    const std::string &getDescription() const {return description;}
    int getAverageLevel() const {return averageLevel;}
    const std::vector<int> &getLocalPokemons() const {return localPokemons;}
    const std::vector<int> &getProbability() const {return probability;}
    int getSumProbability() const {return sumProbability;}

};



#endif //POKEMONS_LOCATION_H
