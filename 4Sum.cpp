// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "4Sum1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	vector<int> testints = {-5, -3, -2, -1, -1, 0, 2, 3, 5, 7, 8};
	
	vector<vector<int>> result = solution._4Sum(testints);

	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << "( ";
		for (unsigned int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
			cout << " ";
		}
		cout << ")";

		cout << "\r\n";
	}

	return 0;
}

