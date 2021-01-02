#include <iostream>
#include <string>


class Entity
{
private:
    int *m_X, *m_Y;
    int m_Z;
    mutable int var;
    
public:
    const int* const GetX() const
    {
        return m_X;
    }

    void SetZ(int Z) 
    {
        m_Z = Z;
    }

    int GetZ() const
    {
        var = 2;
        return m_Z;
    }
};

void PrintEntity(const Entity& e)
{
    std::cout << e.GetZ() << std::endl;
}


int main(){


    const int MAX_AGE = 5;
    const int* const a = new int;
    *a = 2;
    a = (int*)&MAX_AGE;
    *a = 77;
    std::cout << *a << std::endl;

}

