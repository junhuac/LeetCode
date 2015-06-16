// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "AddBinary1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	string  teststring1 = "10110101001010";
	string  teststring2 = "111001010101001010";
	
	string result = solution.AddBinary(teststring1, teststring2);

	cout << teststring1.c_str() << " + " << teststring2.c_str() << " = " << result.c_str();

	return 0;
}

