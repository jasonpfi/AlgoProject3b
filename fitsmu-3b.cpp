/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * fitsmu-3a.cpp: Main code file for word search program
 */

#include <iostream>
#include <fstream>
#include <string>
#include "grid.h"
#include "dictionary.h"

void findMatches(const grid& g, const dictionary& d);

// main method
// Search the dictionary with every possible word greater than 5 characters in
// the grid
int main()
{
	std::cout << "Word Search Program" << std::endl;

	//// Load dictionary
	std::ifstream wordFile("data/dictionary.txt");
	if (!wordFile) return 1; // error reading file
	dictionary wordList(wordFile);
	wordFile.close();

	while (true)
	{
		std::cout << "Choose sorting method:\n"
			<< "Selection Sort (0)\n"
			<< "Quick Sort (1)\n"
			<< "Heap Sort (2)\nEnter method number: ";

		int method = 0;
		std::cin >> method;

		// sort dictionary
		std::cout << "Sorting word list...";

		// switch on sorting algorithm
		switch (method)
		{
		case 0:
			wordList.selectionSort();
			break;
		case 1:
			wordList.quickSort();
			break;
		case 2:
			wordList.heapsort();
			break;
		default:
			std::cout << "\n\nInvalid sorting option.\n";
			continue;
		}
		break;
	}
	std::cout << "Done" << std::endl;

	std::cout << "Enter file name that can be found in the data folder: ";
	std::string fileName;
	std::cin >> fileName;

	std::ifstream f(("data/" + fileName).c_str());
	if (!f) return 1; // error reading file

	// Instantiate grid object
	grid g(f);

	f.close();

	findMatches(g, wordList);

	std::cout << std::endl;

	std::cin.get();
	return 0;
} // End main

// Generates candidate words from grid (g) and prints out the ones
// that are found in the dictionary (d)
void findMatches(const grid& g, const dictionary& d)
{
	// Get all of the possible words from the grid
	std::vector<std::string> candidateWords(g.readGrid());

	std::cout << "Words in the grid found in the dictionary: " << std::endl;

	// Iterate through the vector of possible words. If the word is found in
	//  the dictionary, print it to the screen
	std::vector<std::string>::iterator it;
	int printIndex = 0;
	for (it = candidateWords.begin(); it != candidateWords.end(); it++)
	{
		if (d.binarySearch(*it) != -1)
		{
			std::cout << *it << ", ";
			printIndex++;

			if (printIndex % 5 == 0)
				std::cout << std::endl;
		}
	}
} // End findMatches
