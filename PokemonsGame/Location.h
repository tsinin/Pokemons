#ifndef POKEMONS_LOCATION_H
#define POKEMONS_LOCATION_H

#include "Player.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

class Location {
private:
    std::string name;
    std::string description;
    std::vector<pokemonId> localPokemons = std::vector<pokemonId>(0);
    std::vector<int> probability = std::vector<pokemonId>(0);
    int sumProbability;
    int averageLevel;
    std::vector<Location*> neighbours = std::vector<Location*>(0);
public:
    Location(): name(""), description(""), averageLevel(0), sumProbability(0) {};
    Location(const Location& loc) {
        name = loc.name;
        description = loc.description;
        localPokemons = std::vector<pokemonId>(loc.localPokemons);
        probability = std::vector<int>(loc.probability);
        sumProbability = loc.sumProbability;
        averageLevel = loc.averageLevel;
        neighbours = std::vector<Location*>(loc.neighbours);
    }

    void setName(const std::string &_name) {name = _name;}
    void setDescription(const std::string &_description) {description = _description;}
    void setAverageLevel(int _averageLevel) {averageLevel = _averageLevel;}
    void setLocalPokemons(const std::vector<int> &_localPokemons) {localPokemons = _localPokemons;}
    void setProbability(const std::vector<int> &_probability) {probability = _probability;}
    void setSumProbability(int _sumProbability) {sumProbability = _sumProbability;}
    void addNeighbour(Location* __location) {neighbours.emplace_back(__location);}

    const std::string &getName() const {return name;}
    const std::string &getDescription() const {return description;}
    int getAverageLevel() const {return averageLevel;}
    const std::vector<int> &getLocalPokemons() const {return localPokemons;}
    const std::vector<int> &getProbability() const {return probability;}
    int getSumProbability() const {return sumProbability;}
    std::vector<Location*> getNeighbours() const {return neighbours;}

    Pokemon* getRandomPokemon() {
        if(neighbours.empty())
            return nullptr;
        int rand_pok = rand() % sumProbability + 1;
        int pok_num = 0;
        for(int i = 0; i < localPokemons.size(); ++i) {
            rand_pok -= probability[i];
            if(rand_pok <= 0) {
                pok_num = localPokemons[i];
                break;
            }
        }
        int level;
        if(rand() % 2)
            level = (int)(averageLevel * (1 + (0.15 * (rand() % 101) / 100)));
        else
            level = (int)(averageLevel * (1 - (0.15 * (rand() % 101) / 100)));
        return new RealPokemon(PokemonPrototype::clone(pok_num, level));
    }

    void print() {
        std::cout << name << ". " << description << '\n';
        std::cout << "Local pokemons are:\n";
        for(auto t: localPokemons) {
            auto p = PokemonPrototype::clone(t, 1);
            std::cout << "---" << p->getName() << '\n';
            delete p;
        }
    }
    void printNeighbours() {
        for(int i = 0; i < neighbours.size(); ++i)
            std::cout << i + 1 << ". " << neighbours[i]->getName() << std::endl;
    }
};


typedef std::unordered_map<int, Location*> LocationLibrary;
class LocationBank {
private:
    static LocationLibrary l_instance;
public:
    LocationBank() = delete;
    ~LocationBank() = delete;
    LocationBank(const LocationBank&) = delete;
    LocationBank& operator=(const LocationBank&) = delete;
    static LocationLibrary& instance() {
        if(l_instance.empty()){
            std::ifstream in;
            in.open("../sources/locations.txt");
            int numOfLocations;
            in >> numOfLocations;
            std::string location;
            getline(in, location);
            std::vector<Location*> lib(0);
            std::vector<std::vector<int>> neighboursVector(0, std::vector<int>(0, 0));
            for(int i = 0; i < numOfLocations; ++i) {
                getline(in, location);
                auto *newLocation = new Location();
                int a = location.find('\'');
                int b = location.find('\'', a + 1);
                newLocation->setName(location.substr(a + 1, b - a - 1));
                a = location.find('\'', b + 1);
                b = location.find('\'', a + 1);
                newLocation->setDescription(location.substr(a + 1, b - a - 1));
                std::string temp = location.substr(b + 1);
                std::stringstream sin(temp);
                int numOfPokemons;
                sin >> numOfPokemons;
                std::vector<pokemonId> pokemons(numOfPokemons, 0);
                for(int j = 0; j < numOfPokemons; ++j)
                    sin >> pokemons[j];
                int sumOfProbabilities = 0;
                std::vector<int> probabilities(numOfPokemons, 0);
                for(int j = 0; j < numOfPokemons; ++j) {
                    sin >> probabilities[j];
                    sumOfProbabilities += probabilities[j];
                }
                newLocation->setLocalPokemons(pokemons);
                newLocation->setProbability(probabilities);
                newLocation->setSumProbability(sumOfProbabilities);
                int averageLevel;
                sin >> averageLevel;
                newLocation->setAverageLevel(averageLevel);
                int numOfNeighbours;
                sin >> numOfNeighbours;
                std::vector<int> neighbours(numOfNeighbours, 0);
                for(int j = 0; j < numOfNeighbours; ++j)
                    sin >> neighbours[j];
                neighboursVector.emplace_back(neighbours);
                lib.emplace_back(newLocation);
            }
            for(int i = 0; i < numOfLocations; ++i)
                for(int j = 0; j < neighboursVector[i].size(); ++j)
                    lib[i]->addNeighbour(lib[neighboursVector[i][j]]);
            for(int i = 0; i < numOfLocations; ++i)
                l_instance.insert({i, lib[i]});
        }
        return l_instance;
    }
};

LocationLibrary LocationBank::l_instance = LocationLibrary();

#endif //POKEMONS_LOCATION_H
