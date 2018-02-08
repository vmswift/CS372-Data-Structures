//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Name Grade Sort Link List
//Class: CS372 Spring 2015
//Due Date: March 11, 2015
//file: main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;
ifstream infile;
class LList
{
public:
	double grade;
	string student;
	LList *linkGrade;
	LList *linkName;
};

LList *headGrade; //assign as head for sort by grades list
LList *alphaStudent; //assign as head for alphabetically sorted student name list


LList *myNewNode()
{
	LList *t;
	t=new LList;
	t->grade=0;  //int for grades
	t->student=""; //string for student names
	t->linkGrade=NULL; //link for grades
	t->linkName=NULL; //link for names
	return t;
}

void insertName(LList *c,LList *newNode, string name) //handles string from insert function
{
	LList *p,*t;
	p=NULL;
	while(c!=NULL&&c->student<name)
	{
		p=c;
		c=c->linkName;
	}
	t=newNode;//assign node from insert() to t
	t->student=name; //set name to read in value
	t->linkName=c;
	if(p!=NULL)
		p->linkName=t;
	else
		alphaStudent=t; //head is assigned to t
}

void insert(LList *c,LList *d,double val,string name) //standard insert fucntion with int and string support
{
	LList *p,*t;
	p=NULL;
	while(c!=NULL&&c->grade>val)
	{
		p=c;
		c=c->linkGrade;
	}
	t=myNewNode(); //t is assigned to a newnode
	t->grade=val; //set grade to read in value
	t->linkGrade=c;
	insertName(d,t,name); //call insert name to sort/insert names
	if(p!=NULL)
		p->linkGrade=t;
	else
		headGrade=t; //head is assigned to t

}

void printName(LList *c)
{
	cout << "Student:          Grade:" << endl;
	while(c!=NULL)//generic print. Order based on *head LList
	{
		cout << setw(11) << c->student << "        " << c->grade << endl;
		c=c->linkName;
	}
}

void printGrade(LList *c)
{
	cout << "Student:          Grade:" << endl;
	while(c!=NULL)//generic print. Order based on *head LList
	{
		cout << setw(11) << c->student << "        " << c->grade << endl;
		c=c->linkGrade;
	}
}

void printGradesPercent(LList *c,int top)
{
	cout << "Student:         Grade Percentage%" << endl;
	while(c!=NULL) //print name, grade, and percentage grade. Order is based on *head LList
	{
		cout << setw(11) << c->student << "        " << right << setprecision(3) <<(c->grade/top)*100 << "%" << endl;
		c=c->linkGrade;
	}
}

int main()
{
	double grade,MAX;
	grade=0;
	string name;
	infile.open("LinkLnamesAndGrades.txt");
	infile >> MAX;

	while(infile)
	{
		infile >> name;
		infile >> grade;
		insert(headGrade,alphaStudent,grade,name);
	}
	cout << "Print Name and Grades by sort by Grade Highest with Percentage" << endl;
    printGradesPercent(headGrade,MAX);
	cout << endl;
	cout << "Print Name and Grades by sort by Grade Highest" << endl;
	printGrade(headGrade);
	cout << endl;
	cout << "Print Name and Grades by sort by Name Alphabetically" << endl;
	printName(alphaStudent);
	cout << endl;
	infile.close();
	return 0;
}
