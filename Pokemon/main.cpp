#include <iostream>
#include <stdio.h>
#include <time.h>

#include "plecak.h"
#include "pokemon.h"
#include "pokemon_ognisty.h"
#include "pokemon_roslinny.h"
#include "pokemon_wodny.h"
#include "charmander.h"
#include "bulbasaur.h"
#include "squirtle.h"
#include "caterpie.h"
#include "vulpix.h"
#include "psyduck.h"

void Wymaluj_pole(std::string pole[10][10])
{
    std::cout << "\n";
    for(int i=0; i<10 ;i++)
    {
        for(int j=0; j<10; j++)
        {
            std::cout << pole[i][j];
        }
        std::cout << std::endl;
    }
}

int walka(Pokemon* poke1, Pokemon* przeciwnik, Plecak* plecak)
{
    int wybor;
    std::cout << "Walka!:\n" << poke1->getNazwa() << " typ: " << poke1->getTyp() << " " << "lvl:" << poke1->getLvl() << " przeciwko "
    << przeciwnik->getNazwa() << " typ: " << przeciwnik->getTyp() << " " << "lvl:" << poke1->getLvl() << std::endl;

    int runda = 0;
    do
    {
        std::cout << std::endl << "RUNDA: " << runda++ << std::endl << std::endl;
        std::cout << "Moj pokemon: " << poke1->getNazwa() << " typ: " << poke1->getTyp()<< " " << "lvl:" << poke1->getLvl();
        for(int i=0;i<21-poke1->getNazwa().length()-poke1->getTyp().length();i++)
        {
            std::cout << " ";
        }
        std::cout<< "Pokemon przeciwnika: " << przeciwnik->getNazwa() << " typ: " << przeciwnik->getTyp()<< " " << "lvl:" << poke1->getLvl() << std::endl;
        std::cout << "Sila: " << poke1->getAtak();
        int dlugolsc_atak;
        if (poke1->getAtak()<10) { dlugolsc_atak = 1; }
        else { dlugolsc_atak = 2; }
        for( int i=0 ; i<40-dlugolsc_atak; i++)
        {
            std::cout << " ";
        }
        std::cout<< "Sila: " << przeciwnik->getAtak() << std::endl;

        int dlugolsc_obrona;
        if (poke1->getObrona()<10) { dlugolsc_obrona = 1; }
        else { dlugolsc_obrona = 2; }
        std::cout << "Obrona: " << poke1->getObrona();
        for(int i=0;i<38-dlugolsc_obrona;i++)
        {
            std::cout << " ";
        }
        std::cout << "Obrona: " << przeciwnik->getObrona() << std::endl;


        int dlugolsc_zycie;
        if (poke1->getŻycie()<10) { dlugolsc_zycie = 1; }
        else { dlugolsc_zycie = 2; }

        std::cout << "Zycie: " << poke1->getŻycie();
        for(int i=0 ; i<39-dlugolsc_zycie; i++)
        {
            std::cout << " ";
        }
        std::cout << "Zycie: " << przeciwnik->getŻycie() << std::endl;


        ponow_wybor_ataku:
        std::cout << std::endl << "co chcesz zrobic?" << std::endl;
        std::cout << "1 - atak zwykle " << "2 - atak specjalny " << "3 - mikstura leczaca " << "4 - rzuc pokebolem" << " 5 - uciekaj" << std::endl;
        std::cin >> wybor;
        int zycie_przeciwnika= przeciwnik->getŻycie();
        int zycie_mojego_pokemona = poke1->getŻycie();
        switch(wybor)
        {
        case 1:
            poke1->Atack(przeciwnik);
            std::cout << "Twoj atak zadaje: ";
            std::cout << zycie_przeciwnika - przeciwnik->getŻycie()<< "pkt obrazen" << std::endl;
            break;
        case 2:
            poke1->Atack2(przeciwnik);
            std::cout << "Twoj atak zadaje: ";
            std::cout << zycie_przeciwnika - przeciwnik->getŻycie()<< "pkt obrazen" << std::endl;
            break;
        case 3:
            plecak->uzycie_mikstury(poke1);
            std::cout<< "zycie: " << zycie_mojego_pokemona << "->" << poke1->getŻycie() << std::endl;
            goto ponow_wybor_ataku;
            break;
        case 4:
            bool czy_zlapano_pokemona;
            czy_zlapano_pokemona = plecak->uzycie_pokebola(przeciwnik);
            if (czy_zlapano_pokemona == true)
            {
                return 1;
            }
            break;
        case 5:
            return -1;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            goto ponow_wybor_ataku;
        }
        if(przeciwnik->getŻycie()<=0)
        {
            delete przeciwnik;
            poke1->awans(0);
            return 1;
        }
        //clock_t  wait;
        //wait = clock()+500;
        //while(clock() < wait) {}

        if(przeciwnik->getŻycie()>0)
        {
            std::cout << "\nPrzeciwnik atakuje: " << std::endl;
            switch(rand() % 2 +1)
            {
            case 1:
                przeciwnik->Atack(poke1);
                std::cout << "Atak przeciwnika zadaje: ";
                std::cout << zycie_mojego_pokemona - poke1->getŻycie() << "pkt obrazen" << std::endl;
                break;
            case 2:
                przeciwnik->Atack2(poke1);
                std::cout << "Atak przeciwnika zadaje: ";
                std::cout << zycie_mojego_pokemona - poke1->getŻycie() << "pkt obrazen" << std::endl;
                break;
        }
        //clock_t  wait;
        //wait = clock()+500;
        //while(clock() < wait) {}
        if(poke1->getŻycie()<=0)
        {
            delete poke1;
            return 0;
        }
        }

    }while(przeciwnik->getŻycie()>0  && poke1->getŻycie()>0);
    return -1;
}

