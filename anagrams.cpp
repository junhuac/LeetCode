// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "anagrams2.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Anagrams anagrams;
	vector<string> teststrs;
	
	teststrs.push_back("abc");
	teststrs.push_back("acb");
	teststrs.push_back("abd");
	teststrs.push_back("cba");
	teststrs.push_back("cbab");
	teststrs.push_back("dba");
	teststrs.push_back("cab");

	vector<string> result = anagrams.anagrams(teststrs);

	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i].c_str();

		if (strcmp("\r\n", result[i].c_str()) != 0)
		{
			cout << "\t";
		}
	}

	return 0;
}

