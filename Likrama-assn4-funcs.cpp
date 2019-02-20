//******************************************************************************
//	CODE FILENAME:	Likrama-assn4-funcs.h
//	DESCRIPTION:	Prototypes of functions used in sort test program
//	CLASS/TERM:		CS 372 Summer 8 week 1
//	DESIGNER:		Armand Likrama
//	FUNCTIONS:		report - reports the results of the chosen sort type and time for the sorting
//					swap - used to swap elements for sorting purposes
//					bubbleSort - sorts array of numbers using the bubble sort method
//					quicksort - sorts array of numbers using the quick sort method
//					partition - used to partition the array within the quick sort
//					userMenu - displays a list of sorting options to the user, along with an exit option
//					genRandomArray - generates a new random numbered unsorted array
//					getRndNum - generates a random number to be used in the array
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
/* Armand Likrama functions */

//******************************************************************************
//	FUNCTION: swap
//	DESCRIPTION: used to swap elements for sorting arrays.
//	INPUT:
//		Parameters: a, b - a is the first element, b is the second element
//	OUTPUT:
//		pointers to the elements are switched
//******************************************************************************
void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

//******************************************************************************
//	FUNCTION: bubbleSort
//	DESCRIPTION: steps through the array. Then compares adjacent pairs and swaps 
//				 them if they are in the incorrect order.
//	INPUT:
//		Parameters: sortArray - unordered array
//					size - size of the array
//	OUTPUT:
//		Returns the newly sorted array using a bubble sort
//	CALLS TO: swap - to swap pairs
//******************************************************************************
void bubbleSort(int sortArray[], int size){

	int outerLoop = 0;
	int innerLoop = 0;
	for (outerLoop = 0; outerLoop < size; outerLoop++){
		for (innerLoop = 0; innerLoop < size - outerLoop; innerLoop++){
			if (sortArray[innerLoop]>sortArray[innerLoop + 1]){
				//swap the element
				swap(sortArray[innerLoop], sortArray[innerLoop + 1]);
			}

		}
	}
}

//******************************************************************************
//	FUNCTION: quicksort
//	DESCRIPTION: uses a set pivot from the array to divide elments. the pivot is placed
//				 in the correct order of the array. and the new pivot and division continues
//				 using recursion of quicksort
//	INPUT:
//		Parameters: sortArray - unordered array
//					p - first element
//					q - last element
//	OUTPUT:
//		Returns the newly sorted array using a quick sort
//	CALLS TO: partition , quicksort
//******************************************************************************
void quicksort(int  sortArray[], int p, int q)
{

	int r = sortArray[p]; // pivot element
	int splitPoint;
	if (q>p)
	{
		splitPoint = partition(sortArray, r, p, q);
		sortArray[splitPoint] = r;
		quicksort(sortArray, p, splitPoint-1);
		quicksort(sortArray, splitPoint + 1, q);
	}

}

//******************************************************************************
//	FUNCTION: partition
//	DESCRIPTION: steps through the array. Then compares adjacent pairs and swaps 
//				 them if they are in the incorrect order.
//	INPUT:
//		Parameters: sortArray - unordered array
//					p - first element
//					q - last element
//	OUTPUT:
//		Returns the new pivot element
//	CALLS TO: swap - to swap pairs
//******************************************************************************
int partition(int sortArray[], int pivot, int p, int q)
{
	int left = p;  // pivot element
	int right = q; // first element
	
	while(left < right)
	{
		while(pivot < sortArray[right] && right > left){
			right--;
		}
		swap(sortArray[left], sortArray[right]);
		
		while(pivot >= sortArray[left] && left < right){
			left++;
		}
		swap(sortArray[right], sortArray[left]);
	}

	return left;
}

//******************************************************************************
//	FUNCTION: userMenu
//	DESCRIPTION: displays a list of sorting choices to the user, asking for
//				 consecutive character input for 2 choices. The user also
//				 has the option to exit the program instead.
//	INPUT:
//		Parameters: choice1 - first choice character element
//					choice2 - second choice character element
//	OUTPUT:
//		Returns the two character element choices
//******************************************************************************
void userMenu(char &choice1, char &choice2){

	cout << "Choose two sorts you wish to compare:" << endl;
	cout << "\tB = Bubble sort" << endl;
	cout << "\tI = Insertion sort" << endl;
	cout << "\tM = Merge sort" << endl;
	cout << "\tQ = Quick sort" << endl;
	cout << "\tE = Exit program" << endl;
	cout << "\nEnter two letter choices (or EE to exit): ";
	cin >> choice1 >> choice2;

}

//******************************************************************************
//	FUNCTION: getRndNum
//	DESCRIPTION: generates and returns a randomly generaded number
//	INPUT:
//		Parameters: 
//	OUTPUT:
//		Returns the newly randomly generated number
//	CALLS TO: rand - to randomly generate a number
//******************************************************************************
int getRndNum()
{
	int num;
	num = (rand() % NUM_MAX) + 1; 
	//num = (rand() % ((NUM_MAX + NUM_MIN) + 1));
	
	return num;
}


//******************************************************************************
//	FUNCTION: genRandomArray
//	DESCRIPTION: generates randomly chosen numbers to be input into an unsorted 
//				 array. 
//	INPUT:
//		Parameters: randArray - random array
//	OUTPUT:
//		Inputs the random numbers within the array, unsorted.
//	CALLS TO: getRndNum
//******************************************************************************
void genRandomArray(int randArray[])
{
	//int numberCount = 0;   //count of array spaces filled
	int tempNum;    // number returned from GenerateNumber and tested in array
	int i;
	//cout << i;
	
	for(i = 0; i < ARRAY_SIZE; i++)
	{
		tempNum = getRndNum();
		//cout << tempNum << " ";
		randArray[i] = tempNum;
	}
	
}


//******************************************************************************
//	FUNCTION: report
//	DESCRIPTION: reveals the chosen sorted type and the time value alloted through
//				 the sorting of the array.
//	INPUT:
//		Parameters: sortType - sort type chosen by user
//				 	time - clock ticks it took to sort the array
//	OUTPUT:
//	CALLS TO: 
//******************************************************************************
void report(string sortType, int time)
{
	std::cout <<"\t"<< sortType << " time " << time <<"..."<< endl;
}




