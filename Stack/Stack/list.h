//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: General List Program
//Class: CS372 Spring 2015
//Due Date: Feb. 4, 2015
//file: list.h

typedef char valueType; //valueType is actually size_t

class List
{


public:
    static const size_t CAPACITY=36;  //capacity for easy size change
	List(); //list constructor
	List(List &listA); //list copy constructor
	bool empty();  //will tell you if list is empty or not in bool form
	void front();  //moves position to front of the list
	void end();    //moves position to end of the list
	void prev();   //moves to previous postion in list
	void next();   //moves to next position in list
	size_t getPos();  //returns element value of position in list
	void setPos(size_t inPOS);  //sets the position manually for the list
	void insertBefore(valueType inElem);  //insert element into list before present location
	void insertAfter(valueType inElem); //insert element into list after present location
	valueType getElement(); //return the element of the current position in the list
	size_t size();     //return current size of the list using the used private variable
	void replace(valueType inElem); //replace item in a list at current position
	void erase();        //deletes current element from list then moves data down to fill its spot if needed
	void clear();        //makes the list empty and resets pos and used variables
	void reverse();      //reverses elements in the list
	void swap(List &aList);  //basically moves from one to another list and vice versa
	friend  std::ostream& operator<<(std::ostream& outs,List& aList); //overload cout to output list
	bool operator==(List& aList);  //overload == to output if one list is == to another
	bool operator!=(List& aList); //overload != to output if one list != to another
	void operator+(List& aList);  //overload + to add 2 lists values into one list
	void operator+=(List& aList); //overload += to add 2 lists values and my them assigned to one list
	void operator=(List& aList); //overload = to assign the value of one list to another. can overwrite values in list getting assigned
private:
	size_t pos;  //current position in the list, this is subject to constant change :D
	size_t used; //number of used locations int he list, max is 20 unless capacity is changed
	valueType myArray[CAPACITY];  //array for list
};

List::List() //default constructor
{
	pos=0;  //position set 0
	used=0; //used set 0
	for(size_t i=0;i<CAPACITY;i++)
	{
		myArray[i]=0; //array is zeroed out
	}

}

List::List(List &listA)
{
	pos=listA.pos; //listA is copied to list pos
	used=listA.used; //listA is copied to list used
	for(size_t i=0;i<listA.size();i++)
	{
		myArray[i]=listA.myArray[i]; //entire array is copied
	}

}

bool List::empty() //check if list is empty
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

void List::front() //move pos to front of array
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

void List::end() //move pos to end of array
{
	if(used>0) //check if any positions are even used at all
	{
		pos=used-1; //if that was true then use used to set last pos
	}
	else
	{
	}
}

void List::prev() //move to previous pos in array
{
	if(used>=2)  //error catch to make sure you don't go before the array starts
		pos--;
}

void List::next() //move to next pos in array
{
    if(pos<used&&pos<CAPACITY-1){pos++;} //strong error catch so you don't go off the end of the array

}

size_t List::getPos() //return current position
{
	if(used>0)
		return pos+1; //position converted from array style to user friendly
	else
		return 0;
}

void List::setPos(size_t inPOS) //set position to manual inserted position
{
	if(inPOS<=used&&inPOS<=CAPACITY) //error catch
	{
		pos=inPOS-1;  //position converted to array format for easy used in future
	}
	else
	{
	}
}

void List::insertBefore(valueType inElem) //insert before current pos in list
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


void List::insertAfter(valueType inElem)  //insert after current position
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



valueType List::getElement()  //return element from current position
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

size_t List::size()  //return size of list
{
	return(used);
}

void List::replace(valueType inElem)  //replace element at current position with inElem
{
	myArray[pos]=inElem;
}


void List::erase()  //erase current position in list along with element
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
        else if(pos==used-1)
        {
            used--;
            pos--;
            return;
        }

        else if(pos>=0)
        {

            while(temp<used)
            {
                
                myArray[temp]=myArray[temp+1];
                temp++;
               
            }
            used--;
            return;
        }
    }


}


void List::clear() //zero the list out
{
	used=0;
	pos=0;
	for(size_t i=0;i<CAPACITY;i++)
	{
		myArray[i]=0;
	}
}

void List::reverse()  //reverse the list
{
	valueType t1=0,t2=0;  //temp values
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

void List::swap(List &aList)  //swap list with another and vice versa
{
	valueType temp=0;
	for(size_t i=0;i<CAPACITY;i++)
	{
		temp=myArray[i];
		myArray[i]=aList.myArray[i];
		aList.myArray[i]=temp;
	}
}


std::ostream& operator<<(std::ostream& outs,List& aList)  //output list if it has values  (cout << listA << endl)
{

		for(size_t i=0;i<aList.used;i++)
		{
			outs << aList.myArray[i] << " ";
		}

    return outs;
}

bool List::operator==(List& aList)  //check if lists are equal (listA==listB)
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

bool List::operator!=(List& aList)  //check if lists are not equal (listA!=listB)
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


void List::operator+(List& aList)  //add 2 lists (listA+listB)
{
	for(size_t i=0;i<used;i++)
	{
		myArray[i]=myArray[i]+aList.myArray[i];

	}

}

void List::operator+=(List& aList)  //add 2 lists (listA=listA+listB)
{
	for(size_t i=0;i<used;i++)
	{
		myArray[i]=myArray[i]+aList.myArray[i];

	}
}

void List::operator=(List& aList) //assign values of one list to another (listA=listB)
{
	for(size_t i=0;i<aList.size();i++)
	{
		myArray[i]=aList.myArray[i];
	}
	used=aList.size();
}
