// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "CloneGraph1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	string Graph("1#2#0,2");

	string Clone = solution.CloneGraph(Graph);

	cout << Clone.c_str() << "\r\n";

	return 0;
}

