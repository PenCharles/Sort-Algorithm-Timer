//*************************************************************************************************
//	FILENAME: SaylorLikrama-assn4-main.cpp
//	DESCRIPTION: asks the user to choose the sort programs and then arranges
//				 arrays into ascending order and checks the arrays for accuracy
//				 the program also displays the amount of time it took for the sort
//				 to sort the array of integers and averages the time based on how
//				 many times the user wants to repeat the sort
//	CLASS/TERM: CS 372 8 week 1
//	DESGINER: James Saylor, Armand Likrama
//	FUNCTIONS:
//		James Saylor	int RepeatEachSort ()
//							this functions asks the user how many times to repeat
//							each sort functions
//		James Saylor	int CalculateTime (int startTime, int endTime)
//							calculates the amount of time that had elapsed since 
//							the sort function began
//		James Saylor	void InsertionSort (int sortArray[])
//							sorts the unordered array into ascending order
//		James Saylor	bool VerifySort (int sortArray [])
//							returns true if newly sorted array is in ascending order
//		James Saylor	void DisplayVerifySort (bool sort1, bool sort2)
//							displauys a message that the array is sorted
//		James Saylor	int DisplayAverage (int* resultArray, int amount)
//							averages the times of a particular sort
//		James Saylor	void DisplayTime (char choice1, char choice2, int startTime, int endTime)
//							displays sort chosen and elapsed time
//		James Saylor	int *ResultArray (int amount)
//							initializes the results array
//		James Saylor	void MergeSort (int sortArray[], int low, int high)
//							arranges the array in ascending order thrugh recursion
//		James Saylor	void Merge (int sortArray[], int low, int middle, int high)
//							sorts the integers in ascending order and returns to 
//							previous function

// 		Armand Likrama	report - reports the results of the chosen sort type and time for the sorting
//		Armand Likrama	swap - used to swap elements for sorting purposes
//		Armand Likrama	bubbleSort - sorts array of numbers using the bubble sort method
//		Armand Likrama  quicksort - sorts array of numbers using the quick sort method
//		Armand Likrama	partition - used to partition the array within the quick sort
//		Armand Likrama	userMenu - displays a list of sorting options to the user, along with an exit option
//		Armand Likrama	genRandomArray - generates a new random numbered unsorted array
//		Armand Likrama	getRndNum - generates a random number to be used in the array
//*****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include "SaylorLikrama-assn4-common.h"	//Global Constants
#include "Saylor-assn4-functions.h"		//Saylor function
#include "Likrama-assn4-funcs.h"	//Likrama function


