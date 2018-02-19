// linked_list_OOP_101120161.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include"LinkedList.h"

using namespace std;
int main()
{
	LinkedList list; // initialize the variable for OOP class	
	LinkedList::record dataFromFile; // declare variable for record structure	
	ifstream inputFile; // 
	ofstream sortedFile;
	inputFile.open("studentFile.txt"); // open file to read content 

	if (inputFile.is_open()) { // check condition if file open successfully
		cout << "File open successfully.\n";
		// process the loop to display all data from file
		while (!inputFile.eof() && inputFile >> dataFromFile.lastName >> dataFromFile.firstName >> dataFromFile.ID >> dataFromFile.eMail >> dataFromFile.DOB[0] >> dataFromFile.DOB[1] >> dataFromFile.DOB[2] >> dataFromFile.DOB[3] >> dataFromFile.DOB[4] >> dataFromFile.DOB[5] >> dataFromFile.DOB[6] >> dataFromFile.DOB[7] >> dataFromFile.DOB[8] >> dataFromFile.DOB[9] >> dataFromFile.classification >> dataFromFile.GPA >> dataFromFile.age >> dataFromFile.major) {
		
			//below cout is working correctly
			//cout << "Record #"  << setw(20) << dataFromFile.lastName << setw(16) << dataFromFile.firstName << setw(15) << dataFromFile.ID << setw(27) << dataFromFile.eMail << setw(18) << dataFromFile.DOB[0] << dataFromFile.DOB[1] << dataFromFile.DOB[2] << dataFromFile.DOB[3] << dataFromFile.DOB[4] << dataFromFile.DOB[5] << dataFromFile.DOB[6] << dataFromFile.DOB[7] << dataFromFile.DOB[8] << dataFromFile.DOB[9] << setw(20) << dataFromFile.classification << setw(17) << dataFromFile.GPA << setw(13) << dataFromFile.age << setw(17) << dataFromFile.major << endl;
			
			// pass data of file into function for linked list operation
			list.appendNodeFile(&dataFromFile);
			
		}
	}
	else
	{
		cout << "error opening in file.\n";
	}
	/*list.appendNode(2.5);
	list.appendNode(7.9);
	list.appendNode(10);

	list.displayListDouble();*/
	list.displayListFile();
	cout << "Total Number of Record in File = " << list.getLenght() << endl;
	inputFile.close();
	return 0;
}

