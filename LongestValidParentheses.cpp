// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#include "LongestValidParentheses1.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	string s = "(()";

	std::cout << s << endl;

	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	int result = solution.longestValidParentheses(s);

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	cout << result << endl;

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

	return 0;
}

