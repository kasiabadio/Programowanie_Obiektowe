#ifndef UL_H_
#define UL_H_
#include "Logger.h"
#include <string>
#include <iostream>
#include <vector>

class Ul: Logger{
public:
    Ul();
    Ul(int _startowa_liczba_pszczol);
    Ul(const Ul &ul);
    Ul(Ul &&ul);
    bool zmiana_liczby_pszczol(int _liczba);
    int odczytaj_liczbe_pszczol() const;
    void zaktualizuj_miod(float _ilosc_miodu);
    float odczytaj_miod() const;
    void ustaw_koordynaty(int _x, int _y);
    std::vector<int> odczytaj_koordynaty() const;
    bool okresl_nazwe_pasieki(std::string _nazwa_pasieki);
    std::string odczytaj_nazwe_pasieki() const;
    void zaktualizuj_wlasciciela(std::string _imie, std::string _nazwisko);
    std::string odczytaj_imie_wlasciciela() const;
    std::string odczytaj_nazwisko_wlasciciela() const;

    ~Ul();

protected:
    int *liczba_pszczol;
    int *x;
    int *y;
    float *ilosc_miodu;
    std::string *nazwa_pasieki;
    std::string *imie_wlasciciela;
    std::string *nazwisko_wlasciciela;
};

#endif //UL_H_
