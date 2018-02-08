//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: General List Program
//Class: CS372 Spring 2015
//Due Date: Feb. 4, 2015
//file: list.h

typedef int VT; //valueType is actually size_t
#pragma once //fix for queue and stack using list class http://en.wikipedia.org/wiki/Pragma_once
//This was taught to me at Calhoun in CS218

class Lists
{


public:
    static const size_t CAPACITY=36;  //capacity for easy size change
	Lists(); //list constructor
	Lists(Lists &listA); //list copy constructor
	bool empty();  //will tell you if list is empty or not in bool form
	void front();  //moves position to front of the list
	void end();    //moves position to end of the list
	void prev();   //moves to previous postion in list
	void next();   //moves to next position in list
	size_t getPos();  //returns element value of position in list
	void setPos(size_t inPOS);  //sets the position manually for the list
	void insertBefore(VT inElem);  //insert element into list before present location
	void insertAfter(VT inElem); //insert element into list after present location
	VT getElement(); //return the element of the current position in the list
	size_t size();     //return current size of the list using the used private variable
	void replace(VT inElem); //replace item in a list at current position
	void erase();        //deletes current element from list then moves data down to fill its spot if needed
	void clear();        //makes the list empty and resets pos and used variables
	void reverse();      //reverses elements in the list
	void swap(Lists &aList);  //basically moves from one to another list and vice versa
	friend  std::ostream& operator<<(std::ostream& outs,Lists& aList); //overload cout to output list
	bool operator==(Lists& aList);  //overload == to output if one list is == to another
	bool operator!=(Lists& aList); //overload != to output if one list != to another
	void operator+(Lists& aList);  //overload + to add 2 lists values into one list
	void operator+=(Lists& aList); //overload += to add 2 lists values and my them assigned to one list
	void operator=(Lists& aList); //overload = to assign the value of one list to another. can overwrite values in list getting assigned
private:
	size_t pos;  //current position in the list, this is subject to constant change :D
	size_t used; //number of used locations int he list, max is 20 unless capacity is changed
	valueType myArray[CAPACITY];  //array for list
};

Lists::Lists() //default constructor
{
	pos=0;  //position set 0
	used=0; //used set 0
	for(size_t i=0;i<CAPACITY;i++)
	{
		myArray[i]=0; //array is zeroed out
	}

}

Lists::Lists(Lists &listA)
{
	pos=listA.pos; //listA is copied to list pos
	used=listA.used; //listA is copied to list used
	for(size_t i=0;i<listA.size();i++)
	{
		myArray[i]=listA.myArray[i]; //entire array is copied
	}

}

bool Lists::empty() //check if list is empty
{
	//if places in list are used then list cannont be empty
	if(used>0)
	{
		return false;
	}
	else
	{//else return that list is empty
		return true;
	}
}

void Lists::front() //move pos to front of array
{
	if(used>0)
	{//if positions are used then set pos to 0
		pos=0;
	}
	else
	{
	//if no positions are used then front isn't set or technically already set
	}
}

void Lists::end() //move pos to end of array
{
	if(used>0) //check if any positions are even used at all
	{
		pos=used-1; //if that was true then use used to set last pos
	}
	else
	{
	}
}

void Lists::prev() //move to previous pos in array
{
	if(used>=2)  //error catch to make sure you don't go before the array starts
		pos--;
}

void Lists::next() //move to next pos in array
{
    if(pos<used&&pos<CAPACITY-1){pos++;} //strong error catch so you don't go off the end of the array

}

size_t Lists::getPos() //return current position
{
	if(used>0)
		return pos+1; //position converted from array style to user friendly
	else
		return 0;
}

void Lists::setPos(size_t inPOS) //set position to manual inserted position
{
	if(inPOS<=used&&inPOS<=CAPACITY) //error catch
	{
		pos=inPOS-1;  //position converted to array format for easy used in future
	}
	else
	{
	}
}

void Lists::insertBefore(VT inElem) //insert before current pos in list
{
	if(pos==0&&used<CAPACITY) //only if pos==0
	{


		if(used==0)
        {
            myArray[pos]=inElem;
            used++;
            return;
        }
        used++; //add another used spot

		//prev() statement not needed cuz pos is in array format, can't decrement at position 0
			for(size_t i=0,j=0,k=pos;k<used;k++)
			{
				if(k==pos) //first time through loop
				{
					i=myArray[k]; //copy out current element
					myArray[k]=inElem; //copy in new element
				}
				else //every other time through loop
				{
					j=myArray[k]; //takes value out of current location
					myArray[k]=i;  //copy new value into location
					i=j; //copy value to be inserted next time in loop

				}
			}

	}
	else if(pos>=1&&used<CAPACITY) //do this only if pos is great than 0 or else we can't insert before
	{
		prev(); //move pos to previous
		used++; //add another used spot
			for(size_t i=0,j=0,k=pos;k<used;k++)
			{
				if(k==pos) //first time through loop
				{
					i=myArray[k]; //copy out current element
					myArray[k]=inElem; //copy in new element
				}
				else //every other time through loop
				{
					j=myArray[k]; //takes value out of current location
					myArray[k]=i;  //copy new value into location
					i=j; //copy value to be inserted next time in loop

				}
			}

	}


}


