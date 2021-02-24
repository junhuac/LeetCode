// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#include "SudokuSolver1.h"

void PrintBoard(const vector<vector<char>>& board)
{
	for(int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	//vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

	vector<vector<char>> board = {{'.', '.', '9', '7', '4', '8', '.', '.', '.'}, {'7', '.', '.', '.', '.', '.', '.', '.', '.'}, {'.', '2', '.', '1', '.', '9', '.', '.', '.'}, {'.', '.', '7', '.', '.', '.', '2', '4', '.'}, {'.', '6', '4', '.', '1', '.', '5', '9', '.'}, {'.', '9', '8', '.', '.', '.', '3', '.', '.'}, {'.', '.', '.', '8', '.', '3', '.', '2', '.'}, {'.', '.', '.', '.', '.', '.', '.', '.', '6'}, {'.', '.', '.', '2', '7', '5', '9', '.', '.'}};

	PrintBoard(board);

	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	solution.solveSudoku(board);

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	PrintBoard(board);

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	return 0;
}

