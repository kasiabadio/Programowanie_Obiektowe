#include "pszczoly.h"
#include <iostream>

int main(){
    Ul my_ul(123);
    
    if (my_ul.zmiana_liczby_pszczol(-12)){
        std::cout << "Liczba pszczol: " << my_ul.odczytaj_liczbe_pszczol() << std::endl;
    }else{
        std::cout << "error" << std::endl;
    }

    my_ul.ustaw_koordynaty(1,4);
    std::vector<int> wspolrzedne = my_ul.odczytaj_koordynaty();
    std::cout << "x: " << wspolrzedne[0] << " y: " << wspolrzedne[1] << std::endl;

    float miod = my_ul.odczytaj_miod();
    std::cout << "Ilosc miodu: " << miod << std::endl;
    my_ul.zaktualizuj_miod(123.23);
    my_ul.zaktualizuj_miod(12);
    miod = my_ul.odczytaj_miod();
    std::cout << "Ilosc miodu: " << miod << std::endl;

    std::string testName1 = "Pasieka wyborna";
    std::string testName2 = "pasieka z małej literki";

    if(my_ul.okresl_nazwe_pasieki(testName1)){
        std::cout << "Nazwa pasieki: " << my_ul.odczytaj_nazwe_pasieki() << std::endl;
    }else{
        std::cout << "error" << std::endl;
    }

    if(my_ul.okresl_nazwe_pasieki(testName2)){
        std::cout << "Nazwa pasieki: " << my_ul.odczytaj_nazwe_pasieki() << std::endl;
    }else{
        std::cout << "error" << std::endl;
    }

    std::cout << "Wlasciciel(ka): " << my_ul.odczytaj_imie_wlasciciela() << " " << my_ul.odczytaj_nazwisko_wlasciciela() << std::endl;
    my_ul.zaktualizuj_wlasciciela("Aleksandra", "Kowalska");
    std::cout << "Wlasciciel(ka): " << my_ul.odczytaj_imie_wlasciciela() << " " << my_ul.odczytaj_nazwisko_wlasciciela() << std::endl;
    
    return 0;
}