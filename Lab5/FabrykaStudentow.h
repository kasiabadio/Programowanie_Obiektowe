#ifndef FABRYKA_STUDENTOW_H_
#define FABRYKA_STUDENTOW_H_
#include "FabrykaOsob.h"
#include "Student.h"

class FabrykaStudentow: public FabrykaOsob
{
public:
    Student* utworz();
    
};

#endif // FABRYKA_STUDENTOW_H_