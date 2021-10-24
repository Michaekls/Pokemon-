#ifndef POKEMON_OGNISTY_H
#define POKEMON_OGNISTY_H

#include "pokemon.h"

class Pokemon_ognisty : public Pokemon
{
public:
    Pokemon_ognisty();
    Pokemon_ognisty(std::string imie);
    void Atack2(Pokemon* poke);

};

#endif // POKEMON_OGNISTY_H
