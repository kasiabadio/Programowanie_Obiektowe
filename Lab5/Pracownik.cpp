#include "Pracownik.h"
#include <sstream>
#include <iostream>
#include <iterator>

bool Pracownik::dodaj_przedmiot(std::string _przedmiot)
{
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == _przedmiot)
        {
            return false;
        }
    }
    przedmioty.push_back(_przedmiot);
    return true;
}

bool Pracownik::usun_przedmiot(std::string _przedmiot)
{
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == _przedmiot)
        {
            przedmioty.erase(przedmioty.begin() + i);
            return true;
        }
    }
    return false;
}

bool Pracownik::sprawdz_czy_prowadzi_przedmiot(std::string _przedmiot)
{
    for (int i = 0; i < przedmioty.size(); i++)
    {
        if (przedmioty[i] == _przedmiot)
        {
            return true;
        }
    }
    return false;
}

std::string Pracownik::odczytaj_prowadzone_przedmioty()
{
    std::string temp = "";

    for (int i = 0; i < przedmioty.size(); i++)
    {
        temp += przedmioty[i] + " ";
    }
    return temp;
}

std::string Pracownik::przedstaw()
{
    return "Imie, nazwisko: " + odczytaj_imie() + " " + odczytaj_nazwisko() + "\n" +
           "Data urodzenia: " + odczytaj_date() + "\n" +
           "Adres: " + odczytaj_adres() + "\n" +
           "Prowadzone przedmioty: " + "\n" + odczytaj_prowadzone_przedmioty() + "\n";
}
