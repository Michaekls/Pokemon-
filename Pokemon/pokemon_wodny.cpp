#include "pokemon_wodny.h"
#include <iostream>

Pokemon_wodny::Pokemon_wodny()
{
    this->setTyp("wodny");
    this->setAtak(5);
    this->setObrona(7);
}

Pokemon_wodny::Pokemon_wodny(std::string imie)
{
    this->setAtak(9);
    this->setObrona(7);
    this->setŻycie(55);
    this->setMax_zycie(55);
    this->setTyp("wodny");
    this->zmienNazwa(imie);
}

void Pokemon_wodny::Atack2(Pokemon *poke)
{
    std::cout << "wodny atak" << std::endl;
    if(poke->getTyp()=="ognisty")
    {
        poke->zmienŻycie(this->getAtak()+40);
    }
    else if(poke->getTyp()=="roslinny")
    {
        poke->zmienŻycie(this->getAtak()-20);
    }
    else
    {
        poke->zmienŻycie(this->getAtak()+10);
    }
}
