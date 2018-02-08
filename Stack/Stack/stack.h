//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Stack Program
//Class: CS372 Spring 2015
//Due Date: Feb. 18, 2015
//file: stack.h
#include "list.h"

class Stack
{
public:
    void push(valueType v);  //push value onto stack
    void pop(); //pop value off top of the stack
    bool empty();  //check if stack is empty
    size_t size();  //return size of the stack
    valueType top(); //return top element in the stack
private:
    List myStack;
};


void Stack::push(valueType v)
{
    myStack.end();
    myStack.insertAfter(v);
}


void Stack::pop()
{
    myStack.end();
    myStack.erase();
}

bool Stack::empty()
{
    return(myStack.empty());
}

size_t Stack::size()
{
    return(myStack.size());
}

valueType Stack::top()
{
    myStack.end();
    return(myStack.getElement());
}
