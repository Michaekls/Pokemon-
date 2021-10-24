#include "pokemon_roslinny.h"
#include <iostream>

Pokemon_roslinny::Pokemon_roslinny()
{
    this->setTyp("roslinny");
    this->setAtak(7);
    this->setObrona(5);
    //std::cout << "pokemon roslinny" << std::endl;
}

Pokemon_roslinny::Pokemon_roslinny(std::string imie)
{
    this->setAtak(7);
    this->setObrona(9);
    this->setŻycie(66);
    this->setMax_zycie(66);
    this->setTyp("roslinny");
    this->zmienNazwa(imie);
}

void Pokemon_roslinny::Atack2(Pokemon *poke)
{
    std::cout << "roslinny atak" << std::endl;
    if(poke->getTyp()=="wodny")
    {
        poke->zmienŻycie(this->getAtak()+40);
    }
    else if(poke->getTyp()=="ognisty")
    {
        poke->zmienŻycie(this->getAtak());
    }
    else
    {
        poke->zmienŻycie(this->getAtak()+10);
    }
}
