//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Stack Program
//Class: CS372 Spring 2015
//Due Date: Feb. 18, 2015
//file: main.cpp
#include <iostream>
#include "stack.h"
#include <fstream>
#include <string>
using namespace std;

ifstream infile;

int main()
{
    Stack myStack;//myStack is set to being of Stack class
    char myChar=0;//temp var for incoming data
    bool check;//bool check for matching brackets
    check=true;//check for matching is set to true by default
    infile.open("Stack3.dat");

	while(infile.get(myChar)&&check==true)
	//while infile isn't empty and matching check is true do this
    {
		cout << myChar << " "; //prints out file on screen for verification that contents are read properly

         if(myChar=='(')
        {
            myStack.push(myChar); //push open bracketcs
        }
        else if(myChar=='[')
        {
            myStack.push(myChar); //push open bracketcs
        }
        else if(myChar=='{')
        {
            myStack.push(myChar); //push open bracketcs
        }
        else if(myChar=='<')
        {
            myStack.push(myChar); //push open bracketcs
        }
		else if(myChar==')')
        {
			if(myStack.top()=='(') //if open mataches the closing bracket then pop
			{
				myStack.pop();
			}
			else
			{
				check=false;  //if brackets don't match then check is false and loop is killed
			}
        }
		else if(myChar==']')
        {
			if(myStack.top()=='[')//if open mataches the closing bracket then pop
			{
				myStack.pop();
			}
			else
			{
				check=false;//if brackets don't match then check is false and loop is killed
			}
        }
		else if(myChar=='}')
        {
			if(myStack.top()=='{')//if open mataches the closing bracket then pop
			{
				myStack.pop();
			}
			else
			{
				check=false;//if brackets don't match then check is false and loop is killed
			}
        }
		else if(myChar=='>')
        {
			if(myStack.top()=='<')//if open mataches the closing bracket then pop
			{
				myStack.pop();
			}
			else
			{
				check=false;//if brackets don't match then check is false and loop is killed
			}
        }

   }
	cout << endl;
	cout << endl;
	cout << "Stack size is: " << myStack.size() << endl;  //Shows that stack is empty before check
	cout << endl;
	if(check==true)
	{
		cout << "All Opening and Closing Brackets Match" << endl;
	}
	else
	{
		cout << "Some Opensing and Closing Brackets are Mismatched" << endl;
	}
	cout << endl;

	
    return 0;


}




