#include "plecak.h"
#include "pokemon.h"
#include <iostream>
#include <vector>

void Plecak::setMikstura_leczaca(int newMikstura_leczaca)
{
    mikstura_leczaca = newMikstura_leczaca;
}

void Plecak::setPokebol(int newPokebol)
{
    pokebol = newPokebol;
}

int Plecak::getMikstura_leczaca() const
{
    return mikstura_leczaca;
}

int Plecak::getPokebol()
{
    return this->pokebol;
}

int Plecak::getIlosc_pokemonow()
{
    return pokemony.size();
}

Plecak::Plecak()
{
    this->mikstura_leczaca = 5;
    this->pokebol = 15;
}

void Plecak::uzycie_mikstury(Pokemon *poke)
{
    if(getMikstura_leczaca()>0)
    {
        if(poke->getMax_zycie() - poke->getŻycie() <= 20)
        {
            poke->setŻycie(poke->getMax_zycie());
        }
        else
        {
            poke->setŻycie(poke->getŻycie()+20);
        }
        this->setMikstura_leczaca(this->getMikstura_leczaca()-1);
        std::cout<< "Pozostalo: " << getMikstura_leczaca() << " mikstur leczacych" << std::endl;

    }
    else
    {
        std::cout << "Nie masz juz mikstur" << std::endl;
    }
}

bool Plecak::uzycie_pokebola(Pokemon *poke_zlap)
{
    if(this->getPokebol() >0 )
    {
        this->setPokebol(this->getPokebol()-1);

        if(rand() % 100 + 1 > poke_zlap->getŻycie()*2 )
        {
            this->dodaj_pokemona(poke_zlap);
            return true;
        }
        else
        {
            std::cout << "\n Nie udalo sie zlapac pokemona";
            return false;
        }
    }
    else
    {
        std::cout << "Nie masz pokeboli" << std::endl;
        return false;
    }

    //this->pokemony.push_back(poke_zlap);
}

void Plecak::dodaj_pokemona(Pokemon *poke)
{
    this->pokemony.push_back(poke);
    std::cout << "zlapales pokemona!   " << poke->getNazwa() << "  pokemon " << poke->getTyp() << std::endl;
}

void Plecak::pokaz_moje_pokemony()
{

    for(int i=0 ; i<this->pokemony.size() ; i++)
    {
        std::cout << "Pokemon nr " << i+1 << ":" << this->pokemony[i]->getNazwa() << std::endl;
    }
    std::cout << std::endl;
}
