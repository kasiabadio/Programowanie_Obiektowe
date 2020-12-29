#include <iostream>
#include <sstream>
#include <stdbool.h>
#include "Osoba.h"
#include "Adres.h"
#include "Student.h"
#include "Przedmiot.h"
#include "Pracownik.h"

void foo(Osoba &os)
{
    std::cout << "Wywolanie funkcji foo ...." << std::endl;
    std::cout << os.przedstaw() << std::endl;
}

void bar(Osoba *os)
{
    std::cout << "Wywolanie funkcji bar ...." << std::endl;
    std::cout << os->przedstaw() << std::endl;
}

int main()
{

    std::cout << "*********OSOBA*********" << std::endl;
    // OSOBA
    Osoba osoba;
    osoba.ustaw_imie_nazwisko("Kasia", "Badio");
    std::string odczytane_in = osoba.odczytaj_imie_nazwisko();
    std::cout << odczytane_in << std::endl;

    // ustawienie daty
    bool czy_ustawiona_data = osoba.ustaw_date(2020, 2, 12);
    if (czy_ustawiona_data == true)
    {
        std::cout << osoba.odczytaj_date() << std::endl;
    }
    else
    {
        std::cout << "Data nie zostala ustawiona." << std::endl;
    }
    czy_ustawiona_data = osoba.ustaw_date(8181, 2, 12);
    if (czy_ustawiona_data == true)
    {
        std::cout << osoba.odczytaj_date() << std::endl;
    }
    else
    {
        std::cout << "Data nie zostala ustawiona." << std::endl;
    }

    // ustawienie adresu
    bool czy_ustawiony_adres = osoba.ustaw_adres("Bandycka", 48, 9);
    if (czy_ustawiony_adres == true)
    {
        std::cout << osoba.odczytaj_adres() << std::endl;
    }
    else
    {
        std::cout << "Adres nie został ustawiony" << std::endl;
    }

    czy_ustawiony_adres = osoba.ustaw_adres("Szosowa", -1, 9);
    if (czy_ustawiony_adres == true)
    {
        std::cout << osoba.odczytaj_adres() << std::endl;
    }
    else
    {
        std::cout << "Adres nie zostal ustawiony." << std::endl;
    }
    // przedstawienie osoby
    std::cout << std::endl
              << osoba.przedstaw() << std::endl;
    // podanie obiektu do funkcji
    foo(osoba);
    Osoba *wskaznik_na_osobe = &osoba;
    bar(wskaznik_na_osobe);

    std::cout << "*********STUDENT*********" << std::endl;
    // STUDENT
    Student student;
    // ustawienie danych studenta jako osoby
    student.ustaw_imie_nazwisko("Jan", "Niezbedny");
    student.ustaw_adres("Malinowskiego", 2, 9);
    student.ustaw_date(2012, 12, 5);

    // dodanie przedmiotów których uczy się student
    Przedmiot przyroda;
    przyroda.nazwa_przedmiotu = "Przyroda";
    student.dodaj_przedmiot(przyroda);
    for (int e = 1; e < 6; e++)
    {
        student.dodaj_ocene_z_przedmiotu("Przyroda", e);
    }
    std::string oceny = student.odczytaj_oceny_z_przedmiotu(przyroda);
    //std::cout << oceny << std::endl;

    Przedmiot matma;
    matma.nazwa_przedmiotu = "Matma";
    student.dodaj_przedmiot(matma);
    for (int j = 5; j > 0; j--)
    {
        student.dodaj_ocene_z_przedmiotu("Matma", j);
    }
    std::string oceny1 = student.odczytaj_oceny_z_przedmiotu(matma);
    //std::cout << oceny1 << std::endl;

    // odczytanie ocen ze wszystkich przedmiotów
    std::string wszystkie_oceny = student.odczytaj_oceny();
    std::cout << wszystkie_oceny << std::endl;
    // przedstawienie studenta
    std::cout << std::endl
              << student.przedstaw() << std::endl;
    foo(student);
    Osoba *wskaznik_na_studenta = &student;
    bar(wskaznik_na_studenta);

    std::cout << "*********PRACOWNIK*********" << std::endl;
    // PRACOWNIK
    Pracownik pracownik;
    // ustawienie danych pracownika jako osoby
    pracownik.ustaw_imie_nazwisko("Lech", "Moryksiewicz");
    pracownik.ustaw_adres("Piatkowska", 33, 7);
    pracownik.ustaw_date(1974, 8, 1);

    // dodanie przedmiotów które prowadzi pracownik
    pracownik.dodaj_przedmiot("Historia");
    pracownik.dodaj_przedmiot("WOS");
    pracownik.dodaj_przedmiot("Matma");
    bool czy_prowadzi_matme = pracownik.sprawdz_czy_prowadzi_przedmiot("Matma");
    if (czy_prowadzi_matme)
    {
        pracownik.usun_przedmiot("Matma");
    }
    std::cout << std::endl
              << pracownik.przedstaw() << std::endl;
    foo(pracownik);
    Osoba *wskaznik_na_pracownika = &pracownik;
    bar(wskaznik_na_pracownika);

    /*
    punkt 12
    przy braku słowa virtual funkcja przedstaw() powoduje wywołanie
    metody przedstaw() z klasy bazowej z której dziedziczą klasy Student i Pracownik

    punkt 14
    po dodaniu słowa virtual metoda przedstaw() jest wywoływana w wersji odpowiadającej 
    rzeczywistemu typowi
    */

    /*punkt 15*/
    Pracownik *p1 = new Pracownik;
    Osoba *o1 = static_cast<Osoba *>(p1); // poprawne, niepotrzebne
    Osoba *o2 = static_cast<Pracownik *>(o1); // poprawne, niepotrzebne
    Osoba *o10 = o1;
    Osoba *o20 = o1;

    Osoba *o3 = new Osoba;
    Pracownik *p2 = static_cast<Pracownik *>(o3); 

    /*punkt 16*/
    Pracownik *p3 = new Pracownik;
    Osoba *o4 = dynamic_cast<Osoba *>(p3); 
    //Pracownik *p4 = dynamic_cast<Osoba *>(o4); 

    /*punkt 17*/
    Osoba *o5 = new Osoba;
    Pracownik *p5 = dynamic_cast<Pracownik *>(o5); // p5 to nullptr, niepoprawne 
    if (p5 == nullptr) 
        std::cout << "Blad rzutowania!" << std::endl;
    else
        p5->odczytaj_prowadzone_przedmioty();


    /*punkt 18, 19
    po zamianie definicji funkcji przedstaw nie da się skompilować projektu
    */

   
    return 0;
}