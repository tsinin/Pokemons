.. image:: https://travis-ci.com/tsinin/Pokemons.svg?token=xFMVWzLEZnnkGNPjqGqA&branch=dev
    :target: https://travis-ci.com/tsinin/Pokemons

Guide to install:
1) Choos the directory where you want to install the game. (By default it is game root.)
2) Write "sudo ./installPokemons-linus.sh <install_path>".

Architecture scheme:

.. image:: https://pp.userapi.com/c853524/v853524299/3ca1b/1oYD_gFLHUk.jpg

Architecture description:
There are 6 main classes: Pokemon, Ability, Player, Location, Battle and Game. Banks of pokemons, abilities and locations are read from txt's in directory 'sources' and classes Pokedex, LocationBank and AbilityBank are responsible for it. They are Singletons. PokemonPrototype is responsible for cloning pokemons from Pokedex, and give them queried level. It is pattern Prorotype. 

class Player is responsible for storing  data about player. Class Battle is responsible for running a battle between player and pokemon.
Class Game is responsible for keeping Player, his location, and handing player's queries and calling commands. class Command is responsible for giving an interface of command. There are 9 commands that class Game can call. It is pattern Command. Also there is a class IObserver that gives interface for 3 observers. They're checking if player can fight/heal/buy pokeball. It is pattern Observer.

Class RealPokemon is responsible for pokemons with real stats (not from pokedex) because they're changing with level. Classes Pokemon and RealPokemon together make up pattern Decorator.

Refusing other patterns from the task:
Composite: It is for composing groups of objects to deal with them like with one object. I don't need it because it can only be in one place: grouping pokemons to fight with group of pokemons but in my game you can at the time manage only one pokemon.

Adapter and Proxy: I don't use any libraries that could have very big or not suiting interfaces and also all my interfaces suit all my requirements and use. Also I don't have very big objects that must be managed by Proxy, all objects have pointers to all objects they need. 

CoR or Visitor: I don't need CoR because all responsibilities of all Commands are one-off so they don't need to redirect some problem to other commands. Visitor is a pattern for the situation when a lot of classes should be completed by a similar function and I don't have this situation.











