//Throttle Class Main
//main.cpp
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 8/25/2014
//
#include <iostream>
#include "throttle.h"
using namespace std;

int main()
{
	cout << "Test 1: " << endl;
	throttle test1(5);
	cout << "Flow is: " << test1.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test1.is_on() << endl;
	cout << endl;
	test1.shift(3);
	cout << "Flow is: " << test1.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test1.is_on() << endl;
	test1.shift(5);
	cout << endl;
	cout << "Flow is: " << test1.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test1.is_on() << endl;
	cout << endl;

	cout << "Test 2: " << endl;
	throttle test2(10);
	cout << "Flow is: " << test2.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test2.is_on() << endl;
	cout << endl;
	test2.shift(9);
	cout << "Flow is: " << test2.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test2.is_on() << endl;
	test2.shift(4);
	cout << endl;
	cout << "Flow is: " << test2.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test2.is_on() << endl;
	cout << endl;
	test2.shift(7);
	cout << "Flow is: " << test2.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test2.is_on() << endl;
	cout << endl;
	
	cout << "Test 3: " << endl;
	throttle test3(15);
	cout << "Flow is: " << test3.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test3.is_on() << endl;
	cout << endl;
	test3.shift(15);
	cout << "Flow is: " << test3.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test3.is_on() << endl;
	test3.shift(1);
	cout << endl;
	cout << "Flow is: " << test3.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test3.is_on() << endl;
	cout << endl;
	test3.shift(5);
	cout << "Flow is: " << test3.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test3.is_on() << endl;
	cout << endl;
	test3.shift(20); //out of bounds test should end up max position
	cout << "Flow is: " << test3.flow() << endl;
	cout << "Throttle is on 0 no 1 yes: " <<test3.is_on() << endl;
	cout << endl;
	return 0;
}