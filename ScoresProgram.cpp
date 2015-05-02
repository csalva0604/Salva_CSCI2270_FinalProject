//Christine Salva
//Professor Hoenigman
//Final Project
//May, 2015

#include <iostream>
#include "FinalProject.h"
#include <string>
#include <iomanip>
using namespace std;

//constructor (don't know if I should use this/what to put in it)
Scores::Scores()
{
}

bool Scores::checkGymnastExists(Gymnast arr[], int gymnastNumber, int counter)
{
	for (int i = 0; i < counter; i++) {

		if (arr[i].gymnastNumber == gymnastNumber)
			return true;
	}

	return false;
}

void Scores::printRemaining(Gymnast arr[], int counter)
{
	cout << "These gymnasts have not been disqualified" << endl;
	cout << "---------------------------" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << arr[i].gymnastNumber << endl;

	}
}

/*
 Function prototype: Gymnast* Scores::storeArray((int gymnastNumber, double score, string event, Gymnast arr[], int size, Gymnast arr2[], int counter, string teamName)
 
 Function Description: This method takes the size of the array, the amount of objects in the array,a "temp" array for memory allocation, and the information from the file and stores the gymnast's number, score, the event the gymnast competed, and the team the gymnast is on and stores them in the array. It also dynamically allocates memory and doubles the array when needed, then returns the array.
 
 Example: 
 Scores ScoreInstance;
 Gymnast ScoresArray = ScoreInstance.storeArray(12, 9.6, balance beam, ScoresArray, 40, tempArray, 31, West);
 
 Precondition: Before first time running, the array is empty. The method must be passed an integer, a double, a string, an array of type "Gymnast", and integer, another array of type "Gymnast", an integer, and a string in that order. The team names passed in to be stored must be either "West", "East", "North", or "South" in order for later functions to work.
 Postconditions: The ScoresArray will have the gymnasts' information stored in it, and depending on the amount of gymnasts, its size will be doubled.  
  */
Gymnast* Scores::storeArray(int gymnastNumber, double score, string event, Gymnast arr[], int size, Gymnast arr2[], int counter, string teamName)
{
	//if the counter of the items stored and the size of the array are the same, the array must be doubled using dymnamic memory allocation
	if(counter == size)
	{
		
		arr2 = new Gymnast[size * 2];
		for(int i = 0; i < size; i++)
		{
			arr2[i].gymnastNumber = arr[i].gymnastNumber;
			arr2[i].score = arr[i].score;
			arr2[i].event = arr[i].event;
			arr2[i].teamName = arr[i].teamName;
		}

		delete[] arr;
		arr = arr2;
	}
	//store information in array
	arr[counter].gymnastNumber = gymnastNumber;
	arr[counter].score = score;
	arr[counter].event = event;
	arr[counter].teamName = teamName;
	return arr;
}

/*
 Function prototype: bool Scores::findEvent(string event, int gymnastNumber, Gymnast arr[], int count, int index)
 
 Function Description: This method takes the gymnast's number, the event the user wants to get the information about, the main ScoresArray with all the gymnast information, the amount of items in that array, and the index of the gymnast we are looking at. It will return false if the gymnast's event does not match the one inputed and will return true if it does. 
 
 Example: 
 Scores ScoreInstance;
 bool correctEvent;
 correctEvent = ScoreInstance.findEvent(balance beam, 11, ScoresArray, 31, 4);
 
 Precondition: The method must be passed a string that matches either "balance beam", "uneven bars", "vault", or "floor exercise", an integer, an array of type Gymnast, an integer, and an integer in that order to work. The array must not be empty. 
 PostCondition: The method will change the outcome of the printTopThree function(where it is called), It will return false if the gymnast's event does not match the one inputed and will return true if it does. 
 */
bool Scores::findEvent(string event, int gymnastNumber, Gymnast arr[], int count, int index)
{
	//set bool variable to false
	bool correctEvent = false;
	
		//if the gymnast's number stored in the passed in index matches the gymnast number passed in
		if(arr[index].gymnastNumber == gymnastNumber)
		{
			//if the indexed gymnast competed the event the user wants to find the top scores for
			if(arr[index].event == " "+event)
			{
				//return true
				return true;
			}
			
		}
	
	//return false if the gymnast did not compete that event
	return correctEvent;
}

/*
 Function Prototype: void Scores::printTopThree(string event, Gymnast arr[], int count)
 
 Function Description: This method will take in the event the user wants to print the top three scores for, the array with all of the gymnasts' information in it, and the amount of items in the array and will print out the gymnasts' numbers with the top three scores and their scores for the event the user wants to find the results for. 
 
 Example:
 Scores ScoreInstance;
 ScoreInstance.printTopThree(balance beam, ScoresArray, 31);
 **output**: Event: balance beam
			 First place is gymnast number 2 with a score of 9.7
		     Second place is gymnast number 5 with a score of 9.5
		     Third place is gymnast number 10 with a score of 9.0

 Preconditions: This method needs the findEvent function in order to work. It needs to be passed a string ("balance beam", "uneven bars", "vault", or "floor exercise"), an array of type Gymnast, and an integer in that order in order to work. The array also must not be empty.
 Postconditions: The program will output the top three scores for the specified event and the gymnasts who earned them.
 */
