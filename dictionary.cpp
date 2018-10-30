/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * dictionary.cpp: Contains the definitions for the methods declared in the
 *           dictionary.h header file
 */

#include "dictionary.h"

// Dictionary constructor
// stream: file stream to read words from
dictionary::dictionary(std::ifstream& stream)
{
	this->words = std::vector<std::string>();

	std::string next;
	while (!stream.eof())
	{
		stream >> next;
		this->words.push_back(next);
	}
}

// Overloaded output operator to print contents of dictionary
//
// ostream os: output stream object to write to screen
// dictionary dict: dictionary object, print all words
std::ostream& operator<<(std::ostream& os, const dictionary& dict)
{
	for (int i = 0; i < dict.words.size(); i++)
	{
		os << dict.words.at(i) << "\n";
	}

	return os;
}

// Swap the key's at index i and index least
//
// int i: current index of first loop
// int least: index of element with the smallest value in the rest of the
//            vector
void dictionary::swap(int i, int least)
{
	// Temporary element value
	std::string tmp(this->words.at(i));

	this->words.at(i) = this->words.at(least);
	this->words.at(least) = tmp;
}

// Sort the dictionary in a lexicographic manner using selection sort
void dictionary::selectionSort()
{

	// n - 1 steps through the vector of strings
	for (int i = 0; i < this->words.size() - 2; i++)
	{
		// Set the least item at index i
		int least(i);

		// Loop through the rest of the vector. If the value at index j is less
		//  than the value at index i, set index j as the current least element
		for (int j = i + 1; j < this->words.size(); j++)
		{
			if (this->words.at(least) > this->words.at(j))
			{
				least = j;
			}
		}

		// Swap the words at index least and index i
		this->swap(i, least);
	} // End for
} // End selectionSort()

// Search for the given string in the dictionary. Return -1 if not found and
//  the index of the item in the dictionary if there was a match
// Utilizes the binary search method with a sorted vector
//
// string target: String to be searched for in the vector
int dictionary::binarySearch(const std::string& target) const
{
	// Specify the front and end of the array
	int front(0);
	int back(this->words.size() - 1);

	// Within bounds of vector
	while (front <= back)
	{
		// Find midpoint and compare with target
		int mid((front + back) / 2);
		std::string midValue = this->words.at(mid);

		// Target found
		if (target == midValue)
		{
			return mid;
		}

		// Target in left half of vector
		else if (target < midValue)
		{
			back = mid - 1;
		}

		// Target in right half of vector
		else
		{
			front = mid + 1;
		}
	}

	// Target Not found
	return -1;
}
