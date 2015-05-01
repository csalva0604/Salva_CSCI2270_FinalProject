//Christine Salva
//Professor Hoenigman
//Final Project
//May, 2015

#include <iostream>
#include "FinalProject.h"
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

void displayMenu()
{
	
	cout << "~~~~~~Options~~~~~~" 			 << endl;
	cout << "1. Find Top Scores for Event of Choice" << endl;
	cout << "2. Delete gymnast from array"		 << endl;
	cout << "3. Print certain gymnast's scores"	 << endl;
	cout << "4. Find total deductions for gymnast"	 << endl;
	cout << "5. Print team scores"		         << endl;
	cout << "6. Print remaining gymnasts"		 << endl;
	cout << "7. Quit"			    	 << endl;
}


void displayEvents()
{	
	cout << "~~~~~~Events~~~~~~" << endl;
	cout << "balance beam"	     << endl;
	cout << "floor exercise"     << endl;
	cout << "uneven bars"  	     << endl;
	cout << "vault"		     << endl;
	cout << endl;
}

bool checkEventExists(string userSelection)
{
	string events[] = {"balance beam", "floor exercise", "uneven bars", "vault"};

	for (int i = 0; i < 4; i++) {
		
		if (events[i] == userSelection)
			return true;
	}

	return false;
}


int main(int argc, char* argv[])
{
	string userInput;
	Gymnast* ScoresArray = new Gymnast[10];
	Gymnast* a2 = ScoresArray;
	int gymnastNumber;
	int count = 0;
	int size = 10;
	double score;
	string event;
	string line;
	Scores ScoreInstance;
	string filename = argv[1];
	ifstream infile;
	infile.open(filename);
	if(infile.is_open())
	{
	
		while(getline(infile, line))
		{
			
			istringstream ss(line);
			string token;
			
			getline(ss, token, ',');
	
			gymnastNumber = stoi(token);
			
				
			getline(ss, token, ',');
			score = stod(token);
			
			getline(ss, token, ',');
			string event = token;
			getline(ss, token, ',');
			string teamName = token;
			ScoresArray = ScoreInstance.storeArray(gymnastNumber, score, event, ScoresArray, size, a2, count, teamName);
			if(size == count)
			{
				size = size*2;
			}
			count++;
			

		}
		while(userInput != "7")
		{

			cin.clear();

			displayMenu();

			cin>>userInput;
			cin.ignore();

			if(userInput == "1")
			{

				displayEvents();

				string event;
				cout<<"Enter event to calculate winners for:"<<endl;
				getline(cin, event);

				bool eventExists = checkEventExists(event);

				if (eventExists)
					ScoreInstance.printTopThree(event, ScoresArray, count);

				else
					cout << "Event does not exist! check the spelling!" << endl;
			}
			else if(userInput == "2")
			{
				int gymnastNumber;
				cout<<"Enter gymnast number to delete:"<<endl;
				cin>>gymnastNumber;

				bool gymnastExists = ScoreInstance.checkGymnastExists(ScoresArray, gymnastNumber, count);

				if (gymnastExists) {
				//subtract one from total amount of items to compensate for gymnast deleted from array
					count--;
					ScoresArray = ScoreInstance.deleteGymnast(ScoresArray, gymnastNumber, count);
					cout << "Removing gymnast number " << gymnastNumber << endl;
				}
				
				else
					cout << "Gymnast does not exist!" << endl;	
			}
			else if(userInput == "3")
			{
				int gymnastNumber;
				cout<<"Enter gymnast's number to find:"<<endl;
				cin>>gymnastNumber;
				
				bool gymnastExists = ScoreInstance.checkGymnastExists(ScoresArray, gymnastNumber, count);

				if (gymnastExists)
					ScoreInstance.findGymnast(ScoresArray, gymnastNumber, count);

				else
					cout << "Gymnast does not exist!" << endl;
			}
			else if(userInput == "4")
			{
				int gymnastNumber;
				cout<<"Enter gymnast to find deductions:"<<endl;
				cin>>gymnastNumber;
	
				bool gymnastExists = ScoreInstance.checkGymnastExists(ScoresArray, gymnastNumber, count);

				if (gymnastExists)
					ScoreInstance.totalDeductions(ScoresArray, count, gymnastNumber);

				else
					cout << "Gymnast does not exist!" << endl;
			}
			else if(userInput == "5")
			{
				ScoreInstance.printTeamTotal(ScoresArray, count);
			}
			else if(userInput == "6")
			{
				ScoreInstance.printRemaining(ScoresArray, count);
			}
		}
		cout<<"Goodbye!"<<endl;
	}
	
	return 0;
}
