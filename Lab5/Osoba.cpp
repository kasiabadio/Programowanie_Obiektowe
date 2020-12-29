#include "Osoba.h"
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

Osoba::Osoba()
{}

void Osoba::ustaw_imie_nazwisko(std::string _imie, std::string _nazwisko)
{
    imie = _imie;
    nazwisko = _nazwisko;
}

std::string Osoba::odczytaj_imie_nazwisko() const
{
    return imie + " " + nazwisko;
}

bool Osoba::ustaw_date(int _rok, int _miesiac, int _dzien)
{
    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);
    if ((_rok < 1850) || (_miesiac < 1) || (_dzien < 1))
    {
        return false;
    }
    if ((_rok <= now->tm_year + 1900) && (_miesiac <= now->tm_mon + 1) && (_dzien <= now->tm_mday))
    {
        data = std::to_string(_rok) + ":" + std::to_string(_miesiac) + ":" + std::to_string(_dzien);
        return true;
    }
    return false;
}

std::string Osoba::przedstaw()
{
    return "Imie, nazwisko: " + imie + " " + nazwisko + "\n" +
           "Data urodzenia: " + data + "\n" +
           "Adres: " + this->odczytaj_adres() + "\n";
}

std::string Osoba::odczytaj_imie() const
{
    return imie;
}

std::string Osoba::odczytaj_nazwisko() const
{
    return nazwisko;
}

std::string Osoba::odczytaj_date() const
{
    return data;
}