void Scores::printTopThree(string event, Gymnast arr[], int count)
{
	//print event the user wants to find the top three scores for
	cout<<"Event: "<<event<<endl;
	//create variables to store information
	double topScore = 0;
	double secondTopScore = 0;
	double thirdTopScore = 0;
	int firstPlaceGymnast;
	int secondPlaceGymnast;
	int thirdPlaceGymnast;
	//sort the array to make it easier to find top scores
	sortArray(arr, count);
	//loop through array
	for(int i = 0; i < count; i++)
	{
		//if the gymnast did compete the event the user wants to find the top scores for, the last one is the top score due to sorting
		if(findEvent(event, arr[i].gymnastNumber, arr, count, i) == true)
		{
			topScore = arr[i].score;
			firstPlaceGymnast = arr[i].gymnastNumber;
		}
	}
	//print top score
	cout<<"First place is gymnast number "<<firstPlaceGymnast<<" with a score of "<<topScore<<endl;
	//loop  through to find second place
	for(int j = 0; j<count; j++)
	{
		if(findEvent(event, arr[j].gymnastNumber, arr, count, j) == true)
		{
			if(arr[j].score < topScore)
			{
				secondTopScore = arr[j].score;
				secondPlaceGymnast = arr[j].gymnastNumber;
			}
		}
	}
	cout<<"Second place is gymnast number "<<secondPlaceGymnast<<" with a score of "<<secondTopScore<<endl;
	//loop through to find third place
	for(int k = 0; k < count; k++)
	{
		if(findEvent(event, arr[k].gymnastNumber, arr, count, k) == true)
		{
			if(arr[k].score < secondTopScore)
			{
				thirdTopScore = arr[k].score;
				thirdPlaceGymnast = arr[k].gymnastNumber;
			}
		}
	}
	cout<<"Third palce is gymnast number "<<thirdPlaceGymnast<<" with a score of "<<thirdTopScore<<endl;
}
//got this implementation from online lecture notes
/*
 Function Prototype: void Scores::sortArray(Gymnast arr[], int count)
 
 Function Description: This method takes in the array with all of the gymnasts' information and the amount of items in that array and sorts the array in order using bubble sort and the scores the gymnasts received.
 
 Example:
 Scores ScoreInstance;
 Gymnast array1[4];
 array1 = ScoreInstance.sortArray(array1, 4);
 
 Preconditions: The method needs to be passed an array of type Gymnast and an int in that order to work. The array passed in must not be empty. 
 Postconditions: The array passed in will be in order after the method is run. 
 */
void Scores::sortArray(Gymnast arr[], int count)
{
	//create variable to temporarily store information
	Gymnast swap;
	//loop through and sort the array in order based on scores
    for(int c = 0; c < count-1; c++){
        for(int d = 0; d < count-c-1; d++){
            if(arr[d].score > arr[d+1].score){
                swap = arr[d];
                arr[d] = arr[d+1];
                arr[d+1] = swap;
            }
        }
    }
}
//got implementation from assignment1 and friends I collaborated with on that assignment
/*
 Function Prototype: Gymnast* Scores::shiftArray(Gymnast arr[], int index, int count)
 
 Function Description: This method will take in the array that stores all of the gymnasts' information, the index who's information will be deleted, and the amount of items in the array and will delete the item that the user wants to delete by shifting the array to the left. It will then return the array.
 
 Example:
 Scores ScoreInstance;
 Gymnast ScoresArray[20];
 ScoresArray = shiftArray(ScoresArray, 4, 20);
 
 Preconditions: The method must be passed an array of type Gymnast, an integer, and an integer in that order to work. The array must not be empty. 
 Postconditions: The item the user wants to delete will be deleted, and the array will be shifted over to the left.
 */
Gymnast* Scores::shiftArray(Gymnast arr[], int index, int count)
{
	//loop through array and shift
	for(int j = index; j< count; j++)
    {
		
        //create object for item in next index 
        Gymnast nextGymnast = arr[j+1];
        
			//shift over
            arr[j] = nextGymnast;
        }
        return arr;
 
}

/*
 Function Prototype: Gymnast* Scores::deleteGymnast(Gymnast arr[], int gymnastNumber, int count)
 
 Function Description: The function takes in the array with all of the gymnasts' information, the gymnastNumber(representing the gymnast's information the user wants to delete from the array), and the amount of items in the array and removes that gymnast by calling the shift function. It then returns the array.
 
 Example:
 Scores ScoreInstance;
 Gymnast ScoresArray[40];
 ScoresArray = ScoreInstance.deleteGymnast(ScoresArray, 3, 40);
 
 Preconditions: The method must be passed an array of type Gymnast, an integer, and an integer in that order to work. The array must not be empty. The shiftArray function must be called in this function to work.
 Postconditions: The gymnast the user wants to remove from the array will be removed along with her information, and the array will be shifted to the left.
 */
