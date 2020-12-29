#ifndef PRACOWNIK_H_
#define PRACOWNIK_H_
#include <string>
#include <vector>
#include "Osoba.h"
#include "Przedmiot.h"
class Pracownik : public Osoba
{
public:
    bool dodaj_przedmiot(std::string _przedmiot);
    bool usun_przedmiot(std::string _przedmiot);
    bool sprawdz_czy_prowadzi_przedmiot(std::string _przedmiot);
    std::string odczytaj_prowadzone_przedmioty();
    std::string przedstaw();

private:
    std::vector<std::string> przedmioty;
};

#endif // PRACOWNIK_H_