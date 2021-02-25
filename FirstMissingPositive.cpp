// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#include "FirstMissingPositive1.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	vector<int> nums = {1, 2, 0};

	cout << "["  << nums[0];
	for (int i = 1; i < nums.size(); i++) {
		cout << "," << nums[i];
	}

	cout << "]" << endl;

	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	int result = solution.firstMissingPositive(nums);

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

