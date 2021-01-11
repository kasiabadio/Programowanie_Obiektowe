#include "Student.h"
#include <sstream>
#include <iostream>
#include <iterator>

// konstruktor domyślny
Student::Student()
{}

// konstruktor kopiujący
Student::Student(const Student &student): Osoba(student)
{
    przedmioty_oceny = student.przedmioty_oceny;
    
}

// konstruktor przenoszący
Student::Student(Student &&student) : Osoba(std::move(student))
{
    
    przedmioty_oceny = std::move(student.przedmioty_oceny);
}


bool Student::dodaj_ocene_z_przedmiotu(std::string _przedmiot, int _ocena)
{
    for (int i = 0; i < przedmioty_oceny.size(); i++)
    {
        bool czy_ocena_sie_dodala;
        if (przedmioty_oceny[i].nazwa_przedmiotu == _przedmiot)
        {
            czy_ocena_sie_dodala = przedmioty_oceny[i].dodaj_ocene(_ocena);
            return true;
        }
    }
    return false;
}

bool Student::dodaj_przedmiot(Przedmiot przedmiot)
{
    for (int i = 0; i < przedmioty_oceny.size(); i++)
    {
        if (przedmioty_oceny[i].nazwa_przedmiotu == przedmiot.nazwa_przedmiotu)
        {
            return false;
        }
    }
    przedmioty_oceny.push_back(przedmiot);
    return true;
}

std::string Student::odczytaj_oceny_z_przedmiotu(Przedmiot przedmiot)
{
    std::string temp1 = "";
    for (int j = 0; j < przedmioty_oceny.size(); j++)
    {
        if (przedmioty_oceny[j].nazwa_przedmiotu == przedmiot.nazwa_przedmiotu)
        {
            for (int k = 0; k < przedmioty_oceny[j].oceny_z_przedmiotu.size(); k++)
            {
                temp1 += std::to_string(przedmioty_oceny[j].oceny_z_przedmiotu[k]) + " ";
            }

            return temp1;
        }
    }

    return "";
}

std::string Student::odczytaj_oceny()
{
    std::string temp1 = "";
    for (int j = 0; j < przedmioty_oceny.size(); j++)
    {
        temp1 += przedmioty_oceny[j].nazwa_przedmiotu + ": ";
        for (int k = 0; k < przedmioty_oceny[j].oceny_z_przedmiotu.size(); k++)
        {
            temp1 += std::to_string(przedmioty_oceny[j].oceny_z_przedmiotu[k]) + " ";
        }
        temp1 += "\n";
    }
    return temp1;
}

std::string Student::przedstaw()
{
    return "Imie, nazwisko: " + odczytaj_imie() + " " + odczytaj_nazwisko() + "\n" +
           "Data urodzenia: " + odczytaj_date() + "\n" +
           "Adres: " + odczytaj_adres() + "\n" +
           "Oceny: " + "\n" + odczytaj_oceny();
}