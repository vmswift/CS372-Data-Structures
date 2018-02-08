#include <iostream>
#include <cmath>
#include "stack.h"
#include "queue.h"
#include <fstream>
#include "listint.h"
#include "stackint.h"
using namespace std;

class InToPost
{
    public:
        queue inQueue; //infix queue
        queue postQueue; //postfix queue
        Stack expStack; //expression stack
        Stacks calc;
        void readFile(char temp);
        void printInfix();
        void printPostfix();
        void erase();
        int sum();
};

void InToPost::readFile(char temp)
{
    if(temp>='0'&&temp<='9')
    {
        inQueue.enqueue(temp);
        postQueue.enqueue(temp);
    }
    else if(temp=='(')
    {
        inQueue.enqueue(temp);
        expStack.push(temp);
    }
    else if(temp==')')
    {
        inQueue.enqueue(temp);
        if(expStack.top()!='(')
        {
            while(expStack.top()!='(')
            {postQueue.enqueue(expStack.top());
            expStack.pop();
            }
            expStack.pop();
        }

    }
    else if(temp=='^')
    {
        inQueue.enqueue(temp);
        if(expStack.top()=='^')
        {
			while(expStack.top()=='^'&&expStack.size()!=0)
			{
            postQueue.enqueue(expStack.top());
            expStack.pop();
			}
            expStack.push(temp);
        }
        else
        {
            expStack.push(temp);
        }
    }
    else if(temp=='*'||temp=='/')
    {
        inQueue.enqueue(temp);
            if(expStack.top()=='^')
            {
                while(expStack.top()=='^'&&expStack.size()!=0)
                {

                postQueue.enqueue(expStack.top());
                expStack.pop();
                }
                expStack.push(temp);
            }
            else
            {
                expStack.push(temp);
            }
    }
    else if(temp=='+'||temp=='-')
    {
        inQueue.enqueue(temp);
            if((expStack.top()=='*')||(expStack.top()=='/')||(expStack.top()=='^'))
            {
                while((expStack.top()=='*'||expStack.top()=='/'||expStack.top()=='^')&&expStack.size()!=0)
               {

                postQueue.enqueue(expStack.top());
                expStack.pop();
               }
                expStack.push(temp);
            }

        else
        {
            expStack.push(temp);
        }
    }
    else if(temp=='#')
    {
        while(expStack.size()>0)
        {
            postQueue.enqueue(expStack.top());
            expStack.pop();
        }
    }
}

void InToPost::printInfix()
{
    inQueue.print();
}
void InToPost::printPostfix()
{
    postQueue.print();
}

void InToPost::erase()
{   while(!inQueue.empty())
    {
        inQueue.dequeue();
    }
    while(!postQueue.empty())
    {
        postQueue.dequeue();
    }
    while(!calc.empty())
    {
        calc.pop();
    }

}

int InToPost::sum()
{
	int temp1,temp2;
	int array[25];
	int size=0;
   /* while(postQueue.SIZE()!=0)
    {
		temp1=0;
		temp2=0;
        if(postQueue.top()>='0'&&postQueue.top()<='9')
        {
            calc.push((postQueue.top()-'0'));
            postQueue.dequeue();
        }
        else if(postQueue.top()=='-')
        {
            temp2=calc.top();
            calc.pop();
            temp1=calc.top();
            calc.pop();
           
            calc.push(temp1-temp2);
            postQueue.dequeue();

        }
        else if(postQueue.top()=='+')
        {
            temp2=calc.top();
            calc.pop();
            temp1=calc.top();
            calc.pop();
            
			
            calc.push(temp1+temp2);
            postQueue.dequeue();
	
        }
        else if(postQueue.top()=='/')
        {
            temp2=calc.top();
            calc.pop();
            temp1=calc.top();
            calc.pop();
           
            calc.push(temp1/temp2);
            postQueue.dequeue();

        }
        else if(postQueue.top()=='*')
        {
            temp2=calc.top();
            calc.pop();
            temp1=calc.top();
            calc.pop();
            calc.push(temp1*temp2);
            postQueue.dequeue();

        }
        else if(postQueue.top()=='^')
        {
            temp2=calc.top();
            calc.pop();
            temp1=calc.top();
            calc.pop();
            calc.push(pow(temp1,temp2));
            postQueue.dequeue();
			//cout << calc.top() << " ";

        }
    }
    temp1=0;
    temp2=0;
    if(calc.size()==1)
    {
        return calc.top();
    }
    else if(calc.size()>1||calc.size()==0)
    {
        //cout << "We have a problem!!" << endl;
    }*/
   while(postQueue.SIZE()!=0)
    {
		temp1=0;
		temp2=0;

        if(postQueue.top()>='0'&&postQueue.top()<='9')
        {
			if(size==0)
			{
            array[size]=postQueue.top()-'0';
            postQueue.dequeue();
			size++;
			}
			else
			{
				size++;
				array[size-1]=postQueue.top()-'0';
				postQueue.dequeue();
				
			}
        }
        else if(postQueue.top()=='-')
        {
			temp2=array[size-1];
            size--;
            temp1=array[size-1];
            size--;
			postQueue.dequeue();
			if(size==0)
			{
				array[size]=temp1-temp2;
				size++;
			}
			else
			{
				size++;
				array[size-1]=temp1-temp2;
			}
            

        }
        else if(postQueue.top()=='+')
        {
            temp2=array[size-1];
            size--;
            temp1=array[size-1];
            size--;
			postQueue.dequeue();
			if(size==0)
			{
				array[size]=temp1+temp2;
				size++;
			}
			else
			{
				size++;
				array[size-1]=temp1+temp2;
			}
        }
        else if(postQueue.top()=='/')
        {
            temp2=array[size-1];
            size--;
            temp1=array[size-1];
            size--;
			postQueue.dequeue();
			if(size==0)
			{
				array[size]=temp1/temp2;
				size++;
			}
			else
			{
				size++;
				array[size-1]=temp1/temp2;
			}

        }
        else if(postQueue.top()=='*')
        {
            temp2=array[size-1];
            size--;
            temp1=array[size-1];
            size--;
			postQueue.dequeue();
			if(size==0)
			{
				array[size]=temp1*temp2;
				size++;
			}
			else
			{
				size++;
				array[size-1]=temp1*temp2;
			}

        }
        else if(postQueue.top()=='^')
        {
            temp2=array[size-1];
            size--;
            temp1=array[size-1];
            size--;
			postQueue.dequeue();
			if(size==0)
			{
				array[size]=pow(temp1,temp2);
				size++;
			}
			else
			{
				size++;
				array[size-1]=pow(temp1,temp2);
			}
			//cout << calc.top() << " ";

        }
    }
    
	return array[0];


}

int main()
{
    InToPost fix;
    ifstream infile;
    char temp;
    infile.open("test.txt");
    if ( !infile )            // did the input file open???
    {
        cout << "error opening in put file " << endl;
    }
	int counter=0;
   while(infile)
    {

        do
        {
            infile.get(temp);
            if(temp=='\n')
            {
                fix.readFile('#');
            }
            else
            {
                fix.readFile(temp);
            }

        }
        while(temp!='\n');
		counter++;
        fix.printInfix();
        fix.printPostfix();
		if(counter<=10)
		{
			cout << " The total is: " << fix.sum() << endl;
		}
        fix.erase();
        cout << endl;

    }

    return 0;
}
