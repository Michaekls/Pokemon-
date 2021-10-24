#ifndef POKEMON_WODNY_H
#define POKEMON_WODNY_H

#include "pokemon.h"

class Pokemon_wodny : public Pokemon
{
public:
    Pokemon_wodny();
    Pokemon_wodny(std::string imie);
    void Atack2(Pokemon* poke);
};

#endif // POKEMON_WODNY_H
