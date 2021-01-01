#include <iostream>
#include <string>

class Entity{
private:
    std::string m_Name;
public:
    Entity():
        m_Name("Unknown")
    {}
    
    Entity(const std::string& name){
        m_Name = name;
    }
    const std::string& GetName() const {return m_Name;}
};

int main(){
    Entity e;
    std::cout << e.GetName() << std::endl;

    Entity e1("Cherno");
    std::cout << e1.GetName() << std::endl;


}

