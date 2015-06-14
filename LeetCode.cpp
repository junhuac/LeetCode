// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "anagrams.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Anagrams anagrams;
	vector<string> teststrs;
	
	teststrs.push_back("abc");
	teststrs.push_back("acb");
	teststrs.push_back("acbd");

	vector<string> result = anagrams.anagrams(teststrs);

	for (unsigned int i = 0; i < result.size(); i++)
	{
		cout << result[i].c_str() << " ";
	}

	return 0;
}

