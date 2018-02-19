#include "LinkedList.h"


LinkedList::LinkedList()
{
	head = nullptr;
	headDouble = nullptr;
}
LinkedList::~LinkedList()
{
}
void LinkedList::insertNode(record *data) {

}
// read the data from file and append at the end of pointer
void LinkedList::appendNodeFile(record *data) {
	record *newNode;// to point to new node
	record *travereList;// to move through the list

#pragma region MyRegion assign all incoming content to newnode individually because it is coming from file
	newNode = new record;
	newNode->lastName = data->lastName;
	newNode->firstName = data->firstName;
	newNode->ID = data->ID;
	newNode->eMail = data->eMail;
	newNode->classification = data->classification;
	newNode->GPA = data->GPA;
	newNode->age = data->age;
	newNode->major = data->major;
	newNode->DOB[0] = data->DOB[0];
	newNode->DOB[1] = data->DOB[1];
	newNode->DOB[2] = data->DOB[2];
	newNode->DOB[3] = data->DOB[3];
	newNode->DOB[4] = data->DOB[4];
	newNode->DOB[5] = data->DOB[5];
	newNode->DOB[6] = data->DOB[6];
	newNode->DOB[7] = data->DOB[7];
	newNode->DOB[8] = data->DOB[8];
	newNode->DOB[9] = data->DOB[9];
	newNode->next = nullptr;
#pragma endregion
	
	//if there is no node in the list make 
	// newnode the first node
	if (!head) {
		head = newNode; // if there is no data in list assign first node to head
	}
	else {
		travereList = head;
		// find the last node in list
		while (travereList->next)
		{
			travereList = travereList->next;
		}
		// if use below commented statement, the function will be able to count the total number of record
		// but it will just display only first record, therefore we use travereList->next = newNode;
		//newNode->next = newNode;

		// insert newnode as the last node in the list
		travereList->next = newNode;
	}
	
	length++; // counter to calculate the total number of data in list
}

void LinkedList::appendNode(double data) {
	doubleValue *newNode;// to point to new node
	doubleValue *nodeptr;// to move through the list

						 //allocate new node and store data over there and assign next node after this to null
	newNode = new doubleValue;
	newNode->number = data;
	newNode->next = nullptr;

	//if there is no node in the list make 
	// newnode the first node
	if (!headDouble) {
		headDouble = newNode;
	}
	else {
		// initialize nodeprt to head of list
		nodeptr = headDouble;

		// find the last node in list
		while (nodeptr->next)
		{
			nodeptr = nodeptr->next;
		}
		// insert newnode as the last node
		nodeptr->next = newNode;
	}
}

void LinkedList::deleteNode(record *data) {

}

void LinkedList::displayListDouble() {
	doubleValue *nodeptr; // to move throught the list 
	nodeptr = headDouble; // postion nodeptr at the head of the list
						  // traverse the list to diplay all the data
	while (nodeptr) {
		cout << nodeptr->number << endl; // diplay the value
		nodeptr = nodeptr->next; // move to the next node
	}
}
void LinkedList::displayListFile() {
	record *nodeptr; // to move throught the list 
	nodeptr = head; // postion nodeptr at the head of the list
	int i = 0;
	cout << " Records  " << setw(15) << "Last Name" << setw(20) << "First Name " << setw(10) << "ID" << setw(25) << " eMail " << setw(15) << " DOB" << setw(18) << "Class " << setw(15) << " GPA " << setw(15) << " age " << setw(15) << "major " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

	// traverse the list to diplay all the data of file in console application
	while (nodeptr) {
		cout << "Record #" << (i+1) << setw(15) << nodeptr->lastName << setw(16) << nodeptr->firstName << setw(15) << nodeptr->ID << setw(27) << nodeptr->eMail << setw(8) << nodeptr->DOB[0] << nodeptr->DOB[1] << nodeptr->DOB[2] << nodeptr->DOB[3] << nodeptr->DOB[4] << nodeptr->DOB[5] << nodeptr->DOB[6] << nodeptr->DOB[7] << nodeptr->DOB[8] << nodeptr->DOB[9] << setw(10) << nodeptr->classification << setw(17) << nodeptr->GPA << setw(13) << nodeptr->age << setw(17) << nodeptr->major << endl;
		nodeptr = nodeptr->next; // move to the next node
		i++;
	}
}

int LinkedList::getLenght() {
	return length;
}
void LinkedList::InsertNewDataInList(record *data){
	record *newNode;// to point to new node
	record *travereList;// to move through the list
	record *previousNode = nullptr;

#pragma region MyRegion assign all incoming content to newnode individually because it is coming from file
	newNode = new record;
	newNode->lastName = data->lastName;
	newNode->firstName = data->firstName;
	newNode->ID = data->ID;
	newNode->eMail = data->eMail;
	newNode->classification = data->classification;
	newNode->GPA = data->GPA;
	newNode->age = data->age;
	newNode->major = data->major;
	newNode->DOB[0] = data->DOB[0];
	newNode->DOB[1] = data->DOB[1];
	newNode->DOB[2] = data->DOB[2];
	newNode->DOB[3] = data->DOB[3];
	newNode->DOB[4] = data->DOB[4];
	newNode->DOB[5] = data->DOB[5];
	newNode->DOB[6] = data->DOB[6];
	newNode->DOB[7] = data->DOB[7];
	newNode->DOB[8] = data->DOB[8];
	newNode->DOB[9] = data->DOB[9];
	newNode->next = nullptr;
#pragma endregion

	if (!head) {
		head = newNode; // if there is no data in list assign first node to head
		newNode->next = nullptr;
	}
	else {
		travereList = head;
		previousNode = nullptr;
		// find the last node in list
		while (travereList != nullptr &&  travereList->ID < data->ID)
		{
			previousNode = travereList;
			travereList = travereList->next;
		}
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = travereList;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = travereList;
		}
	}
}