using namespace std;
int main (){
	


	int* randArray;
	int* Sort1;
	int* Sort2;
	double* sortTimesArray1;
	double* sortTimesArray2;
	int low = 0;
	int high = 99999;
	double startTime, endTime, elapsedTime;
	double averageTimeSort1 = 0;
	double averageTimeSort2 = 0;
	char choice1=' ';
	char choice2=' ';
	int numberTimes = 0;
	bool sortWorks1;
	bool sortWorks2;
	string sortType = "";
	string sortType1 = "";
	int i = 0;
	
	do
	{
		srand( time(NULL) );
		void (*simpleInsertion) (int[]) = NULL;
		void (*simpleBubble) (int[], int) = NULL;
		void (*complexMerge) (int[], int, int) = NULL; 
		void (*complexQuick) (int[], int, int) = NULL;
		simpleInsertion = InsertionSort;
		simpleBubble = bubbleSort;
		complexQuick = quicksort;
		complexMerge = MergeSort;
		Sort1 = new (nothrow) int [ARRAY_SIZE];
		Sort2 = new (nothrow) int [ARRAY_SIZE];
		randArray = new (nothrow) int [ARRAY_SIZE];
	 	
		
			//Ask for two choice of sorting algo
			userMenu(choice1, choice2);
			if ((choice1 == 'E' && choice2 == 'E') || (choice1 == 'e' && choice2 == 'e')){
				return 0;
			}
			//generate ranarray
	
			numberTimes = RepeatEachSort ();
			//sortTimesArray1 = ResultArray (numberTimes);
			//sortTimesArray2 = ResultArray (numberTimes);
			sortTimesArray1 = new (nothrow) double [numberTimes];
			sortTimesArray2 = new (nothrow) double [numberTimes];
			
				//Generate array of 100000 random numbers between 1 and 30000
			
	
	
			for (int cycle = 0; cycle < numberTimes; cycle++){
				// Perform action here that you want to time
					//to make both array element unique
					genRandomArray(randArray);
	
	
				for (i = 0; i < ARRAY_SIZE; i++){
					Sort1[i] = randArray[i];
					//cout << Sort1[i] << " ";
					//Sort2[i] = Sort1[i];
					//cout << Sort2[i] << " ";
				}
	
				//second array
	
				for (i = 0; i <  ARRAY_SIZE; i++){
					Sort2[i] = randArray[i];
					//cout << Sort2[i] << " ";
				}
	
			
				cout << "Starting sort #" << (cycle + 1) << "." << endl;
				{
					if (choice1 != 'E'){
						startTime = clock();
						//cout << startTime << endl;
						switch (toupper(choice1)){
						case 'B':
							sortType = "Bubble Sort";
							(*simpleBubble) (Sort1, ARRAY_SIZE);
							//bubbleSort(Sort1, ARRAY_SIZE);
							break;
							
						case 'M':
							sortType = "Merge Sort";
							(*complexMerge) (Sort1, low, high);
							break;
	
						case 'Q':
							sortType = "Quick Sort";
							(*complexQuick) (Sort1, 0, ARRAY_SIZE);
							//quicksort(Sort1, 0, ARRAY_SIZE);
							break;
							
						case 'I':
							sortType = "Insertion Sort";
							(*simpleInsertion) (Sort1);
							break;
	
						case 'E':
							break;
	
						default:
							break;
						}
	
						endTime = clock();
						//cout << endTime << endl;
						elapsedTime = CalculateTime (startTime, endTime);
						//cout << elapsedTime;
						sortTimesArray1[cycle] = elapsedTime;
						report(sortType, elapsedTime);
						sortWorks1 = VerifySort (Sort1);
						//averageTimeSort1 += elapsedTime;
					}
				}
	
	
	
				
					if (choice2 != 'E'){
	
						startTime = clock();
						switch (toupper(choice2)){
						case 'B':
							sortType1 = "Bubble Sort";
							(*simpleBubble) (Sort2, ARRAY_SIZE);
							//bubbleSort(Sort2, ARRAY_SIZE);
							break;
						case 'M':
							sortType1 = "Merge Sort";
							(*complexMerge) (Sort2, low, high);
							break;
	
						case 'Q':
							sortType1 = "Quick Sort";
							(*complexQuick) (Sort2, 0, ARRAY_SIZE);
							//quicksort(Sort2, 0, ARRAY_SIZE);
							break;
							
						case 'I':
							sortType1 = "Insertion Sort";
							(*simpleInsertion) (Sort2);
							break;
	
						case 'E':
							break;
	
						default:
							break;
						}
						endTime = clock();
						//elapsedTime = endTime - startTime;
						elapsedTime = CalculateTime (startTime, endTime);
						//averageTimeSort2 += elapsedTime;
						sortTimesArray2[cycle] = elapsedTime;
						sortWorks2 = VerifySort (Sort2);
						report(sortType1, elapsedTime);
						DisplayVerifySort (sortWorks1, sortWorks2);
					}
				
	
				//if (vaildArray(Sort1,Sort2, ARRAY_SIZE) == true){
				//		cout << "\tSorts validated" << endl;
					}
				
			
			cout << endl;
			//averageTimeSort1 = (averageTimeSort1 / numberTimes);
			//averageTimeSort2 = (averageTimeSort2 / numberTimes);
			
			cout << "SORTING RESULTS" << endl;
			cout << "---------------" << endl;
			averageTimeSort1 = DisplayAverage (sortTimesArray1, numberTimes);
			averageTimeSort2 = DisplayAverage (sortTimesArray2, numberTimes);
			cout << "\t" << std::right<< sortType << setw(13) << (averageTimeSort1 ) << " clock ticks on average" << endl;
			cout << "\t" << std::right<<sortType1 << setw(13) <<  (averageTimeSort2 ) << " clock ticks on average" << endl;
	
			
			
		delete [] sortTimesArray1;
		delete [] sortTimesArray2;
		delete [] Sort1;
		delete [] Sort2;
		delete [] randArray;
		
		system("pause");
		
	} while ((choice1 != 'E' && choice2 != 'E') || (choice1 != 'e' && choice2 != 'e'));
			
	//Print the report

	//User chooses table size for tests and initial hash method
	cout << endl << endl;
	return 0;
}