Gymnast* Scores::deleteGymnast(Gymnast arr[], int gymnastNumber, int count)
{
	//loop through array, if the gymnast matches the gymnast the user wants to delete from the array, shift over the array
	for(int i = 0; i < count; i++)
	{
		if(arr[i].gymnastNumber == gymnastNumber)
		{
			shiftArray(arr, i, count);
		}
	}
	return arr;
}

/*
 Function Prototype: void Scores::findGymnast(Gymnast arr[], int gymnastNumber, int count)
 
 Function Description: This method takes in the array with all of the gymnasts' information, the gymnast's number the user wants to find the information for, and the amount of items in the array and prints the event the gymnast competed and her score.
 
 Example:
 Scores ScoreInstance;
 ScoreInstance.findGymnast(ScoresArray, 4, 40);
 **output**: Event: balance beam
			 Score: 9.4
 
 Preconditions: The method must be passed an array of type Gymnast, an integer, and an integer in that order to work. The array must not be empty. 
 Postconditions: The program will output the event the gymnast competed and her score.
 */
void Scores::findGymnast(Gymnast arr[], int gymnastNumber, int count)
{
	//loop through the array, if the gymnast matches the gymnast the user wants to find the score for, print the event competed and her score
	for(int i = 0; i < count; i++)
	{
		if(arr[i].gymnastNumber == gymnastNumber)
		{
			cout<<"Event:"<<arr[i].event<<endl;
			cout<<"Score: "<<arr[i].score<<endl;
		}
	}
}

/*
 Function Prototype: void Scores::totalDeductions(Gymnast arr[], int count, int gymnastNumber)
 
 Function Description: This method takes in the array with all of the gymnasts' information, the amount of items in the array, and the gymnast's number that represents the gymnast who the user wants to find the total deductions for for her rountine. It then prints the total deductions the gymnast received for her routine.
 
 Example:
 Scores ScoreInstance;
 ScoreInstance.totalDeductions(ScoresArray, 31, 20);
 **output**: Gymnast number 31 had 2.5 point(s) worth of deductions for her uneven bars routine.
 
 Preconditions: This method needs to be passed an array of type Gymnast, an integer, and an integer in that order to work. The array must not be empty. 
 Postconditions: The function will print the gymnast's total amount of deductions for her routine.
 */
void Scores::totalDeductions(Gymnast arr[], int count, int gymnastNumber)
{
	//create variable to store deductions
	double deductions;
	//loop through array, if the gymnast matches the gymnast the user wants to find the deductions for, print her total deductions
	for(int i = 0; i < count; i++)
	{
		if(arr[i].gymnastNumber == gymnastNumber)
		{
			//subtract from 10.0(the highest score someone can receive) the score the gymnast received
			deductions = 10 - arr[i].score;
			cout<<"Gymnast number "<<gymnastNumber<<" had "<<deductions<<" point(s) worth of deductions for her"<<arr[i].event<<" routine."<<endl;
		}
	}
}

/*
 Function Prototype: void Scores::printTeamTotal(Gymnast arr[], int count)
 
 Function Description: This method takes in the array with all of the gymnasts' information and the amount of items in the array, searches the array for girls on certain teams, and prints all of the teams' total score.
 
 Example:
 Scores ScoreInstance;
 ScoreInstance.printTeamTotal(ScoresArray, 31);
 **output**: Team West Score: 110.5
			 Team East Score: 112.6
			 Team North Score: 109.2
			 Team South Score: 115.225
 
 Preconditions: The method must be passed an array of type Gymnast and an integer in that order to work. The array must not be empty. The team names stored in the array must be either "West", "East", "North", or "South".
 Postconditions: The function will print the teams' total scores when called.
 */
void Scores::printTeamTotal(Gymnast arr[], int count)
{
	//create variables to hold scores
	double westTotal = 0;
	double eastTotal = 0;
	double southTotal = 0;
	double northTotal = 0;
	//loop through array,if the gymnast is on the certain team, add her score to the total score
	for(int i = 0; i < count; i++)
	{
		if(arr[i].teamName == " West")
		{
			westTotal += arr[i].score;
		}
		else if(arr[i].teamName == " East")
		{
			eastTotal += arr[i].score;
		}
		else if(arr[i].teamName == " North")
		{
			northTotal += arr[i].score;
		}
		else
		{
			southTotal += arr[i].score;
		}
	}
	//print scores
	cout<<"Team West Score: "<<westTotal<<endl<<"Team East Score: "<<eastTotal<<endl<<"Team North Score: "<<northTotal<<endl<<"Team South Score: "<<southTotal<<endl;
	
}
