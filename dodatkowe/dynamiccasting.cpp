#include <iostream>
#include <string>

class Entity
{
public:
    virtual void PrintName(){}
};

class Player : public Entity
{
public:
};

class Enemy : public Entity
{
public:
};

int main()
{
    int a = 8;
    a++;
    const char* stringg = "Hello";
    printf("Hello world");
    for(int i = 0; i < 5; i ++){
        const char c = stringg[i];
        std::cout << c << std::endl;
    }
    /*dynamic casting
    if the cast is valid then it returns a value that you want
    but if it is not valid because it is not a type that you claimed that it is, then it return NULL*/
    Entity* actuallyPlayer = new Player();
    Entity* actuallyEnemy = new Enemy();

    Player* p = dynamic_cast<Player*>(actuallyEnemy);
    if (p){
        std::cout << "WOW" << std::endl;
    }
    Player* p1 = dynamic_cast<Player*>(actuallyPlayer);

}