/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/22/2015
File: Combinations.cpp
Purpose: Defines the entry point for the Combinations console application.
*/

#include <iostream>

#include "Combinations1.h"

using namespace std;

const int maxdigits = 20;

int main(int argc, char* argv[])
{
	Solution solution;

    vector<vector<int>> result = solution.Combinations(4, 2);

    for (int i = 0; i < result.size(); i++)
    {
        cout << "[";
        cout << result[i][0];
        for (int j = 1; j < result[i].size(); j++)
        {
            cout << ",";
            cout << result[i][j];
        }
        cout << "]\r\n";
    }

	return 0;
}

