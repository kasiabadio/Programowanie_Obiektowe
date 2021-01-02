#include "Ul.h"
#include "Logger.h"
#include <string>
#include <iostream>
#include <typeinfo>

void funkcja_konw(Ul ul)
{
    std::cout << "Liczba pszczol w f. konwertujacej: " << ul.odczytaj_liczbe_pszczol() << std::endl;
    std::cout << "Nazwa pasieki w f. konwertujacej: " << ul.odczytaj_nazwe_pasieki() << std::endl;
    std::cout << "Imie wlasciciela w f. konwertujacej: " << ul.odczytaj_imie_wlasciciela() << std::endl;
}

void funkcja_lvalue(const Ul &ul)
{
    std::cout << "To jest funkcja lvalue. " << std::endl;
    std::cout << ul.odczytaj_liczbe_pszczol() << std::endl;
    //po probie wywolania powyzszej funkcji (gdy nie miała const' a na koncu) pojawia sie informacja:
    //obiekt ma kwalifikatory typu niezgodne ze składową funkcja
    //"Ul::odczytaj_liczbe_pszczol" -- typ obiektu to: const Ul

    //gdy odczytaj_liczbe_pszczol() jest const, to wtedy mozna tutaj jej uzyc
}

void funkcja_zwykla_lvalue(Ul &ul)
{
    std::cout << "To jest zwykla funkcja lvalue. " << std::endl;
    std::cout << ul.odczytaj_liczbe_pszczol() << std::endl;
}

void funkcja_rvalue(Ul &&ul)
{
    std::cout << "To jest funkcja rvalue. " << std::endl;
    std::cout << ul.odczytaj_liczbe_pszczol() << std::endl;
}

struct Ul_struktura
{
    int *liczba_pszczol;
    int *x;
    int *y;
    float *ilosc_miodu;
    std::string *nazwa_pasieki;
    std::string *imie_wlasciciela;
    std::string *nazwisko_wlasciciela;
};

int main()
{

    Ul ul1(123);

    int lp = ul1.odczytaj_liczbe_pszczol();
    std::cout << "Liczba pszczol: " << lp << std::endl;
    if (ul1.zmiana_liczby_pszczol(-6))
    {
        lp = ul1.odczytaj_liczbe_pszczol();
        std::cout << "Liczba pszczol: " << lp << std::endl;
    }
    else
    {
        std::cout << "Error!" << std::endl;
    }

    /*
    Ul ul2(ul1);
    ul1.zaktualizuj_miod(11);
    float miod = ul1.odczytaj_miod();
    std::cout << "Miod ul1: " << miod << std::endl;
    miod = ul2.odczytaj_miod();
    std::cout << "Miod ul2: " << miod << std::endl;
    ul2.zaktualizuj_miod(14);
    miod = ul1.odczytaj_miod();
    std::cout << "Miod ul1: " << miod << std::endl;
    miod = ul2.odczytaj_miod();
    std::cout << "Miod ul2: " << miod << std::endl;
    */

    ul1.ustaw_koordynaty(2, 3);
    std::vector<int> koordynaty = ul1.odczytaj_koordynaty();
    std::cout << "Koordynaty: x: " << koordynaty[0] << " y: " << koordynaty[1] << std::endl;

    std::string nazwa_pasieki = ul1.odczytaj_nazwe_pasieki();
    std::cout << nazwa_pasieki << std::endl;

    if (ul1.okresl_nazwe_pasieki("Pasieka pod milorzebem"))
    {
        nazwa_pasieki = ul1.odczytaj_nazwe_pasieki();
        std::cout << nazwa_pasieki << std::endl;
    }

    std::string imie = ul1.odczytaj_imie_wlasciciela();
    std::string nazwisko = ul1.odczytaj_nazwisko_wlasciciela();
    std::cout << "Imie: " << imie << " Nazwisko: " << nazwisko << std::endl;
    ul1.zaktualizuj_wlasciciela("Aleksandra", "Badio");
    imie = ul1.odczytaj_imie_wlasciciela();
    nazwisko = ul1.odczytaj_nazwisko_wlasciciela();
    std::cout << "Imie: " << imie << " Nazwisko: " << nazwisko << std::endl;
    std::cout << std::endl;

    // punkt 15 - wywołany zostaje konstruktor kopiujący
    std::cout << "*Wywolanie konstruktora kopiujacego*" << std::endl;
    funkcja_konw(ul1);

    // punkt 16 - wywołany zostaje konstruktor przenoszący
    std::cout << "*Wywolanie konstruktora przenoszacego*" << std::endl;
    funkcja_konw(std::move(ul1));

    // punkt 17 - wywołany zostaje konstruktor zdolny 
    // do konwertowania obiektów typu jednego z pól klasy na obiekt implementowanej klasy
    std::cout << "*Wywolanie konstruktora konwertujacego*" << std::endl;
    funkcja_konw(999);
    std::cout << std::endl;

    
    Ul ul3(100);

    //const lvalue referencja moze przyjac zarowno lwartosci jak i rwartosci: przyjmuje ul3, std::move(ul3) jak i 3000
    std::cout << "*funkcja_lvalue*" << std::endl;
    funkcja_lvalue(ul3);
    funkcja_lvalue(std::move(ul3));
    funkcja_lvalue(3000);
    
    //lvalue zwykla referencja moze przyjac tylko lwartosci: przyjmuje ul3, a std::move(ul3) i 3000 nie przyjmuje
    std::cout << "*funkcja_zwykla_lvalue*" << std::endl;
    funkcja_zwykla_lvalue(ul3);
    //funkcja_zwykla_lvalue(std::move(ul3));
    //funkcja_zwykla_lvalue(3000);

    //rvalue moze przyjac tylko rwartosci: przyjmuje 5000 i std::move(ul3), a nie przyjmuje ul3
    std::cout << "*funkcja_rvalue*" << std::endl;
    //funkcja_rvalue(ul3);
    funkcja_rvalue(std::move(ul3));
    funkcja_rvalue(5000);
    
    // punkt 25 - nie da się wywołać metody log obiektu implementowanej klasy,
    // ponieważ poprzez napisanie "class Ul: Logger" wszyscy członkowie klasy
    // Logger stają się prywatni w klasie która dziedziczy po klasie Logger
    //ul3.log("Hello world!");

    return 0;
}