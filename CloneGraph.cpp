// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "CloneGraph1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	string strGraph("1#2#2");

    NODE* pNode = solution.UnSerialize(strGraph);
    string Graph = solution.Serialize();
    cout << Graph.c_str() << "\r\n";

    Solution solution2;
    NODE* pClone = solution2.CloneGraph(pNode);
    string Clone = solution2.Serialize();
	cout << Clone.c_str() << "\r\n";

	return 0;
}

