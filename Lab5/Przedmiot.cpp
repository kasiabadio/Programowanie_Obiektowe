#include "Przedmiot.h"
#include <sstream>

bool Przedmiot::dodaj_ocene(int _ocena)
{
    if(_ocena > 5 || _ocena < 1){
        return false;
    }
    oceny_z_przedmiotu.push_back(_ocena);
    return true;
}


bool Przedmiot::sprawdz_czy_ma_ocene() const
{
    if(!oceny_z_przedmiotu.empty()){
        return true;
    }
    return false;
}

