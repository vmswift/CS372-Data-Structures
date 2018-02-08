//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Stack Program
//Class: CS372 Spring 2015
//Due Date: Feb. 18, 2015
//file: stack.h
#include "listint.h"

class Stacks
{
public:
    void push(VT v);  //push value onto stack
    void pop(); //pop value off top of the stack
    bool empty();  //check if stack is empty
    size_t size();  //return size of the stack
    VT top(); //return top element in the stack
private:
    Lists myStack;
};


void Stacks::push(VT v)
{
    myStack.end();
	myStack.insertAfter(v);
	myStack.end();
}


void Stacks::pop()
{
    myStack.end();
    myStack.erase();
	myStack.end();
}

bool Stacks::empty()
{
    return(myStack.empty());
}

size_t Stacks::size()
{
    return(myStack.size());
}

VT Stacks::top()
{
    myStack.end();
    return(myStack.getElement());
}