void game()
{
    const int wielkosc_planszy2 = 10;
    int nr_pokemona=0;
    int ilosc_pokemonow;
    char isc;
    char tak_nie;
    int pozycja[2]={0,0};
    int nr;
    std::string imie_pokemona;
    Plecak* plecak = new Plecak();

    Wybor_pokemona:
    std::cout << "\nWybierz swojego pokemona" << std::endl;
    std::cout << "1 - charmander, 2-squirtle, 3-bulbasaur" << std::endl;
    std::cin >> nr;
    if(nr==1 || nr==2 || nr==3)
    {
        Wybor_imienia:
        std::cout << "\nPamietaj ze kazdy pokemon z imieniem jest wyjatkowy" << std::endl;
        std::cout << "Czy chcesz mu nadac imie? [y/n]:" << std::endl;

    }
    std::cin >> tak_nie;
    switch(tak_nie)
    {
    case 'y':
        std::cout << "Wpisz imie: ";
        std::cin >> imie_pokemona;
        break;
    case 'n':
        break;
    default:
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        goto Wybor_imienia;
    }
    std::cout << std::endl;

    Pokemon *poke1;
    switch(nr)
    {
    case 1:
         std::cout << "Gratulacje wybrales charmandera" << std::endl;
         if(tak_nie=='y')
         {
            poke1 = new Charmander(imie_pokemona);
         }
         else
         {
             poke1 = new Charmander();
         }

        break;
    case 2:
        std::cout << "Gratulacje wybrales squirtle" << std::endl;
        if(tak_nie=='y')
        {
           poke1 = new Squirtle(imie_pokemona);
        }
        else
        {
            poke1 = new Squirtle();
        }
        break;
    case 3:
        std::cout << "Gratulacje wybrales bulbasaura" << std::endl;
        if(tak_nie=='y')
        {
           poke1 = new Bulbasaur(imie_pokemona);
        }
        else
        {
            poke1 = new Bulbasaur();
        }
        break;
    default:
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        goto Wybor_pokemona;
    }
    plecak->dodaj_pokemona(poke1);




    std::cout << "\n";
    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" << std::endl;
    std::cout << "Jesli zlapales po drodze co najmniej 4 pokemonow to wygrales!!!\n" << std::endl;
    std::cout << "Rozpoczynasz gre majac 15 pokeboli i 5 mikstur leczacych" << std::endl;
    std::cout << "mikstury leczace lecza do 20 punktow zycia \n" << std::endl;
    std::cout << "jesli zabijesz innego pokemona to Twoj pokemon dostanie awans" << std::endl;
    std::cout << "jesli go zlapiensz awansu nie dostaniesz\n" << std::endl;

    std::cout << "Pamietaj!!" << std::endl;
    std::cout << "Pokemon ognisty jest dobry na pokemony roslinne a słaby na pokemony wodne" <<std::endl;
    std::cout << "Pokemon roslinny jest dobry na pokemony wodne a słaby na pokemony ogniste" <<std::endl;
    std::cout << "Pokemon wodny jest dobry na pokemony ogniste a słaby na pokemony roslinne\n" <<std::endl;


    int rozmieszczenie_pokemonow[wielkosc_planszy2][wielkosc_planszy2];
    for(int i=0; i<wielkosc_planszy2 ;i++)
    {
        for(int j=0; j<wielkosc_planszy2; j++)
        {
            rozmieszczenie_pokemonow[i][j]=0;
        }
    }

    std::cout << "\nIle chcesz miec pokemonow na planszy?" << std::endl;
    std::cout << "Wybierz liczbe miedzy 8 a 15" << std::endl;
    std::cin >> ilosc_pokemonow;
    while( !(ilosc_pokemonow) || (ilosc_pokemonow<8 || ilosc_pokemonow>15))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        std::cout << "Wybierz liczbe miedzy 8 a 15" << std::endl;
        std::cin >> ilosc_pokemonow;
    }
    //Pokemon** przeciwnik = new Pokemon* [ilosc_pokemonow];
    std::vector <Pokemon*> przeciwnik;
    Pokemon* pokemon;
    for(int i=0; i<ilosc_pokemonow; i++ )
    {
        switch(rand() % 7+1)
        {
        case 1:
            pokemon = new Pokemon();
            przeciwnik.push_back(pokemon);
            break;
            //przeciwnik[i] = new Pokemon;
        case 2:
            pokemon = new Charmander();
            przeciwnik.push_back(pokemon);
            break;
            //przeciwnik[i] = new Pokemon_ognisty;
        case 3:
            pokemon = new Squirtle();
            przeciwnik.push_back(pokemon);
            break;
            //przeciwnik[i] = new Pokemon_wodny;
        case 4:
            pokemon = new Bulbasaur();
            przeciwnik.push_back(pokemon);
            break;
        case 5:
            pokemon = new Caterpie();
            przeciwnik.push_back(pokemon);
            break;
        case 6:
            pokemon = new Vulpix();
            przeciwnik.push_back(pokemon);
            break;
        case 7:
            pokemon = new Psyduck();
            przeciwnik.push_back(pokemon);
            break;
        }
    }
    //pozniom
    for(int i=0; i< rand() % 3+0; i++)
    {
        pokemon->awans(-1);
    }

    for(int i=0; i<ilosc_pokemonow; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if(rozmieszczenie_pokemonow[x][y]==1 || (x==0 && y==0))
        {
            i--;
        }
        else
        {
        rozmieszczenie_pokemonow[x][y]=1;
        }
    }
    for(int i=0; i<4; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if(rozmieszczenie_pokemonow[x][y]==1 || (x==0 && y==0) || rozmieszczenie_pokemonow[x][y]==2)
        {
            i--;
        }
        else
        {
        rozmieszczenie_pokemonow[x][y]=2;
        }
    }
    for(int i=0; i<4; i++)
    {
        int x = rand() % 10;
        int y = rand() % 10;

        if(rozmieszczenie_pokemonow[x][y]==1 || (x==0 && y==0) || rozmieszczenie_pokemonow[x][y]==2 || rozmieszczenie_pokemonow[x][y]==3)
        {
            i--;
        }
        else
        {
        rozmieszczenie_pokemonow[x][y]=3;
        }
    }


    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n" << std::endl;
    std::cout << "Twoj ruch\n" << std::endl;
    std::cout << "Znajdujesz sie na polu o, idz pokonuj i lap pokemony" << std::endl;
    std::cout << "Gra konczy sie jesli dojdziesz do pola H:\n" << std::endl;
    std::string pole[wielkosc_planszy2][wielkosc_planszy2];
    for(int i=0; i<wielkosc_planszy2 ;i++)
    {
        for(int j=0; j<wielkosc_planszy2; j++)
        {
            if (i==0 and j==0)
            {
                pole[i][j]="o";
            }
            else if (i==wielkosc_planszy2-1 and j==wielkosc_planszy2-1)
            {
                pole[i][j]="H";             }
            else
            {
                pole[i][j]='x';
            }
            std::cout << pole[i][j];
        }
        std::cout << std::endl;
    }
    pole[0][0]="-";
    bool tru=true;
    while(tru)
    {
        std::cout<< "w ktora strone chcesz isc? lewo(a) dol(s) prawo(d) gora(w) wyjdz(q), plecak(p)" << std::endl;
        std::cin >> isc;
        switch(isc)
        {
        case 'a':
            if(pozycja[1]==0)
            {
                std::cout<< "Nie tedy droga" << std::endl;
            }
            else
            {
                pozycja[1]-=1;
                pole[pozycja[0]][pozycja[1]]='<';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='-';
            }
            break;
        case 's':
            if(pozycja[0]==wielkosc_planszy2-1)
            {
                std::cout<< "Nie tedy droga" << std::endl;
            }
            else
            {
                pozycja[0]+=1;
                pole[pozycja[0]][pozycja[1]]='v';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='-';
            }
            break;
        case 'w':
            if(pozycja[0]==0)
            {
                std::cout<< "Nie tedy droga" << std::endl;
            }
            else
            {
                pozycja[0]-=1;
                pole[pozycja[0]][pozycja[1]]='^';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='-';
            }
            break;
        case 'd':
            if(pozycja[1]==wielkosc_planszy2-1)
            {
                std::cout<< "Nie tedy droga" << std::endl;
            }
            else
            {
                pozycja[1]+=1;
                pole[pozycja[0]][pozycja[1]]='>';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='-';
            }
            break;
        case 'q':
            std::cout << "koniec" << std::endl;
            tru=false;
            break;
        case 'p':
            std::cout << "ilosc pokeboli: " << plecak->getPokebol();
            std::cout << "\nilosc mikstury: " << plecak->getMikstura_leczaca();
            std::cout << "\nMoje pokemony: " << std::endl;
            plecak->pokaz_moje_pokemony();
            break;
        default:
            std::cout<< "Niewlasciwa wartosc" << std::endl;
        }
        if(pozycja[0]==wielkosc_planszy2-1 && pozycja[1]==wielkosc_planszy2-1)
        {
            if(plecak->getIlosc_pokemonow()>=5)
            {
                std::cout << "\n\nGratlacje wygrales!!!!" << std::endl;
                system("PAUSE");
                break;
            }
            else
            {
                std::cout << "\n\nPrzegrales :(" << std::endl;
                system("PAUSE");
                break;
            }
        }
        if(rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]==1)
        {
            std::cout << "\n\n    Natrafiles na pokemona ktory Cie atakuje!!" << std::endl;
            //std::cout << poke1->getNazwa() << " przeciwko " << (przeciwnik[nr_pokemona])->getNazwa() << std::endl;
            int wynik  = walka(poke1,przeciwnik[nr_pokemona++],plecak);
            if(wynik==0)
            {
                std::cout << "przegrales, koniec gry" << std::endl;
                break;
            }
            else if( wynik == 1)
            {
                rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]=0;
                std::cout << "\n";
                pole[pozycja[0]][pozycja[1]]='o';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='-';
            }
            else
            {
                std::cout << "\n";
                pole[pozycja[0]][pozycja[1]]='o';
                Wymaluj_pole(pole);
                pole[pozycja[0]][pozycja[1]]='p';
            }
            std::cout << "Znajdujesz sie na polu o" << std::endl;
        }
        else if (rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]==2)
        {
            plecak->setMikstura_leczaca(plecak->getMikstura_leczaca()+1);
            std::cout << "\n            Znalazles miksture leczaca!" << std::endl;
            system("PAUSE");
            rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]=0;
            std::cout << "\n";
            pole[pozycja[0]][pozycja[1]]='o';
            Wymaluj_pole(pole);
            pole[pozycja[0]][pozycja[1]]='-';
        }
        else if (rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]==3)
        {
            plecak->setPokebol(plecak->getPokebol()+1);
            std::cout << "\n            Znalazles pokebola!" << std::endl;
            system("PAUSE");
            rozmieszczenie_pokemonow[pozycja[0]][pozycja[1]]=0;
            std::cout << "\n";
            pole[pozycja[0]][pozycja[1]]='o';
            Wymaluj_pole(pole);
            pole[pozycja[0]][pozycja[1]]='-';
        }
    }
}

int main()
{
    std::cout << "very very simple old game pokemon revolution" << std::endl;
    std::cout << "its just a beginning of a biggest aplication\n" << std::endl;
    std::cout << "Witaj o to prosta gra w pokemony revolution" << std::endl;
    std::cout << "Przejd z punktu 'o' do punktu 'H' lapiac jak najwiecej pokemonow" << std::endl;
    game();
    std::cout << "koniec gry" << std::endl;
    system("PAUSE");
    return 1;
}
