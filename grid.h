/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * grid.h: Contains all of the declarations for the methods and fields of a
 *         grid object
 *
 */

#pragma once
#include <fstream>
#include "d_matrix.h"
#include <vector>

 // Class declaration
class grid
{

public:

	// Constructor
	grid(std::ifstream& stream);

	// Indexing method
	//
	// int i: The row number of the matrix
	// int j: The column number of the matrix
	char at(const int& i, const int& j) const
	{
		return mat[i][j];
	};

	// TODO: Turn this into findMatches()
	std::vector<std::string> readGrid()const;

private:

	// Private data member - the matrix that contains all of the letters in the
	//  grid
	matrix<char> mat;

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
	void findWords(std::vector<std::string>& vec, const int& direction,
		int& i, int& j) const;

	// Append to the vector of possible words for the letter at the given index
	//  of starti and startj by moving in one of 8 directions. The direction is
	//  Controlled by the function pointer. All possible words in this direction
	//  of:
	//  5 < length < mat.row()/mat.column
	//  are added to the vector.
	//
	//  void(grid::*f)(int &, int &): The function pointer that moves the
	//       indices starti and startj in a certain direction on the grid.
	//  vector<string> vec: The list of all strings of length of at least 5 found
	//       in this grid
	//  int starti: the index of the column of the current item in the matrix
	//  int startj: the index of the row of the current item in the matrix
	void generateWords(void(grid::*f)(int &, int &) const,
		std::vector<std::string>& vec,
		int& i,
		int& j) const;

	// The movement methods. Moves the indixes i and j in a certain direction
	//
	// Decrement j, Move up
	void moveUp(int& i, int& j) const;
	// Increment j, Move down
	void moveDown(int& i, int& j) const;
	// Increment i, Move right
	void moveRight(int& i, int& j) const;
	// Decrement i, Move left
	void moveLeft(int& i, int& j) const;
	// Decrement j + Decrement i, Move up-left
	void moveUL(int& i, int& j) const;
	// Decrement j + Increment i, Move up-right
	void moveUR(int& i, int& j) const;
	// Increment j + Decrement i, Move down-left
	void moveDL(int& i, int& j) const;
	// Increment j + Increment i, move down-right
	void moveDR(int& i, int& j) const;

};

