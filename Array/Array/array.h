//Array Class Header
//array.h
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 8/25/2014
//
#include <iostream>

using namespace std;

class Array
{
public:
	Array();  //array default construct
	Array(int size); //array size setting construct
	void setVal(int pos,int value); //vaule set for position and value
	int getVal(int pos); //get value of a position in the array
	int highVal(); //highest value in the array
	int lowVal(); //lowest value in the array
	int avg(); //avg of of all the values in the array
	int nonZero(); //number of nonzero position in the array
private:
	int *array1; //array pointer
	int length; //length of array
};

Array::Array()
{
	cout << "Please initilize array using Array(int size) " << endl;
	cin.get(); //holds the console in case of error
}

Array::Array(int size)
{
	length=size;
	array1= new int [size]; //set aray size
	for (int i=0;i<size;i++)//initialize array to zero
	{
		array1[i]=0;
		
	}
}

void Array::setVal(int pos,int value)
{
	if(pos-1>=0 && pos-1<=(length-1))
	{
	array1[pos-1]=value; //value at given position is set to given value
	}
	else
	{
		cout << "value cannot be set position is wrong" << endl; 
		cin.get(); //error is caught if pos is beyond legal value
	}
}

int Array::getVal(int pos)
{
	if(pos-1>=0 && pos-1<=(length-1))
	{
	return array1[pos-1]; //returns value at given array position
	}
	else
	{
		cout << "value cannot be returned position is wrong" << endl;
		cin.get(); //error is caught if pos is beyond legal value
	}
	return 0;
}

int Array::highVal()
{

	int num=array1[0];
	for(int i=0;i<=length-1;i++) //loop for highest value
	{
		if(num<array1[i])
		{
			num=array1[i];
		}
	}
	return num; //return highest value
}

int Array::lowVal()
{
	int num=array1[0];
	for(int i=0;i<=length-1;i++)//loop for lowest value
	{
		if(num>array1[i])
		{
			num=array1[i];
		}
	}
	return num; //return lowest value
}

int Array::avg()
{
	int num=0;
	for(int i=0;i<=length-1;i++)//loop for array avg value
	{
		num+=array1[i];
	}
	return (num/length); //return value after TotalOfArray/SizeOfArray
}


int Array::nonZero()
{
	int num=0;
	for(int i=0;i<=length-1;i++)//loop for number of nonzero locations in array
	{
		if(array1[i]<0||array1[i]>0)
		{
			num=num+1;
		}
	}
	return (num); //return number of locations
}