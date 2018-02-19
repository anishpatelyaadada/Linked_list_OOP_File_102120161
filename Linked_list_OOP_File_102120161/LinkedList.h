#pragma once
#include<iostream>
#include <string>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<vector>

using namespace std;

class LinkedList
{
public:
	struct record
	{
		string lastName;
		string firstName;
		int ID;
		string eMail;
		char DOB[10];
		char classification;
		float GPA;
		int age;
		string major;
		struct record *next;
	};
	struct doubleValue
	{
		double number;
		struct doubleValue *next;

	};
	record *head;
	doubleValue *headDouble;
	int length = 0;
public:
	LinkedList();
	~LinkedList();
	void insertNode(record *);
	void deleteNode(record *);
	void appendNodeFile(record *);
	void InsertNewDataInList(record *);
	void appendNode(double);
	void displayListDouble();
	int getLenght();
	void displayListFile();
};

