#pragma once
#include <iostream>
#include "SelfOrderedListADT.h"
#include "llist.h"
/*
 * File:   SelfOrderedListADT.hpp
 * Author: Prof Sipantzi
 *
 * Created on September 28, 2012, 8:18 AM
 * Modified 05/15/2023 -- Prof Sipantzi
 */

template <class E>
class Count : public SelfOrderedListADT<E> {
public:
	//Default constructor/destructor
	Count() {}
	~Count() {}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it) {
		bool found = false; // Boolean to check if the value is found
		list.moveToStart(); // Just in case it's not pointing to the start of the list
		for (int i = 0; i < list.length(); i++) {
			compares++; //increments the number of compares made
			if (list.getValue() == it) { // Checks if the value is found
				found = true; //increment frequency
				list.setFreq(list.getFreq() + 1); // Increments the frequency if it was found
				break; // breaks from the loop
			}
			list.next();
		}
		reorder(it, found); // Reorders the list
		if (found == false) {
			add(it); // Appends the value to the list, if it was not found
		}
		return found;
	}
	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	void add(const E& it) {
		list.append(it); //Appends 'it' to the list
	}//Add new 'it' to the list


	int getCompares() const {
		return compares;
	}
	//Returns the number of accumulated compares

	int size() const {
		return list.length();
	} //Returns the size of the list

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist() {
		list.moveToStart(); // Just in case it's not pointing to the start of the list
		for (int i = 0; i < list.length(); i++) {
			std::cout << list.getValue() << "-" << list.getFreq() << " "; // Prints the list
			list.next(); // Moves the list to the next position
		}
	}
	void printlist(int n) {
		list.moveToStart(); // Just in case it's not pointing to the start of the list
		for (int i = 0; i < n; i++) {
			std::cout << list.getValue() << "-" << list.getFreq() << " "; // Prints the list
			list.next(); // Moves the list to the next position
		}
	}

	void clear() {
		list.clear();
	}
	// Clears the list
	void reorder(const E& it, bool found) { //Reorders the list in terms of Count
		if (found == true && list.getCurrent() != list.getHead()) {
			int tempFreq = list.getFreq(); // Creates a temporary variable to hold frequency
			list.remove(); // Removes the value from the list
			list.moveToStart(); // Moves the list to the start
			while (tempFreq <= list.getFreq()) { // Compares the frequency of the value to the frequency of each item in the list and once the condition is false, it will place 'it' accordingly to the Count heuristic
				list.next();
			}
			list.insert(it); // Inserts the value into the list
			list.setFreq(tempFreq); // Sets the frequency of the value to the frequency of the value that was removed, to maintain the frequency of the value
		}
	}
	// do not make any changes to this file or you will not get
	// any credit for your work -- Prof Sipantzi (05/13/2022)	
private:
	LList<E> list; //List of elements, not a pointer because it is already made up of pointers
	int compares; // Number of compares
};
