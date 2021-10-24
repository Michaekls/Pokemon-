#ifndef PLECAK_H
#define PLECAK_H

#include <vector>

class Plecak
{
friend class Pokemon;
private:
    int mikstura_leczaca;
    int pokebol;

    std::vector<Pokemon*> pokemony;

public:
    Plecak();
    void uzycie_mikstury(Pokemon* poke);
    bool uzycie_pokebola(Pokemon *poke_zlap);
    void dodaj_pokemona(Pokemon* poke);
    void pokaz_moje_pokemony();


    void setMikstura_leczaca(int newMikstura_leczaca);
    void setPokebol(int newPokebol);
    int getMikstura_leczaca() const;
    int getPokebol();
    int getIlosc_pokemonow();
};

#endif // PLECAK_H
