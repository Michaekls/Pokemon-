#include "pokemon_ognisty.h"
#include <iostream>

Pokemon_ognisty::Pokemon_ognisty()
{
    //std::cout << "pokemon ognisty" << std::endl;
    this->setTyp("ognisty");
    this->setAtak(6);
    this->setObrona(6);
}

Pokemon_ognisty::Pokemon_ognisty(std::string imie)
{
    this->setAtak(8);
    this->setObrona(8);
    this->setŻycie(64);
    this->setMax_zycie(64);
    this->setTyp("ognisty");
    this->zmienNazwa(imie);
}

void Pokemon_ognisty::Atack2(Pokemon* poke)
{
    std::cout << "ognisty atak" << std::endl;
    if(poke->getTyp()=="roslinny")
    {
        poke->zmienŻycie(this->getAtak()+40);
    }
    else if(poke->getTyp()=="wodny")
    {
        poke->zmienŻycie(this->getAtak()-20);
    }
    else
    {
        poke->zmienŻycie(this->getAtak()+10);
    }
}
