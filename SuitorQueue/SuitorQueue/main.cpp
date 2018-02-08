//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Suitor Circular Queue
//Class: CS372 Spring 2015
//Due Date: Feb. 18, 2015
//file: main.cpp

#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	queue myQ;
	//set myQ as being of queue class

	for(char i='A';i<='d';i++)
	{
		myQ.enqueue(i); 
		//insert into queue ASCII char from 'A' to 'd'
	}

	cout << "Queue of Suitors: " << endl;
	myQ.print(); 
	cout << endl << endl;
	//print list of all possible suitors

	while(myQ.SIZE()>1)
	//loop continues until the queue size is 1
	{
		//skip 2 places then delete. 
		//We are technically moving 3 space since we count starting locations.
		myQ.next();
		myQ.next();
		myQ.dequeue();
		//myQ.print();
		//cout << endl << endl;
		// used to test for proper space skipping and deletion
	}

	
	cout << "The winning suitor is: " << myQ.top() << endl;
	//print winning suitor for princess Eve
	cout << "Queue size is: " << myQ.SIZE() << endl << endl;

	return 0;
}
