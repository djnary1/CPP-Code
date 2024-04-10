// Lab 2: Double Threaded Binary Search Tree
// Name: Daniel Nary
// Date: 09/29/2023
// Purpose: To create a double threaded binary search tree and test it's functions
// Class and Section: CSCN 215-002 Data Structures and Algorithms

// Include statements and using namespace
#include <iostream>
#include "BST.h"
using namespace std;

void wait(); //Used to pause screen output, created by Professor Sipantzi

int main()
{
	BST<int, string> tree; // Creates a BST object
	tree.insert(77, "seventy-seven"); // Lines 10 - 22 are used to insert values into the tree
	tree.insert(70, "seventy");
	tree.insert(75, "seventy-five");
	tree.insert(66, "sixty-six");
	tree.insert(79, "seventy-nine");
	tree.insert(68, "sixty-eight");
	tree.insert(67, "sixty-seven");
	tree.insert(69, "sixty-nine");
	tree.insert(90, "ninety");
	tree.insert(85, "eighty-five");
	tree.insert(83, "eighty-three");
	tree.insert(87, "eighty-seven");
	tree.insert(65, "sixty-five");
	cout << "Testing the insert function to build my tree." << endl;
	cout << "My BST tree size is " << tree.size() << endl; // This function tests to see how big the tree is
	cout << "My tree's structure is <tests my changes to the print function>:" << endl;
	tree.print(); // This function prints out the structure of the tree
	cout << endl << "Inorder printing of my tree" << endl;
	cout << "<tests my right threads and printInOrder function>:" << endl;
	tree.printInOrder(); // This function prints our the in-order traversal of the tree
	cout << endl << "Reverse order printing of tree" << endl;
	cout << "<tests my left threads and printReverse function>:" << endl;
	tree.printReverse(); // This function prints out the reverse order traversal of the tree

	void wait(); // Waits until the user presses enter to continue
	return 0;
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