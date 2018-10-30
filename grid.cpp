/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * grid.cpp: Contains the definitions for the methods declared in the grid.h
 *           header file
 */

#include "grid.h"

 // Constructor for grid class
grid::grid(std::ifstream& stream)
{
	// Read the number of rows and columns from the first 2 items in the
	//  data file
	int rows;
	int cols;
	stream >> rows;
	stream >> cols;

	// Create a matrix with that number of rows and columns
	this->mat = matrix<char>(rows, cols);

	// Add the characters in the data file to the matrix one by one, indexing
	//  by column and row of the matrix
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			stream >> mat[i][j];
		}
	}
} // End Constructor

// Generates candidate words from grid that have length at least 5
std::vector<std::string> grid::readGrid() const
{
	std::vector<std::string> candidateWords;

	// iterate through columns and rows with i and j loops
	for (int i = 0; i < this->mat.cols(); i++)
	{
		for (int j = 0; j < this->mat.rows(); j++)
		{
			// loop through 8 different orientations of words
			for (int k = 0; k < 8; k++)
			{
				this->findWords(candidateWords, k, i, j);
			}
		}
	}

	return candidateWords;
}

// Find all the possible words in every direction for the letter in the
//  matrix at row index j and column index i. This method is called 8 times
//  by readGrid() - once for every possible direction
//
//  vector<string> vec: The list of all strings of length of at least 5 found
//       in this grid
//  int direction: integer that is switched upon. This specifies on of 8
//       directions - up, down, left, right, up-right, up-left, down-right,
//                  down-left
//  int i: the index of the column of the current item in the matrix
//  int j: the index of the row of the current item in the matrix
void grid::findWords(std::vector<std::string>& vec, const int& direction,
	int& i, int& j) const
{
	// Switch on one of 8 possible directions
	switch (direction)
	{
		// Up
	case 0:
		this->generateWords(&grid::moveUp, vec, i, j);
		break;
		// Down
	case 1:
		this->generateWords(&grid::moveDown, vec, i, j);
		break;
		// Right
	case 2:
		this->generateWords(&grid::moveRight, vec, i, j);
		break;
		// Left
	case 3:
		this->generateWords(&grid::moveLeft, vec, i, j);
		break;
		// Up Right
	case 4:
		this->generateWords(&grid::moveUR, vec, i, j);
		break;
		// Up Left
	case 5:
		this->generateWords(&grid::moveUL, vec, i, j);
		break;
		// Down Right
	case 6:
		this->generateWords(&grid::moveDR, vec, i, j);
		break;
		// Down Left
	case 7:
		this->generateWords(&grid::moveDL, vec, i, j);
		break;
	} // End Switch
} // End findWords()

// Append to the vector of possible words for the letter at the given index
//  of starti and startj by moving in one of 8 directions. The direction is
//  Controlled by the function pointer. All possible words in this direction
//  of:
//  5 < length < mat.row()/mat.col() 
//  are added to the vector.
//	NOTE: because this is a square matrix, mat.row() == mat.col()
//
//  void(grid::*f)(int &, int &): The function pointer that updates the
//       indices starti and startj in a certain direction on the grid.
//  vector<string> vec: The list of all strings of length of at least 5 found
//       in this grid
//  int starti: the index of the column of the current item in the matrix
//  int startj: the index of the row of the current item in the matrix
void grid::generateWords(void(grid::*f) (int&, int&) const, std::vector<std::string>& vec,
	int& i, int& j) const
{
	// Empty Word to be appended to
	std::string word = "";

	// Loop through all possible letters making up this word, adding them to
	//  the string "word" one by one
	for (int k = 0; k < this->mat.rows(); k++)
	{
		word += mat[i][j];
		(this->*f)(i, j);

		// Test if the length of the word is > 4, then add the word to the vector
		if (k >= 4)
			vec.push_back(word);
	}
} // End generateWords()

// Decrement j, Move up
void grid::moveUp(int& i, int& j) const
{
	j--;

	if (j == -1)
		j = mat.rows() - 1;
}

// Increment j, Move down
void grid::moveDown(int& i, int& j) const
{
	j++;

	if (j == mat.rows())
		j = 0;
}

// Increment i, Move right
void grid::moveRight(int& i, int& j) const
{
	i++;
	if (i == mat.cols())
		i = 0;
}

// Decrement i, Move left
void grid::moveLeft(int& i, int& j) const
{
	i--;
	if (i == -1)
		i = mat.cols() - 1;
}

// Decrement j + Decrement i, Move up-left
void grid::moveUL(int& i, int& j) const
{
	moveUp(i, j);
	moveLeft(i, j);
}

// Decrement j + increment i, Move up-right
void grid::moveUR(int& i, int& j) const
{
	moveUp(i, j);
	moveRight(i, j);
}

// Increment j + Decrement i, Move down-left
void grid::moveDL(int& i, int& j) const
{
	moveDown(i, j);
	moveLeft(i, j);
}

// Increment j + Increment i, Move down-right
void grid::moveDR(int& i, int& j) const
{
	moveDown(i, j);
	moveRight(i, j);
}
