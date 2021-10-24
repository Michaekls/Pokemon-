#include "charmander.h"
#include <iostream>

Charmander::Charmander()
{
    this->zmienNazwa("charmander");
}

Charmander::Charmander(std::string imie)
{
    this->zmienNazwa(imie);
}
