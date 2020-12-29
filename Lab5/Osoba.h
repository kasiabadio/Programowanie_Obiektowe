#ifndef OSOBA_H_
#define OSOBA_H_
#include <string>
#include "Adres.h"

class Osoba: public Adres
{
public:
    Osoba();
    void ustaw_imie_nazwisko(std::string _imie, std::string _nazwisko);
    std::string odczytaj_imie_nazwisko() const;
    bool ustaw_date(int _rok, int _miesiac, int _dzien);
    virtual std::string przedstaw();
    //virtual void przedstaw() = 0;
    std::string odczytaj_imie() const;
    std::string odczytaj_nazwisko() const;
    std::string odczytaj_date() const;

private:
    std::string imie;
    std::string nazwisko;
    std::string data; // format: 2020-12-22
    
};


#endif // OSOBA_H_