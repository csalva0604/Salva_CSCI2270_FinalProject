//Christine Salva
//Professor Hoenigman
//Final Project
//May, 2015
#ifndef FINALPROJECT_H
#define FINALPROJECT_H

#include <string>

struct Gymnast
{
	int gymnastNumber;
	double score;
	std::string event;
	std::string teamName;
};
class Scores
{
	public:
		
		Scores();
		void printRemaining(Gymnast arr[], int counter);
		Gymnast* storeArray(int gymnastNumber, double score, std::string event, Gymnast arr[], int size, Gymnast arr2[], int counter, std::string teamName);
		Gymnast* deleteGymnast(Gymnast arr[], int gymnastNumber, int count);
		void sortArray(Gymnast arr[], int count);
		bool findEvent(std::string event, int gymnastNumber, Gymnast arr[], int count, int index);
		void addGymnast(Gymnast arr[], int count, int gymnastNumber, int score, std::string event,int size);
		void findGymnast(Gymnast arr[], int gymnastNumber, int count);
		void printTopThree(std::string event, Gymnast arr[], int count);
		//bool findTeam(Gymnast arr[], int count, std::string teamName);
		void printTeamTotal(Gymnast arr[], int count);
		Gymnast* shiftArray(Gymnast arr[], int index, int count);
		void totalDeductions(Gymnast arr[], int count, int gymnastNumber);
		bool checkGymnastExists(Gymnast arr[], int gymnastNumber, int count);		
	
};

#endif //FINALPROJECT_H
