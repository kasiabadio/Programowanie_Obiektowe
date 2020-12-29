#ifndef SAMOCHOD_H_
#define SAMOCHOD_H_
#include <string>
#include <stdbool.h>

class Samochod{
public:
    Samochod();
    Samochod(float _pojemnosc_baku, std::string _model);
    void napelnij_bak(float _paliwo);
    float odczytaj_poziom_paliwa() const;
    float odczytaj_pojemnosc_baku() const;
    void dodaj_przejechane_kilometry(unsigned int _liczba_kilometrow);
    unsigned int odczytaj_przejechane_kilometry() const;
    void zmien_model_samochodu(std::string _model);
    std::string odczytaj_model_samochodu() const;
    operator bool() const;
    bool operator!() const;
    // używając friend, klasa ma dostęp do zmiennych prywatnych klasy Samochod
    friend std::ostream& operator<<(std::ostream &os, const Samochod &samochod);
    bool operator<(const Samochod &samochod) const;
    void operator++();


private:
    float pojemnosc_baku;
    float poziom_paliwa;
    unsigned int liczba_kilometrow;
    std::string model;

};

#endif // SAMOCHOD_H_