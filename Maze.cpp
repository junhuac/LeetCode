/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/27/2015
File: CompareVersionNumbers.cpp
Purpose: Defines the entry point for the CompareVersionNumbers console application.
*/

#include <iostream>

#include "Maze.h"

using namespace std;

const int NUM = 6;

int main(int argc, char* argv[])
{
	Solution solution;

    int maze[] = { 1, 1, 0, 0, 1, 0, 0, 1, 1 };
    vector<pair<int, int>> path = solution.Maze(maze, 3, 3, 2, 2);

    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i].first << "," << path[i].second << "\r\n";
    }

	return 0;
}

