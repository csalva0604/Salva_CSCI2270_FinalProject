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
		while(userInput != "6")
		{
			cout<<"~~~~~~Options~~~~~~"<<endl;
			cout<<"1. Find Top Scores for Event of Choice"<<endl;
			cout<<"2. Delete gymnast from array"<<endl;
			cout<<"3. Print certain gymnast's scores"<<endl;
			cout<<"4. Find total deductions for gymnast"<<endl;
			cout<<"5. Print team scores"<<endl;
			cout<<"6. Quit"<<endl;
			cin>>userInput;
			if(userInput == "1")
			{
				string event;
				cout<<"Enter event to calculate winners for:"<<endl;
				cin.ignore();
				getline(cin, event);
				ScoreInstance.printTopThree(event, ScoresArray, count);
			}
			else if(userInput == "2")
			{
				int gymnastNumber;
				cout<<"Enter gymnast number to delete:"<<endl;
				cin>>gymnastNumber;
				//subtract one from total amount of items to compensate for gymnast deleted from array
				count--;
				ScoresArray = ScoreInstance.deleteGymnast(ScoresArray, gymnastNumber, count);
				
				for(int i = 0; i < count; i++)
				{
					cout<<ScoresArray[i].gymnastNumber<<endl;
				}
				
			}
			else if(userInput == "3")
			{
				int gymnastNumber;
				cout<<"Enter gymnast's number to find:"<<endl;
				cin>>gymnastNumber;
				ScoreInstance.findGymnast(ScoresArray, gymnastNumber, count);
			}
			else if(userInput == "4")
			{
				int gymnastNumber;
				cout<<"Enter gymnast to find deductions:"<<endl;
				cin>>gymnastNumber;
				ScoreInstance.totalDeductions(ScoresArray, count, gymnastNumber);
			}
			else if(userInput == "5")
			{
				ScoreInstance.printTeamTotal(ScoresArray, count);
			}
		}
		cout<<"Goodbye!"<<endl;
	}
	
	return 0;
}
