//Array Class Main File
//main.cpp
//CS372 Fall 2014
//By John Knowles jknowle2@my.athens.edu
//Date 8/25/2014
//
#include <iostream>
#include "array.h"

using namespace std;

int main()
{
	int total1=0;
	cout << "Test1 array: " << endl;
	Array test1(5);
	test1.setVal(3,12);
	test1.setVal(1,50);
	test1.setVal(4,23);
	test1.setVal(5,32);
	cout << "Value at pos1 is: " << test1.getVal(1) << endl;
	cout << "Value at pos3 is: " << test1.getVal(3) << endl;
	cout << "Value at pos2 is: " << test1.getVal(2) << endl;
	cout << "Value at pos4 is: " << test1.getVal(4) << endl;
	cout << "Value at pos5 is: " << test1.getVal(5) << endl;
	cout << "The lowest value in the array is: " << test1.lowVal() << endl;
	cout << "The highest value in the array is: " << test1.highVal() << endl;
	cout << "The number of nonzero positions is: " << test1.nonZero() << endl;
	cout << "The array avg value is: " << test1.avg() << endl;
	for(int i=1;i<=5;i++)//avg of non zero numbers
	{
		total1+=test1.getVal(i);
	}
	cout << "Average of nonzero number is: " << total1/test1.nonZero() << endl << endl;

	
	int total2=0;
	cout << "Test2 array: " << endl;
	Array test2(20);
	test2.setVal(1,5012);
	test2.setVal(2,34);
	test2.setVal(3,125);
	test2.setVal(4,233);
	test2.setVal(5,5);
	test2.setVal(6,25);
	test2.setVal(9,2345);
	test2.setVal(20,564);
	test2.setVal(15,525);
	test2.setVal(18,35);
	test2.setVal(14,65);
	test2.setVal(12,52);
	cout << "Value at pos1 is: " << test2.getVal(1) << endl;
	cout << "Value at pos4 is: " << test2.getVal(4) << endl;
	cout << "Value at pos6 is: " << test2.getVal(6) << endl;
	cout << "Value at pos8 is: " << test2.getVal(8) << endl;
	cout << "Value at pos9 is: " << test2.getVal(9) << endl;
	cout << "Value at pos13 is: " << test2.getVal(13) << endl;
	cout << "Value at pos15 is: " << test2.getVal(15) << endl;
	cout << "Value at pos17 is: " << test2.getVal(17) << endl;
	cout << "Value at pos20 is: " << test2.getVal(20) << endl;
	cout << "The lowest value in the array is: " << test2.lowVal() << endl;
	cout << "The highest value in the array is: " << test2.highVal() << endl;
	cout << "The number of nonzero positions is: " << test2.nonZero() << endl;
	cout << "The array avg value is: " << test2.avg() << endl;
	for(int i=1;i<=5;i++)//avg of non zero numbers
	{
		total2+=test2.getVal(i);
	}
	cout << "Average of nonzero number is: " << total2/test2.nonZero() << endl << endl;



	int total3=0;
	cout << "Test3 array: " << endl;
	Array test3(8);
	test3.setVal(3,150);
	test3.setVal(1,100);
	test3.setVal(4,223);
	test3.setVal(5,5342);
	test3.setVal(7,51);
	cout << "Value at pos1 is: " << test3.getVal(1) << endl;
	cout << "Value at pos3 is: " << test3.getVal(3) << endl;
	cout << "Value at pos7 is: " << test3.getVal(7) << endl;
	cout << "The lowest value in the array is: " << test3.lowVal() << endl;
	cout << "The highest value in the array is: " << test3.highVal() << endl;
	cout << "The number of nonzero positions is: " << test3.nonZero() << endl;
	cout << "The array avg value is: " << test3.avg() << endl;
	for(int i=1;i<=5;i++) //avg of non zero numbers
	{
		total3+=test3.getVal(i);
	}
	cout << "Average of nonzero number is: " << total3/test3.nonZero() << endl;
	return 0;
}