#include "Ul.h"
#include "Stopper.h"
// konstruktor domyślny inicjalizujący wszystkie wskaźniki
// z użyciem listy inicjalizacyjnej
Ul::Ul() : liczba_pszczol{nullptr},
           x{nullptr},
           y{nullptr},
           ilosc_miodu{nullptr},
           nazwa_pasieki{nullptr},
           imie_wlasciciela{nullptr},
           nazwisko_wlasciciela{nullptr}
{
    liczba_pszczol = new int;
    x = new int;
    y = new int;
    ilosc_miodu = new float;
    nazwa_pasieki = new std::string;
    imie_wlasciciela = new std::string;
    nazwisko_wlasciciela = new std::string;
    reset_time_stopper();
}

// konstruktor zdolny do konwertowania obiektów typu jednego z pól
// klasy na obiekt implementowanej klasy
Ul::Ul(int _startowa_liczba_pszczol) : Ul()
{
    reset_time_stopper();
    *liczba_pszczol = _startowa_liczba_pszczol;
    *x = 0;
    *y = 0;
    *ilosc_miodu = 0.00;
    *nazwa_pasieki = "Pasieka pod klonem";
    *imie_wlasciciela = "Kasia";
    *nazwisko_wlasciciela = "Badio";
}

// konstruktor kopiujący dokonujący głębokiej kopii
Ul::Ul(const Ul &ul) : Ul()
{
    reset_time_stopper();
    *liczba_pszczol = *ul.liczba_pszczol;
    *x = *ul.x;
    *y = *ul.y;
    *ilosc_miodu = *ul.ilosc_miodu;
    *nazwa_pasieki = *ul.nazwa_pasieki;
    *imie_wlasciciela = *ul.imie_wlasciciela;
    *nazwisko_wlasciciela = *ul.nazwisko_wlasciciela;
}

// konstruktor przenoszący
Ul::Ul(Ul &&ul) : liczba_pszczol(std::move(ul.liczba_pszczol)),
                  x(std::move(ul.x)),
                  y(std::move(ul.y)),
                  ilosc_miodu(std::move(ul.ilosc_miodu)),
                  nazwa_pasieki(std::move(ul.nazwa_pasieki)),
                  imie_wlasciciela(std::move(ul.imie_wlasciciela)),
                  nazwisko_wlasciciela(std::move(ul.nazwisko_wlasciciela))
{
    reset_time_stopper();
    ul.liczba_pszczol = nullptr;
    ul.x = nullptr;
    ul.y = nullptr;
    ul.ilosc_miodu = nullptr;
    ul.nazwa_pasieki = nullptr;
    ul.imie_wlasciciela = nullptr;
    ul.nazwisko_wlasciciela = nullptr;
}

bool Ul::zmiana_liczby_pszczol(int _liczba)
{
    start_time_stopper();
    this->log("zmiana_liczby_pszczol");
    if (_liczba >= -100 && _liczba <= 100 && *(this->liczba_pszczol) + _liczba >= 0)
    {
        *liczba_pszczol += _liczba;
        stop_time_stopper();
        return true;
    }
    stop_time_stopper();
    return false;
}

int Ul::odczytaj_liczbe_pszczol() const
{
    return *liczba_pszczol;
}

void Ul::ustaw_koordynaty(int _x, int _y)
{
    start_time_stopper();
    this->log("ustaw_koordynaty");
    *x = _x;
    *y = _y;
    stop_time_stopper();
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
    start_time_stopper();
    this->log("zaktualizuj_miod");
    *ilosc_miodu += _ilosc_miodu;
    stop_time_stopper();
}

float Ul::odczytaj_miod() const
{
    return *ilosc_miodu;
}

bool Ul::okresl_nazwe_pasieki(std::string _nazwa_pasieki)
{
    start_time_stopper();
    this->log("okresl_nazwe_pasieki");
    char c = _nazwa_pasieki[0];
    if (isupper(c))
    {
        *nazwa_pasieki = _nazwa_pasieki;
        stop_time_stopper();
        return true;
    }
    stop_time_stopper();
    return false;
}

std::string Ul::odczytaj_nazwe_pasieki() const
{
    return *nazwa_pasieki;
}

void Ul::zaktualizuj_wlasciciela(std::string _imie, std::string _nazwisko)
{
    start_time_stopper();
    this->log("zaktualizuj_wlasciciela");
    *imie_wlasciciela = _imie;
    *nazwisko_wlasciciela = _nazwisko;
    stop_time_stopper();
}

std::string Ul::odczytaj_imie_wlasciciela() const
{
    return *imie_wlasciciela;
}

std::string Ul::odczytaj_nazwisko_wlasciciela() const
{
    return *nazwisko_wlasciciela;
}

// destruktor
Ul::~Ul()
{

    delete this->liczba_pszczol;
    delete this->x;
    delete this->y;
    delete this->ilosc_miodu;
    delete this->nazwa_pasieki;
    delete this->imie_wlasciciela;
    delete this->nazwisko_wlasciciela;

    std::cout << "Usunieto obiekt" << std::endl;
}
