#include "pokemon.h"
#include <iostream>

int Pokemon::Number_pokemon=-1;

int Pokemon::getMax_zycie() const
{
    return max_zycie;
}

int Pokemon::getLvl() const
{
    return lvl;
}

Pokemon::Pokemon()
{
    ++Number_pokemon;
    Nazwa = "Pokemon" + std::to_string(Number_pokemon);
    typ = "normalny";
    obrona = 5;
    atak = 5;
    życie = 44;
    max_zycie=44;
}

Pokemon::Pokemon(std::string imie)
{
    ++Number_pokemon;
    Nazwa = imie;
    typ = "normalny";
    obrona = 15;
    atak = 15;
    życie = 44;
    max_zycie=44;
}

Pokemon::~Pokemon()
{
    std::cout << "Pokemon pokonany " << std::endl;
    --Number_pokemon;
}

std::string Pokemon::getNazwa()
{
    return this->Nazwa;
}

std::string Pokemon::getTyp()
{
    return this->typ;
}

void Pokemon::setAtak(int atak)
{
    this->atak=atak;
}

void Pokemon::setTyp(std::string typ)
{
    this->typ = typ;
}

void Pokemon::setMax_zycie(int zycie)
{
    this->max_zycie = zycie;
}

void Pokemon::zmienNazwa(std::string newNazwa)
{
    this->Nazwa = newNazwa;
}

void Pokemon::setŻycie(int zycie)
{
    this->życie = zycie;
}

void Pokemon::setObrona(int obrona)
{
    this->obrona = obrona;
}

int Pokemon::getŻycie() const
{
    return this->życie;
}

void Pokemon::zmienŻycie(int atak)
{
    this->życie = this->życie - 2*atak/this->obrona-1;
}


int Pokemon::getObrona() const
{
    return this->obrona;
}

int Pokemon::getAtak() const
{
    return this->atak;
}


void Pokemon::Atack(Pokemon *poke)
{
    std::cout << "atak zwykly" << std::endl;
    poke->zmienŻycie(this->getAtak());
    //return this->atak*2;
}

void Pokemon::Atack2(Pokemon *poke)
{
    std::cout << "atak zwykly" << std::endl;
    poke->zmienŻycie(this->getAtak());

}

void Pokemon::awans(int pokaz=0)
{
    if(pokaz==0)
    {
        std::cout << "\nPokemon " << this->Nazwa << " awansowal: "  << std::endl;

        std::cout << "Atak: " << this->getAtak() << "->";
        this->setAtak(this->getAtak()+2);
        std::cout << this->getAtak() << std::endl;;

        std::cout << "Obrona: "<< this->getObrona() << "->";
        this->setObrona(this->getObrona()+2);
        std::cout << this->getObrona() << std::endl;

        std::cout << "Max zycie: " << this->getMax_zycie() << "->";
        this->setMax_zycie(this->getMax_zycie()+4);
        std::cout << this->getMax_zycie() << std::endl;
    }
    else
    {
        this->setAtak(this->getAtak()+2);
        this->setObrona(this->getObrona()+2);
        this->setMax_zycie(this->getMax_zycie()+4);
    }
    this->lvl++;
}
