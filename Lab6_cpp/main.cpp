#include "Stack.h"
#include <exception>

class StackException : public std::exception
{
public:
    StackException() {}
    virtual const char *what() const noexcept override
    {
        return "Bledna operacja na stosie!";
    }
};

class StackFullException : public StackException
{
    int element = 0;
    int maxStackSize = 0;
    std::string message;

public:
    StackFullException() {}
    StackFullException(std::string p, int e, int s) {}
    // what() returns a cause of an exception
    virtual const char *what() const noexcept override {
        return "Stos jest pełny!";
    }
};

class StackEmptyException : public StackException
{
    std::string message;

public:
    StackEmptyException() {}
    StackEmptyException(std::string p) {}
    virtual const char *what() const noexcept override {
        return "Stos jest pusty!";
    }
};

void function_5(Stack &s)
{
    try
    {
        for (int i = 0; i < 12; i++)
        {
            s.push(i);
        }
    }
    catch (StackException e)
    {
        std::cout << e.what() << std::endl;
    }
}

void function_6(Stack &s)
{
    for (int i = 0; i < 12; i++)
    {
        try
        {
            s.push(i);
        }
        catch (StackException &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}

int main()
{

    Stack stack(10);
    std::cout << "Dodawanie na stos" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    //stack.push(10);

    std::cout << "Zdejmowanie ze stosu" << std::endl;
    for (int j = 9; j >= 0; j--)
    {
        std::cout << stack.pop() << std::endl;
    }
    //std::cout << stack.pop() << std::endl;

    /*punkt 5
    przy próbie przekroczenia rozmiaru stosu
    wyłapywany jest wyjątek StackException i wyświetla się na ekranie
    "Bledna operacja na stosie!"*/
    std::cout << "Punkt 5" << std::endl;
    Stack stack_5(10);
    function_5(stack_5);

    /*punkt 6
    przy próbie przekroczenia rozmiaru stosu
    wyłapywany jest wyjątek StackFullException i wyświetla się na ekranie
    "Stos jest pelny!"*/
    std::cout << "Punkt 6" << std::endl;
    Stack stack_6(10);
    function_6(stack_6);

    // try{

    // }catch(StackException &e){

    // }

    return 0;
}