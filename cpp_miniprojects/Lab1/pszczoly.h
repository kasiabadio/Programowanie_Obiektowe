#ifndef PSZCZOLY_H_
#define PSZCZOLY_H_
#include <string>
#include <vector>

class Ul
{
public:
    Ul(int _startowa_liczba_pszczol);
    bool zmiana_liczby_pszczol(int _liczba);
    int odczytaj_liczbe_pszczol();
    void ustaw_koordynaty(int _x, int _y);
    std::vector<int> odczytaj_koordynaty();
    void zaktualizuj_miod(float _ilosc_miodu);
    float odczytaj_miod();
    bool okresl_nazwe_pasieki(std::string _nazwa_pasieki);
    std::string odczytaj_nazwe_pasieki();
    void zaktualizuj_wlasciciela(std::string _imie, std::string _nazwisko);
    std::string odczytaj_imie_wlasciciela();
    std::string odczytaj_nazwisko_wlasciciela();

protected:
    int liczba_pszczol;
    int x;
    int y;
    float ilosc_miodu;
    std::string nazwa;
    std::string imie_wlasciciela;
    std::string nazwisko_wlasciciela;
};

#endif //PSZCZOLY_H_