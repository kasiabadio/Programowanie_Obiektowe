#include "Ul.h"

Ul::Ul() : liczba_pszczol{nullptr},
           x{nullptr},
           y{nullptr},
           ilosc_miodu{nullptr},
           nazwa_pasieki{nullptr},
           imie_wlasciciela{nullptr},
           nazwisko_wlasciciela{nullptr}
{
}

Ul::Ul(int _startowa_liczba_pszczol) : Ul()
{
    liczba_pszczol = new int;
    *liczba_pszczol = _startowa_liczba_pszczol;
    x = new int;
    *x = 0;
    y = new int;
    *y = 0;
    ilosc_miodu = new float;
    *ilosc_miodu = 0.00;
    nazwa_pasieki = new std::string;
    *nazwa_pasieki = "Pasieka pod klonem";
    imie_wlasciciela = new std::string;
    *imie_wlasciciela = "Kasia";
    nazwisko_wlasciciela = new std::string;
    *nazwisko_wlasciciela = "Badio";
}

Ul::Ul(const Ul &ul) : Ul()
{
    liczba_pszczol = new int;
    *liczba_pszczol = *ul.liczba_pszczol;
    x = new int;
    *x = *ul.x;
    y = new int;
    *y = *ul.y;
    ilosc_miodu = new float;
    *ilosc_miodu = *ul.ilosc_miodu;
    nazwa_pasieki = new std::string;
    *nazwa_pasieki = *ul.nazwa_pasieki;
    imie_wlasciciela = new std::string;
    *imie_wlasciciela = *ul.imie_wlasciciela;
    nazwisko_wlasciciela = new std::string;
    *nazwisko_wlasciciela = *ul.nazwisko_wlasciciela;
}

Ul::Ul(const Ul &&ul)
{
    liczba_pszczol = std::move(ul.liczba_pszczol);
    x = std::move(ul.x);
    y = std::move(ul.y);
    ilosc_miodu = std::move(ul.ilosc_miodu);
    nazwa_pasieki = std::move(ul.nazwa_pasieki);
    imie_wlasciciela = std::move(ul.imie_wlasciciela);
    nazwisko_wlasciciela = std::move(ul.nazwisko_wlasciciela);
}

bool Ul::zmiana_liczby_pszczol(int _liczba)
{
    if (_liczba >= -100 && _liczba <= 100 && *(this->liczba_pszczol) + _liczba >= 0)
    {
        *liczba_pszczol += _liczba;
        return true;
    }
    return false;
}

int Ul::odczytaj_liczbe_pszczol() const
{
    return *liczba_pszczol;
}

void Ul::ustaw_koordynaty(int _x, int _y)
{
    *x = _x;
    *y = _y;
}

std::vector<int> Ul::odczytaj_koordynaty() const
{
    std::vector<int> temp;
    temp.emplace_back(*x);
    temp.emplace_back(*y);
    return temp;
}

void Ul::zaktualizuj_miod(float _ilosc_miodu)
{
    *ilosc_miodu += _ilosc_miodu;
}

float Ul::odczytaj_miod() const
{
    return *ilosc_miodu;
}

bool Ul::okresl_nazwe_pasieki(std::string _nazwa_pasieki)
{
    char c = _nazwa_pasieki[0];
    if (isupper(c))
    {
        *nazwa_pasieki = _nazwa_pasieki;
        return true;
    }
    return false;
}

std::string Ul::odczytaj_nazwe_pasieki() const
{
    return *nazwa_pasieki;
}

void Ul::zaktualizuj_wlasciciela(std::string _imie, std::string _nazwisko)
{
    *imie_wlasciciela = _imie;
    *nazwisko_wlasciciela = _nazwisko;
}

std::string Ul::odczytaj_imie_wlasciciela() const
{
    return *imie_wlasciciela;
}

std::string Ul::odczytaj_nazwisko_wlasciciela() const
{
    return *nazwisko_wlasciciela;
}

Ul::~Ul()
{
    delete this->liczba_pszczol;
    delete this->x;
    delete this->y;
    delete this->ilosc_miodu;
    delete this->nazwa_pasieki;
    delete this->imie_wlasciciela;
    delete this->nazwisko_wlasciciela;
}
