#include <memory>
#include "Wezel.h"

int main()
{
    /*Obiekty są niszczone od razu gdy przestają być używane (they are out of scope)*/
    std::cout << "*Unique ptr*" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::unique_ptr<Wezel>(new Wezel());
    }

    /*Brak zmian - Liczone są referencje do wskaźnika, gdy ta liczba jest równa 0, to
    wskaźnik jest usuwany
    */
    std::cout << "*Shared ptr*" << std::endl;
    for (int j = 0; j < 10; j++){
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
    }

    /*Program nie zwalnia pamięci poprawnie
    Wskaźniki nie są usuwane, ponieważ ciągle istnieją do nich referencje (w->next)*/
    std::cout << "*Shared ptr - cykliczne referencje*" << std::endl;
    for(int k = 0; k < 10; k ++){
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();
        w1->next = w1;
        w2->next = w2;
    }

    /*Program poprawnie teraz zwalnia pamięć
    weak_ptr jest jak obserwator - może dostać się do tego samego obiektu co shared_ptr,
    ale nie jest rozpoznawany jako właściciel obiektu
    wskaźniki shared_ptr liczą jedynie referencje do właścicieli, zatem wskaźniki 
    są usuwane gdy referencji nie ma (w-> next weak to weak ptr)*/
    std::cout << "*Weak ptr*" << std::endl;
    for(int k = 0; k < 10; k ++){
        std::shared_ptr<Wezel> w1 = std::make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std::make_shared<Wezel>();

        w1->next_weak = w1;
        w2->next_weak = w2;
    }

    return 0;
}