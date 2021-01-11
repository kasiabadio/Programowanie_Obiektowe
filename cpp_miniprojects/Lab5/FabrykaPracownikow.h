#ifndef FABRYKA_PRACOWNIKOW_H_
#define FABRYKA_PRACOWNIKOW_H_
#include "FabrykaOsob.h"
#include "Pracownik.h"

class FabrykaPracownikow: public FabrykaOsob
{
public:
    Pracownik* utworz();
    
};

#endif // FABRYKA_PRACOWNIKOW_H_