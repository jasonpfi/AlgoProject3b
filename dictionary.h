/*
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * dictionary.h: Contains all of the declarations for the methods and fields of
 *               a dictionary object
 */

#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

 // Class declaration
class dictionary
{

public:

	// Constructor
	//
	// ifstream stream: input stream to read words from dictionary file
	dictionary(std::ifstream& stream);

	// Search for the given string in the dictionary. Return -1 if not found and
	//  the index of the item in the dictionary if there was a match
	// Utilizes the binary search method
	//
	// string target: String to be searched for in the vector
	int binarySearch(const std::string& target) const;

	// Sort the dictionary in a lexicographic manner. Utilizes selection sort
	void selectionSort();

	// Overloaded output operator to print contents of dictionary
	friend std::ostream& operator<<(std::ostream& os,
		const dictionary& dict);

private:

	// The list of all the words in the dictionary
	std::vector<std::string> words;

	// Swap the key's at index i and index least
	//
	// int i: current index of first loop
	// int least: index of element with the smallest value in the rest of the
	//            vector
	void swap(int i, int least);
};

