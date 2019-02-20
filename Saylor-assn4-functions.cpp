//******************************************************************************
//	CODE FILENAME:	Saylor-assn4-funcs.h
//	DESCRIPTION:	Prototypes of functions used in sort test program
//	CLASS/TERM:		CS 372 Summer 8 week 1
//	DESIGNER:		James Saylor
//	FUNCTIONS:		RepeatEachSort - asks the user for amount of sort repeats
//					CalculateTime - calculates the time that has elapsed during sort
//					InsertionSort - sorts array of nums using insertion sort method
//					VerifySort - checks each element in the array to verify sort success
//					DisplayVerifySort - displays to user that both sorts worked
//					DisplayAverage - figures and displays average sort time 
//					DisplayTime - displays the time for each sort
//					*ResultArray - decalres and intializes results array
//					MergeSort - help sort an array through recursion
//					Merge - swaps elements until array is in order
//******************************************************************************




#include "SaylorLikrama-assn4-common.h"	//Global Constants
#include "Saylor-assn4-functions.h"		//Saylor function
#include "Likrama-assn4-funcs.h"	//Likrama function
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>


using namespace std;
//******************************************************************************
//	FUNCTION: RepeatEachSort
//	DESCRIPTION: prompts the user for an amount of times to run each sort, checks
//				 the amount to make sure it is correct and returns the amount
//	OUTPUT: 
//		Return Val: amount - the number of times to repeat each sort
//******************************************************************************
int RepeatEachSort ()
{
	int amount = 0;
	
	while (amount < 1)
	{
		cout << " How many times would like to run each sorting method." << endl;
		cin >> amount;
		cout << endl;
	
		if (amount < 1)
		{
			cout << " Error. Please enter a number that is higher than 1." << endl << endl;
		}
	}
	return amount;
}

//******************************************************************************
//	FUNCTION: CalculateTime
//	DESCRIPTION: calculates the time that has elapsed during the sort function
//	INPUT:
//		Paramters: startTime - the time that the sort function began executing
//				   endTime - the time that the sort function ends its execution
//	OUTPUT:
//		Return Val: result - the time that has elapsed during sort execution
//******************************************************************************
double CalculateTime (double startTime, double endTime)
{
	double result;
	
	result = endTime - startTime;
	
	return result;
}

//******************************************************************************
//	FUNCTION: InsertionSort
//	DESCRIPTION: sorts an array of integers into ascending order
//	INPUT:
//		Parameters: sortArray[] - an array of unsorted numbes
//******************************************************************************
void InsertionSort (int sortArray[])
{
	int remainTopIdx = 1;
	int lastIdx = ARRAY_SIZE - 1;
	int insertValue;
	int currentIdx;

	while (remainTopIdx <= lastIdx)
	{
		insertValue = sortArray[remainTopIdx];
		//cout << insertValue << " ";
		currentIdx = remainTopIdx - 1;
		
		while ((currentIdx >= 0) && (insertValue < sortArray[currentIdx]))
		{
			sortArray[currentIdx + 1] = sortArray[currentIdx];
			currentIdx--;
		}
		sortArray[currentIdx + 1] = insertValue;
		remainTopIdx++;
	}
	/*	for (int i = 0; i < ARRAY_SIZE; i++){
		cout << sortArray[i] << " ";
		}*/
	
}

//******************************************************************************
//	FUNCTION: VerifySort
//	DESCRIPTION: verifies that the array was sorted in ascending order
//	INPUT:
//		Paramters: sortArray[] - an array of sorted numbers
//	OUTPUT:
//		Return Val: true - if the array is sorted in ascending order
//					false - if the array is not sorted
//******************************************************************************
bool VerifySort (int sortArray[])
{
	int index = 0;
	bool sorted = true;
	
	while (index < ARRAY_SIZE - 1 && sorted)
	{
		if (sortArray [index + 1] >= sortArray [index])
		{
			//cout << sortArray[index] << " ";
			index++;
		}
		else
		{
			sorted = false;
		}
	}
	return sorted;
}
//******************************************************************************
//	FUNCTION: DisplayVerifySort
//	DESCRIPTION: if the sort functions worked then this will display a succesfull
//				 message
//	INPUT:
//		Parameters: sort1 - the outcome of the first sort choice
//					sort2 - the outcome of the second sort choice
//	OUTPUT:
//		Return Val: validSort - holds true if both sorts worked and false if one 
//								of the sorts did not work
//******************************************************************************
void DisplayVerifySort (bool sort1, bool sort2)
{
	bool validSort;
	
	if (sort1 && sort2)
	{
		cout << " Sorts Validated" << endl;
		//validSort = true;
	}
	else
	{
		if(!sort1)
		{
			cout << " The first sort choice is invalid!!" << endl;
		}
		else if(!sort2)
		{
			cout << " The second sort choice is invalid!!" << endl;
		}
		//validSort = false;
	}
	
}

