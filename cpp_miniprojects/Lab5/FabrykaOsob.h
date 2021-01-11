#ifndef FABRYKA_OSOB_H_
#define FABRYKA_OSOB_H_
#include "Osoba.h"

class FabrykaOsob 
{
public:
    virtual Osoba* utworz() = 0;
    
    
};

#endif // FABRYKA_OSOB_H_