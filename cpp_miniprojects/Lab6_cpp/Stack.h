#ifndef STACK_H_
#define STACK_H_
#include <vector>
#include <exception>
#include <iostream>


class Stack{
public:
    Stack();
    Stack(int max);
    void push(int newItem);
    int pop();

private:
   int maxStackSize;
   std::vector<int> dfs;
   int top; 
    
};


#endif // STACK_H_