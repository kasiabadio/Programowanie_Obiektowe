#include "samochod.h"
#include <string>
#include <stdbool.h>

Samochod::Samochod():
    pojemnosc_baku{100.0}
{
    poziom_paliwa = 10.0;
    liczba_kilometrow = 100;
    model = "";
};

Samochod::Samochod(float _pojemnosc_baku, std::string _model):
    pojemnosc_baku{_pojemnosc_baku},
    model{_model}
{
    poziom_paliwa = 10.0;
    liczba_kilometrow = 100;
}

void Samochod::napelnij_bak(float _paliwo){
    poziom_paliwa += _paliwo;
}

float Samochod::odczytaj_poziom_paliwa() const{
    return poziom_paliwa;
}

float Samochod::odczytaj_pojemnosc_baku() const{
    return pojemnosc_baku;
}

void Samochod::dodaj_przejechane_kilometry(unsigned int _liczba_kilometrow){
    liczba_kilometrow += _liczba_kilometrow;
}

unsigned int Samochod::odczytaj_przejechane_kilometry() const{
    return liczba_kilometrow;
}

void Samochod::zmien_model_samochodu(std::string _model){
    model = _model;
}

std::string Samochod::odczytaj_model_samochodu() const{
    return model;
}

Samochod::operator bool() const{
    return !model.empty();
}


bool Samochod::operator!() const{
    return odczytaj_pojemnosc_baku() > 0;
}

// słowa const użyto za funkcją, dzięki czemu nic sie nie pozmienia (model samochodu)
// gdy będziemy zwracać jakąś wartość
// tutaj można tylko czytać wartości z klasy, ale nie modyfikować je
bool Samochod::operator<(const Samochod &samochod) const{
    return this->model < samochod.model;
}


void Samochod::operator++(){
    this->poziom_paliwa += 10;
}

