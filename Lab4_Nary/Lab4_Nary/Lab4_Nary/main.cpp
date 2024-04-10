#include <iostream>
#include "MoveToFront.h"
#include "Count.h"
#include "Transpose.h"
#include <string>
#include <fstream>
using namespace std;

// functions
void wait();

int main() {
	MoveToFront<char> mtf; // create MoveToFront object being used for the part where we read in an assortment of char values
	Count<char> count; // create Count object being used for the part where we read in an assortment of char values
	Transpose<char> transpose; // create Transpose object being used for the part where we read in an assortment of char values
	MoveToFront<string> mtf2; // create MoveToFront object being used for the part where we read in words from a file
	Count<string> count2; // create Count object being used for the part where we read in words from a file
	Transpose<string> transpose2; // create Transpose object being used for the part where we read in words from a file
	ifstream inFile; // create ifstream object for reading in the from the file
	string word; // create string object storing the words from the file into the linked list

	// adds the following characters to the linked list
	mtf.add('A');
	mtf.add('B'); 
	mtf.add('C'); 
	mtf.add('D'); 
	mtf.add('E'); 
	mtf.add('F'); 
	mtf.add('G'); 
	mtf.add('H'); 

	// finds the following characters in the linked list and uses the Move-to-Front heuristic
	mtf.find('F'); 
	mtf.find('D'); 
	mtf.find('F'); 
	mtf.find('G'); 
	mtf.find('E'); 
	mtf.find('G');
	mtf.find('F');
	mtf.find('A');
	mtf.find('D');
	mtf.find('F');
	mtf.find('G');
	mtf.find('E');
	mtf.find('H');
	mtf.find('I');

	// adds the following characters to the linked list
	transpose.add('A'); 
	transpose.add('B'); 
	transpose.add('C'); 
	transpose.add('D'); 
	transpose.add('E'); 
	transpose.add('F'); 
	transpose.add('G'); 
	transpose.add('H');

	// finds the following characters in the linked list and uses the Transpose heuristic
	transpose.find('F');
	transpose.find('D');
	transpose.find('F');
	transpose.find('G');
	transpose.find('E');
	transpose.find('G');
	transpose.find('F');
	transpose.find('A');
	transpose.find('D');
	transpose.find('F');
	transpose.find('G');
	transpose.find('E');
	transpose.find('H');
	transpose.find('I');

	// adds the following characters to the linked list
	count.add('A'); 
	count.add('B'); 
	count.add('C'); 
	count.add('D'); 
	count.add('E'); 
	count.add('F'); 
	count.add('G'); 
	count.add('H'); 

	// finds the following characters in the linked list and uses the Count heuristic
	count.find('F'); 
	count.find('D'); 
	count.find('F'); 
	count.find('G'); 
	count.find('E'); 
	count.find('G');
	count.find('F');
	count.find('A');
	count.find('D');
	count.find('F');
	count.find('G');
	count.find('E');
	count.find('H');
	count.find('I');

	// The following statements prints out the size of the linked list, the number of compares, and the first 9 characters within the linked list
	cout << "Count Heuristic: Size of list: " << count.size() << endl;
	cout << "Number of compares: " << count.getCompares() << endl;
	count.printlist();
	cout << endl << endl;

	cout << "Move-to-Front Heuristic: Size of list: " << mtf.size() << endl;
	cout << "Number of compares: " << mtf.getCompares() << endl;
	mtf.printlist();
	cout << endl << endl;

	cout << "Tranpose Heuristic: Size of list: " << transpose.size() << endl;
	cout << "Number of compares: " << transpose.getCompares() << endl;
	transpose.printlist();
	cout << endl << endl;

	// The following code reads in words from a file and adds/finds them to the linked list
	inFile.open("test.txt");
	if (inFile.is_open()) {
		// Reads the file until there is nothing left to read
		while (!inFile.eof()) {
			inFile >> word;
			mtf2.find(word);
			transpose2.find(word);
			count2.find(word);
		}
		// closes the file
		inFile.close();
	}
	// should never run as long as the file is in the correct directory and has the correct name
	else {
		cout << "Unable to open file." << endl;
	}
	// The following statements prints out the size of the linked list, the number of compares, and the first 10 words within the linked list
	cout << "Count Heuristic: Size of list: " << count2.size() << endl;
	cout << "Number of compares: " << count2.getCompares() << endl;
	count2.printlist(10);
	cout << endl << endl;

	cout << "Move-to-Front Heuristic: Size of list: " << mtf2.size() << endl;
	cout << "Number of compares: " << mtf2.getCompares() << endl;
	mtf2.printlist(10);
	cout << endl << endl;

	cout << "Tranpose Heuristic: Size of list: " << transpose2.size() << endl;
	cout << "Number of compares: " << transpose2.getCompares() << endl;
	transpose2.printlist(10);
	cout << endl << endl;
	// waits until the user presses enter to exit the program
	wait();
}

//Used to pause the screen wherever desired
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.

	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(256, '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}