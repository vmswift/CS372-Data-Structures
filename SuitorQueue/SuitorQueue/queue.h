//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Suitor Circular Queue
//Class: CS372 Spring 2015
//Due Date: Feb. 18, 2015
//file: queue.h

#include "list.h"

class queue
{
    private:
		List list;
    public:
        queue(); //default constructor
		void next(); //move to next place in circle queue
        bool empty(); //check if queue is empty
        void dequeue(); //remove current element from circle queue
		void enqueue(valueType inElem); //insert element into queue
        char top();  //return top element
        int SIZE();  //return the current queue size
		void print(); //print entire queue
};

queue::queue()
{
}

void queue::next()
{
	if(list.getPos()==list.size()) 
	{
		list.front();//if list is at the end position set it to the front
	}
	else
	{
		list.next();//move to next position
	}
}

bool queue::empty()
{
    return(list.empty());//return true/false if empty
}



void queue::dequeue()
{
	if(list.getPos()==list.size())
	{
		list.erase();//if list is at the end then erase
		list.front();//then set to front since queue is circular
	}
	else
	{
		list.erase();//else just erase current item without worry
	}
	
}

void queue::enqueue(valueType inElem)
{
	list.insertAfter(inElem);
	if(list.size()==list.CAPACITY)
	{
		list.front();//if list is full after current insert then set to first position
	}
}

char queue::top()
{
	list.front(); //set position to front
	return(list.getElement());//return front/top element
}

int queue::SIZE()
{
	return(list.size());//return queue size
}

void queue::print()
{
	std::cout << list << std::endl; //return all elements in list
}