//******************************************************************************
//	FUNCTION: DisplayAvergae
//	DESCRIPTION: displays the average amount of for a sort function to execute
//	INPUT:
//		Parameters: *resultArray - holds the values to average
//					 amount - holds the size of the array
//	OUTPUT:
//		Return Val: average - average amount of time to run the sort
//******************************************************************************
double DisplayAverage (double resultArray[], int amount)
{
	int total = 0;
	int average = 0;
	
	for (int i = 0; i <= amount; i++)
	{
		total = total + resultArray[i];
	}
	
	average = total / amount;
	
	return average;
}

//******************************************************************************
//	FUNCTION: DisplayTime
//	DESCRIPTION: displays the amount of time it took for each sort to run
//	INPUT:
//		Paramters: choice1 - users choice of sort
//				   choice2 - users 2nd choice of sort
//				   startTime - the time the sort began execution
//				   endTime - the time the sort stopped execution
//******************************************************************************
/*void DisplayTime (char choice1, char choice2, int startTime, int endTime)
{
	int elapsedTime;
	
	if (choice1 == 'B' || choice2 == 'B')
	{
		cout << " Bubble Sort time "; 
	}
	else if (choice1 == 'I' || choice2 == 'I')
	{
		cout << " Insertion Sort time ";
	}
	else if (choice1 == 'M' || choice2 == 'M')
	{
		cout << " Merge Sort time ";
	}
	else if (choice1 == 'Q' || choice2 == 'Q')
	{
		cout << " Quick Sort time ";
	}
	
	elapsedTime = CalculateTime(startTime, endTime);
	cout << endl;
	
}
*/
//******************************************************************************
//	FUNCTION: ResultArray
//	DESCRIPTION: initializes and declares an array
//	INPUT:
//		Parameters: amount - size of the array
//	OUTPUT:
//		Return Val: resultArray - a pointer to the array
//******************************************************************************
int *ResultArray (int amount)
{
	int* resultArray;
	
	resultArray = new (nothrow) int[amount];
	
/*	if (resultArray[0] == NULL)
	{
		cout << " Could not allocate memory";
	}
	*/
	
	return resultArray;
}

//******************************************************************************
//	FUNCTION: MergeSort
//	DESCRIPTION: call its ownself over and over and inorder to split the array 
//				 down to one element and then begins returning the elements
//				 and calling merge to sort and combing the integers
//	INPUT:
//		Parameters: sortArray[] - unordered array
//					low - top most element address in the array being halved
//					high - last element address in the array being halved
//	OUTPUT:
//		Return Val: low - the last element left in the array
//	CALLS TO: merge
//******************************************************************************
void MergeSort (int sortArray[], int low, int high)
{
	int middle;
		/*	for (int i = 0; i < ARRAY_SIZE - 1; i++){
		cout << sortArray[i] << " ";
		}*/
	//if (low >= high)
/*	{
		return low;
	}*/
	if (low < high)
	{
		middle = (low + high) / 2;
		MergeSort (sortArray, low, middle);
		MergeSort (sortArray, middle + 1, high);
		Merge (sortArray, low, middle, high);
	}
}

//******************************************************************************
//	FUNCTION: Merge
//	DESCRIPTION: sorts the elements in the array 
//	INPUT:
//		Parameters: sortArray[] - ordered array of integers
//		low - top most element in the array
//		middle - mid index address in the array
//		high - last index in the array
//******************************************************************************
void Merge (int sortArray[], int low, int middle, int high)
{
	static int tempArray[ARRAY_SIZE];//create tempArray same size as list
	int leftIdx;
	int rightIdx;
	int tempPos;
	
	for (int i = 0; i < middle; i++)
	{
		tempArray[i] = sortArray[i];
	}
	leftIdx = low;
	rightIdx = middle + 1;
	tempPos = low;
	
	while ((leftIdx <= middle) && (rightIdx <= high))
	{
		if (tempArray[leftIdx] <= tempArray[rightIdx])
		{
			sortArray[tempPos] = tempArray[leftIdx];
			leftIdx++;
		}
		else
		{
			sortArray[tempPos] = tempArray[rightIdx];
			rightIdx++;
		}
		tempPos++;
	}
	while (leftIdx <= middle)
	{
		sortArray[tempPos] = tempArray[leftIdx];
		tempPos++;
		leftIdx++;
	}
	while (rightIdx <= high)
	{
		sortArray[tempPos] = tempArray[rightIdx];
		tempPos++;
		rightIdx++;
	}
}
