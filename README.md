# Salva_CSCI2270_FinalProject
In the sport of gymnastics, gymnasts receive scores between 0 and 10 based on how well they completed their routines from a set of judges for each event: floor exercise, balance beam, vault, and uneven bars. The scores can be whole numbers or decimals, causing the difference between two gymnasts' scores to be as small as a hundredth of a point. After an event, going through every gymnast's score to decide who got first, second, and third place for each can be very lenghty. In order to help make this process easier, this program reads in from a file gymnasts' scores, gets the reader input for which event the scores should be analyzed, and outputs who received first, second, and third place along with their scores. The program will store the scores and the other information (including the team the gymnast is on, either "West", "North", "East", or "South") into a dynamically allocated array. The program will also provide the user with options from a menu to find certain information from the array.

How To Run:
To run this program, include the file name as a command line argument. For example, if the file with the gymnasts and their scores is stored in a file called "GymnastScores.txt" use this file name as a command line argument.The text file the program reads needs to be in the format of the gymnast's ID number(an int), the score(an int), the event competed(a string), and the team the gymnast is on(a string). The program will automatically store the information into an array. To search the array for the gymnasts with the top three scores, the user will press one. To delete a gymnast from the array, press two. To print a certain gymnast's score, press 3. To find the total deductions a gymnast received for her routine, press 4. To print each team's total score, press 5. To quit the program, press 6. For example, a menu will be brought up for the user, and it will tell the user their options to choose. 

Dependencies:
This program will not require any additional libraries to be installed, but needs to be run with -std==c++11 on the command line. 

System Requirements:
There are no system requirements. 

Group Members:
None

Contributors:
None yet

Open issues/bugs:
In the last function, printTeamTotal, I didn't know how to add each of the scores that match up with the specific teams to the team total without hardcoding "West", "East", "North", and "South" into the loop. Also, I'd like to utilize a constructor, but I don't know what to put in it. 
