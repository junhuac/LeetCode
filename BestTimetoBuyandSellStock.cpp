// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "BestTimetoBuyandSellStock1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;


	double profit = solution.BestTimetoBuyandSellStock(vector<double>({101.0, 5.0, 8.0, 99.9, 0.05}));

	cout << "Maximum profit:" << profit << "\r\n";

	return 0;
}

