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

    int zmienna = 999;
    funkcja_konw(999);
    std::cout << std::endl;

    Ul_struktura ul2;
    ul2.ilosc_miodu = new float;
    *ul2.ilosc_miodu = 6.66;
    ul2.x = new int;
    *ul2.x = 4;
    ul2.y = new int;
    *ul2.y = 6;
    ul2.liczba_pszczol = new int;
    *ul2.liczba_pszczol = 45;
    ul2.nazwa_pasieki = new std::string;
    *ul2.nazwa_pasieki = "Pasieka miododajna";
    ul2.imie_wlasciciela = new std::string;
    *ul2.imie_wlasciciela = "Hanka";
    ul2.nazwisko_wlasciciela = new std::string;
    *ul2.nazwisko_wlasciciela = "Mostowiak";
    std::cout << *ul2.ilosc_miodu << std::endl;
    std::cout << *ul2.x << std::endl;
    std::cout << *ul2.y << std::endl;
    std::cout << *ul2.liczba_pszczol << std::endl;
    std::cout << *ul2.nazwa_pasieki << std::endl;
    std::cout << *ul2.imie_wlasciciela << std::endl;
    std::cout << *ul2.nazwisko_wlasciciela << std::endl;
    std::cout << std::endl;

    Ul ul3(100);

    //const lvalue referencja moze przyjac zarowno lwartosci jak i rwartosci: przyjmuje ul3 jak i 3000
    funkcja_lvalue(ul3);
    funkcja_lvalue(3000);

    //lvalue zwykla referencja moze przyjac tylko lwartosci: przyjmuje ul3, a 3000 nie przyjmuje
    funkcja_zwykla_lvalue(ul3);
    //funkcja_zwykla_lvalue(3000);

    //rvalue moze przyjac tylko rwartosci: przyjmuje 5000, a nie przyjmuje ul3
    funkcja_rvalue(5000);
    //funkcja_rvalue(ul3);

    return 0;
}