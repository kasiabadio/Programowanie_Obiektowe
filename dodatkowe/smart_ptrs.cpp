#include <iostream>
#include <string>
#include <memory>

class Entity{
public:
    Entity(){
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity(){
        std::cout << "Destroyed Entity!" << std::endl;
    }
};



int main(){
    std::shared_ptr<Entity> s0 ;
    {
        //std::unique_ptr<Entity> entity(new Entity());
        //std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();

        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
        //std::weak_ptr<Entity> weakEntity = sharedEntity;
        s0 = sharedEntity;
    }

}