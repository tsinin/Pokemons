#!/usr/bin/env bash

DIR="./"

sudo apt install g++

sudo apt-get install make

sudo apt-get install cmake

cd build
cmake ..
make

cd ..


if [ $# = '1' ] ; then
    DIR="$1"
    sudo mkdir $HOME/$DIR
    mkdir $HOME/$DIR/Pokemons
    mkdir $HOME/$DIR/Pokemons/bin
    mkdir $HOME/$DIR/Pokemons/sources
    mv -u build/Pokemons $HOME/$DIR/Pokemons/bin
    cp -u sources/* $HOME/$DIR/Pokemons/sources
    echo "Game installed in $HOME/$DIR/Pokemons/bin"
else
    echo "Game installed in Pokemons/build"
fi

