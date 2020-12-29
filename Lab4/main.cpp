#include "samochod.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdbool.h>
#include <iterator>
#include <set>

struct cmp {
    bool operator() (const Samochod &a, const Samochod &b) const{
        return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
    }
};


std::ostream& operator<<(std::ostream &os, const Samochod& samochod){
    os << samochod.model << " " << samochod.poziom_paliwa << "\n";
    return os;
}

int main(){

    
    Samochod multipla = Samochod();
    float ile_paliwa = multipla.odczytaj_poziom_paliwa();
    std::cout << "Paliwo: " << ile_paliwa << std::endl;
    
    multipla.napelnij_bak(60);
    ile_paliwa = multipla.odczytaj_poziom_paliwa();
    std::cout << "Paliwo: " << ile_paliwa << std::endl;

    float pojemnosc_baku = multipla.odczytaj_pojemnosc_baku();
    std::cout << "Pojemnosc w baku: " << pojemnosc_baku << std::endl;

    unsigned int przejechane_kilometry = multipla.odczytaj_przejechane_kilometry();
    std::cout << "Przejechane kilometry: " << przejechane_kilometry << std::endl;

    multipla.dodaj_przejechane_kilometry(200);
    przejechane_kilometry = multipla.odczytaj_przejechane_kilometry();
    std::cout << "Przejechane kilometry: " << przejechane_kilometry << std::endl;

    std::cout << std::endl;
    Samochod s1(123, "audi");
    if(s1){
        std::cout << s1.odczytaj_model_samochodu() << " - model nie jest pustym stringiem" << std::endl;
    }else{
        std::cout << "Model jest pustym stringiem" << std::endl;
    }
    if(!s1){
        std::cout << "Pojemnosc baku > 0" << std::endl;
    }else{
        std::cout << "Pojemnosc baku =< 0" << std::endl;
    }

    std::cout << std::endl;
    Samochod s2(0, "bmw");
    if(s2){
        std::cout << s2.odczytaj_model_samochodu() << " - model nie jest pustym stringiem" << std::endl;
    }else{
        std::cout << "Model jest pustym stringiem" << std::endl;
    }
    if(!s2){
        std::cout << "Pojemnosc baku > 0" << std::endl;
    }else{
        std::cout << "Pojemnosc baku =< 0" << std::endl;
    }

    std::cout << std::endl;
    Samochod s3(200, "");
    if(s3){
        std::cout << s3.odczytaj_model_samochodu() << " - model nie jest pustym stringiem" << std::endl;
    }else{
        std::cout << "Model jest pustym stringiem" << std::endl;
    }
    if(!s3){
        std::cout << "Pojemnosc baku > 0" << std::endl;
    }else{
        std::cout << "Pojemnosc baku =< 0" << std::endl;
    }

    std::cout << s1 << std::endl;

    // sortowanie leksykograficzne
    std::vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    std::cout << "Przed posortowaniem: " << std::endl;
    for(auto it = v.begin(); it != v.end(); ++it){
        std::cout << *it;
    }
    sort(v.begin(), v.end());
    std::cout << "Po posortowaniu: " << std::endl;
    for(auto it = v.begin(); it != v.end(); ++it){
        std::cout << *it;
    }
    
    // sortowanie według rosnącej pojemnosci baku
    std::set <Samochod, cmp> s;
    std::cout << std::endl << "Set: " << std::endl;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for(auto it = s.begin(); it != s.end(); ++it){
        std::cout << *it;
    }

    // napisz przeciążenia dla:
    // ++ - oznacza podwyższenie poziomu paliwa o 10l
    std::cout << "Poziom paliwa: " << s2.odczytaj_poziom_paliwa() << std::endl;
    ++(s2);
    std::cout << "Poziom paliwa po napelnieniu: " << s2.odczytaj_poziom_paliwa() << std::endl;
    // ,

    // |= 

    return 0; 
}