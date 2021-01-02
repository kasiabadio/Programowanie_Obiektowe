#ifndef ADRES_H_
#define ADRES_H_
#include <string>


class Adres{
public:
    Adres();
    Adres(const Adres& adres);
    bool ustaw_adres(std::string _ulica, int _nr_domu, int _nr_mieszkania);
    std::string odczytaj_adres() const;
    ~Adres();


protected:
    std::string *ulica;
    int *nr_domu;
    int *nr_mieszkania;
    
};


#endif // ADRES_H_