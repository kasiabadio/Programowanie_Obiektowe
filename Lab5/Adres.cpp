#include "Adres.h"
#include <string>

bool Adres::ustaw_adres(std::string _ulica, int _nr_domu, int _nr_mieszkania)
{
    if(_ulica.empty() || _nr_domu <= 0 || _nr_mieszkania < 0){
        return false;
    }
    ulica = _ulica;
    nr_domu = _nr_domu;
    nr_mieszkania = _nr_mieszkania;
    
    return true;
}


std::string Adres::odczytaj_adres() const
{
    return ulica + " " + std::to_string(nr_domu) + " m." + std::to_string(nr_mieszkania);
}
