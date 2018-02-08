//Throttle Overload Class Main
//main.cpp
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 9/8/2014
//
#include <iostream>
#include "throttle.h"
using namespace std;


int main()
{
	throttle car(20,5); //car class
	throttle truck;     //truck class
	throttle dumptruck(15); //dumptruck class


	cout << "For bool logic 1 means yes and 0 means no" << endl;
	cout << endl;

	//equal comparison tests
	cout << "Is car equal to car?:  " << car.operator==(car) << endl; //nasty syntax
	bool num = false; //variable for use with bool logic overload operators
	num = car==car;//nice syntax
	cout << "Is car equal to car?: " << num << endl;
	num = car==truck;//nice syntax
	cout << "Is car equal to truck?: " << num << endl;
	num = car==dumptruck;//nice syntax
	cout << "Is car equal to dumptruck?: " << num << endl;
	num = truck==dumptruck;//nice syntax
	cout << "Is truck equal to dumptruck?: " << num << endl;

	cout << endl;
	//is not equal comparison tests
	num=car.operator!=(car); //nasty syntax
	cout <<"Car is not equal to car?: " << num << endl;
	num = car!=car; //nice syntax
	cout <<"Car is not equal to car?: " << num << endl;
	num = car!=truck; //nice syntax
	cout <<"Car is not equal to truck?: " << num << endl;
	num = car!=dumptruck; //nice syntax
	cout <<"Car is not equal to dumptruck?: " << num << endl;
	num = truck!=dumptruck; //nice syntax
	cout <<"Truck is not equal to dumptruck?: " << num << endl;

	cout << endl;
	cout << "Values for car are: " << car << endl;
	cout << "Values for truck are: " << truck << endl;
	cout << "Values for dumptruck are: " << dumptruck << endl;

	cout << endl;
	//position shifts the reprint cout for each class
	car.shift(10);
	truck.shift(4);
	dumptruck.shift(13);
	cout << "Class values after throttle shift: " << endl;
	cout << "Values for car are: " << car << endl;
	cout << "Values for truck are: " << truck << endl;
	cout << "Values for dumptruck are: " << dumptruck << endl;
	return 0;
}