//Written by: John Knowles (jknowle2@my.athens.edu)
//Assignment: Sorts Search
//Class: CS372 Spring 2015
//Due Date: April 15, 2015
//file: main.cpp
#include <iostream>
#include <cstdlib>

using namespace std;
size_t COUNT;//counter for swaps and probes

void bubbleSort(size_t arr[], size_t n)
{//bubble sort
      bool swapped = true;
	  size_t j = 0;
	  size_t tmp;
      while (swapped)
	  {
            swapped = false;
            j++;
            for (size_t i = 0; i < n - j; i++)
			{
                  if (arr[i] > arr[i + 1])
				  {
                        tmp = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = tmp;
                        swapped = true;
						COUNT++;
                  }
            }
      }
}

void selectionSort(size_t arr[], size_t n)
{//selection sort
      size_t i, j, minIndex, tmp;
      for (i = 0; i < n - 1; i++)
	  {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i)
			{
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
				  COUNT++;//counter for number of swaps
            }
      }
}

void quickSort(size_t arr[], size_t left, size_t right)
{//quick sort
      size_t i = left, j = right;
      size_t tmp;
      size_t pivot = arr[(left + right) / 2];

      while (i <= j)
	  {
            while (arr[i] < pivot)
			{
                  i++;
			}
            while (arr[j] > pivot)
			{
                  j--;
			}
            if (i <= j)
			{
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
				  COUNT++; //counter for number of swaps
            }
      };
      if (left < j)
            quickSort(arr, left, j);
      if (i < right)
            quickSort(arr, i, right);
}

bool lsearch(size_t Arr[], size_t s, size_t VAL)
{//linear search
	COUNT=0;//counter reset to zero
	for(size_t i=0; i<s; i++)
	{
		if(Arr[i]==VAL)
			return true;
		COUNT++;//counter for probes
	}
	return false;
}

int binarysearch(size_t arr[], size_t value, int left, int right)
{//binary search
		COUNT=0;//counter reset to zero
      while (left <= right)
	  {
            int middle = (left + right) / 2;
			COUNT++;//counter for probes
            if (arr[middle] == value)
			{
                  return middle;
			}
            else if (arr[middle] > value)
			{
                  right = middle - 1;
			}
            else
			{
                  left = middle + 1;
			}
      }
      return -1;
}

void print(size_t arr[])
{//print middle 100 of 10000
	size_t i=4950;
	while(i<5050)
	{
		cout << arr[i] << " ";
		i++;
	}
	cout << endl;
}

void copyAry(size_t arr1[], size_t arr2[],size_t n)
{//copy one array to another
	for(size_t i=0;i<n;i++)
	{
		arr2[i]=arr1[i];
	}
}
int main()
{
	COUNT=0;
	const size_t N=10000;
	size_t array[N];
	size_t array2[N];
	for(size_t i=0;i<N;i++)
	{
		array[i]=rand()%200000+1;
	}
	copyAry(array,array2,N);//copy array for first time
	cout << "Original Array middle 100" << endl;
	print(array2);//print array middle 100
	cout << endl;

	bubbleSort(array2,N);
	cout << "BubbleSort Array middle 100" << endl;
	print(array2);//print array middle 100
	cout << "BubbleSort swaps made is " << COUNT << endl << endl;
	copyAry(array,array2,N);//copy original array over
	COUNT=0;//reset counter for swaps

	selectionSort(array2,N);
	cout << "Selectionsort Array middle 100" << endl;
	print(array2);//print array middle 100
	cout << "SelectionSort swaps made is " << COUNT << endl << endl;
	copyAry(array,array2,N);//copy original array over
	COUNT=0;//reset counter for swaps

	quickSort(array2,0,N-1);
	cout << "QuickSort Array middle 100" << endl;
	print(array2);//print array middle 100
	cout << "QuickSort swaps made is " << COUNT << endl << endl;
	COUNT=0;//reset counter for swaps

	size_t SUM=0;//total number of probes made
	for(size_t i=0;i<1000;i++)
	{
		size_t num=rand()%200000+1;//random number between 1 and 200000
		lsearch(array2,N,num);//linear search
		SUM=SUM+COUNT; //add up total probes from the 1000 number searches
	}

	cout << "Average number of probes of a linear search is " << SUM/1000 << endl;
	cout << "Theoretical number of probes in a 10k location array linear search is about 10000 probes" << endl << endl;
	//linear search has a big(O) of N times. so if the array is 10000 long then the search worst case is 10000 probes
	//This is the worst possible scenario if the desired value is at the end of the array
	SUM=0;//reset sum to 0

	for(size_t i=0;i<1000;i++)
	{
		size_t num=rand()%200000+1;//random number between 1 and 200000
		binarysearch(array2,num,0,9999);//binary search
		SUM=SUM+COUNT;//add up total probes from the 1000 number searches
	}
	cout << "Average number of probes of a binary search is " << SUM/1000 << endl;
	cout << "Theoretical number of probes in a 10k location array binary search is about 13.28 probes" << endl << endl;
	//Binary Search has a big(O) of log base 2(n) which comes out as log base 2(10000) with an answer of 13.287712
	return 0;
}
