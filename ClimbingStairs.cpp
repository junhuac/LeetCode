// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "ClimbingStairs1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	int stairs = 4;
	int result = solution.ClimbingStairs(stairs);

	cout << result << "\r\n";

	return 0;
}

