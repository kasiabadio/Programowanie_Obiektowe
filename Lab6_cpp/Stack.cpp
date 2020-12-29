#include "Stack.h"

// struct StackOverflowException : public std::exception
// {
//     const char *what() const throw()
//     {
//         return "Przekroczony rozmiar stosu";
//     }
// };

// struct StackUnderflowException : public std::exception
// {
//     const char *what() const throw()
//     {
//         return "Rozmiar stosu jest rowny 0";
//     }
// };

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

Stack::Stack() : maxStackSize{1000},
                 top{0}
{
}

Stack::Stack(int max) : maxStackSize{10},
                        top{0}
{
}

void Stack::push(int newItem)
{
    int dfs_size = dfs.size();
    if (dfs_size == maxStackSize)
    {
        throw StackFullException();
    }
    else
    {
        std::cout << newItem << std::endl;
        dfs.push_back(newItem);
    }
}

int Stack::pop()
{
    int dfs_size = dfs.size();
    if (dfs_size == 0)
    {
        throw StackEmptyException();
    }
    int dfs_back = dfs.back();
    dfs.pop_back();
    return dfs_back;
}