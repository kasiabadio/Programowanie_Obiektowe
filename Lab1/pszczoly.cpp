#include "pszczoly.h"

Ul::Ul(int _startowa_liczba_pszczol):
    liczba_pszczol{_startowa_liczba_pszczol},
    ilosc_miodu{0},
    imie_wlasciciela{"Katarzyna"},
    nazwisko_wlasciciela{"Badio"}
{}

bool Ul::zmiana_liczby_pszczol(int _liczba){
    if(_liczba >= -100 && _liczba <= 100 && this->liczba_pszczol + _liczba >= 0){
        this->liczba_pszczol += _liczba;
        return true;
    }
    return false;
}

int Ul::odczytaj_liczbe_pszczol(){
    return this->liczba_pszczol;
}

void Ul::ustaw_koordynaty(int _x, int _y){
    this->x = _x;
    this->y = _y;
}

std::vector<int> Ul::odczytaj_koordynaty(){
    std::vector<int> temp;
    temp.emplace_back(this->x);
    temp.emplace_back(this->y);
    return temp;
}

void Ul::zaktualizuj_miod(float _ilosc_miodu){
    this->ilosc_miodu += _ilosc_miodu;
}

float Ul::odczytaj_miod(){
    return this->ilosc_miodu;
}

bool Ul::okresl_nazwe_pasieki(std::string _nazwa_pasieki){
    char c = _nazwa_pasieki[0];
    if(isupper(c)){
        this->nazwa = _nazwa_pasieki;
        return true;
    }
    return false;
}

std::string Ul::odczytaj_nazwe_pasieki(){
    return this->nazwa;
}

void Ul::zaktualizuj_wlasciciela(std::string _imie, std::string _nazwisko){
    this->imie_wlasciciela = _imie;
    this->nazwisko_wlasciciela = _nazwisko;
}

std::string Ul::odczytaj_imie_wlasciciela(){
    return this->imie_wlasciciela;
}

std::string Ul::odczytaj_nazwisko_wlasciciela(){
    return this->nazwisko_wlasciciela;
}