void Lists::insertAfter(VT inElem)  //insert after current position
{

	if(!empty()) //check if array is not empty
	{
		if(pos<used) //check if pos is less than used
		{

			next(); //increment position
			used++; //increment used
			for(size_t i=0,j=0,k=pos;k<used;k++)
			{
				if(k==pos) //first time through loop
				{
					i=myArray[k]; //copy out current element
					myArray[k]=inElem; //copy in new element
				}
				else //every other time through loop
				{
					j=myArray[k]; //takes value out of current location
					myArray[k]=i;  //copy new value into location
					i=j; //copy value to be inserted next time in loop

				}
			}

		}
		else
		{
		}

	}
	else  //if array is empty do this
	{
		myArray[0]=inElem;
		used=1;
		pos=0;
	}

}



VT Lists::getElement()  //return element from current position
{
    if(used==1)
    {
        return(myArray[0]);
    }
    else
    {
        return(myArray[pos]);
    }
}

size_t Lists::size()  //return size of list
{
	return(used);
}

void Lists::replace(VT inElem)  //replace element at current position with inElem
{
	myArray[pos]=inElem;
}


void Lists::erase()  //erase current position in list along with element
{
    size_t temp;
    temp=pos;
    if(used>0)
    {
        if(used==1)
        {
            pos=0;
            used=0;
            return;
        }
        else if(pos==used-1&&used>1)
        {
            used--;
            pos--;
            return;
        }

        else if(used>1)
        {

            while(temp<=used-1)
            {
				if(temp==used-1)
				{
					temp++;
				}
				else
				{
					myArray[temp]=myArray[temp+1];
					temp++;
				}

            }
            used--;
            return;
        }
    }


}


void Lists::clear() //zero the list out
{
	used=0;
	pos=0;
	for(size_t i=0;i<CAPACITY;i++)
	{
		myArray[i]=0;
	}
}

void Lists::reverse()  //reverse the list
{
	VT t1=0,t2=0;  //temp values
	for(size_t i=0;i<used;i++)
	{
		if(i>used-(i+1))
		{
			t1=myArray[i];
			t2=myArray[used-(i+1)];
			myArray[i]=t2;
			myArray[used-(i+1)]=t1;
		}
	}
}

void Lists::swap(Lists &aList)  //swap list with another and vice versa
{
	VT temp=0;
	for(size_t i=0;i<CAPACITY;i++)
	{
		temp=myArray[i];
		myArray[i]=aList.myArray[i];
		aList.myArray[i]=temp;
	}
}


std::ostream& operator<<(std::ostream& outs,Lists& aList)  //output list if it has values  (cout << listA << endl)
{

		for(size_t i=0;i<aList.used;i++)
		{
			outs << aList.myArray[i] << " ";
		}

    return outs;
}

bool Lists::operator==(Lists& aList)  //check if lists are equal (listA==listB)
{
	for(size_t i=0;i<used-1;i++)
	{
		if(myArray[i]!=aList.myArray[i])
		{
			return false;
		}
	}
	return true;
}

bool Lists::operator!=(Lists& aList)  //check if lists are not equal (listA!=listB)
{
	for(size_t i=0;i<used-1;i++)
	{
		if(myArray[i]!=aList.myArray[i])
		{
			return true;
		}
	}
	return false;

}


void Lists::operator+(Lists& aList)  //add 2 lists (listA+listB)
{
	for(size_t i=0;i<used;i++)
	{
		myArray[i]=myArray[i]+aList.myArray[i];

	}

}

void Lists::operator+=(Lists& aList)  //add 2 lists (listA=listA+listB)
{
	for(size_t i=0;i<used;i++)
	{
		myArray[i]=myArray[i]+aList.myArray[i];

	}
}

void Lists::operator=(Lists& aList) //assign values of one list to another (listA=listB)
{
	for(size_t i=0;i<aList.size();i++)
	{
		myArray[i]=aList.myArray[i];
	}
	used=aList.size();
}
