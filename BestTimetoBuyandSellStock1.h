/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 07/14/2015
Problem: 
	Say you have an array for which the ith element is the price of a given stock on day i.
	If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
	design an algorithm to find the maximum profit..
*/

#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	Solution() {}
	~Solution() {}

	double BestTimetoBuyandSellStock(vector<double> prices)
	{
		double min = prices[0], profit = -min;

		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < min)
			{
				min = prices[i];
			}
			else if (prices[i] - min > profit)
			{
				profit = prices[i] - min;
			}
		}

		return profit;
	}
};