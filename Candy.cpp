// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "Candy1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	vector<int> children = {-3, 1, 100, 99};

	int result = solution.Candy(children);

	cout << result << "\r\n";

	return 0;
}

