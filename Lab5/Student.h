#ifndef STUDENT_H_
#define STUDENT_H_
#include <string>
#include <vector>
#include "Osoba.h"
#include "Przedmiot.h"

class Student : public Osoba
{
public:
    bool dodaj_ocene_z_przedmiotu(std::string _przedmiot, int _ocena);
    bool dodaj_przedmiot(Przedmiot przedmiot);
    std::string odczytaj_oceny_z_przedmiotu(Przedmiot przedmiot);
    std::string odczytaj_oceny();
    std::string przedstaw();

private:
    std::vector<Przedmiot> przedmioty_oceny;
};

#endif // STUDENT_H_