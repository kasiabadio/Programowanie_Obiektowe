#ifndef PRZEDMIOT_H_
#define PRZEDMIOT_H_
#include <string>
#include <vector>

class Przedmiot
{
public:
    std::string nazwa_przedmiotu;
    std::vector<int> oceny_z_przedmiotu;
    bool dodaj_ocene(int _ocena);
    bool sprawdz_czy_ma_ocene() const;

};


#endif // PRZEDMIOT_H_