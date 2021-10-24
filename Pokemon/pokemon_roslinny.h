#ifndef POKEMON_ROSLINNY_H
#define POKEMON_ROSLINNY_H

#include "pokemon.h"

class Pokemon_roslinny : public Pokemon
{
public:
    Pokemon_roslinny();
    Pokemon_roslinny(std::string imie);
    void Atack2(Pokemon* poke);
};

#endif // POKEMON_ROSLINNY_H
