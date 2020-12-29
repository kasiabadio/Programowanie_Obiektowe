#include <iostream>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }

};


class Player : public Entity
{
public:
    const char* Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }

};

int main()
{
    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;
    Player player;
    player.X = 7;
    player.Y = 2;
    player.Move(5, 5);
    player.PrintName();
    

    std::cin.get();

}