#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
//friend class Plecak;

private:
    std::string Nazwa;
    std::string typ;
    int życie;
    int obrona;
    int atak;
    int max_zycie;
    int lvl=0;

public:
    static int Number_pokemon;
    Pokemon();
    Pokemon(std::string imie);
    virtual ~Pokemon();
    void Atack(Pokemon* poke);
    void virtual Atack2(Pokemon* poke);

    void zmienŻycie(int atak);
    void zmienNazwa(std::string newNazwa);
    void awans(int pokaz);

// setter and getter

    void setŻycie(int zycie);
    void setObrona(int obrona);
    void setAtak(int atak);
    void setTyp(std::string typ);
    void setMax_zycie(int zycie);

    std::string getNazwa();
    std::string getTyp();
    int getŻycie() const;
    int getObrona() const;
    int getAtak() const;

    int getMax_zycie() const;
    int getLvl() const;
};


#endif // POKEMON_H
