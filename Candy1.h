/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/12/2015
Notes:
	There are N children standing in a line. Each child is assigned a rating value.
	You are giving candies to these children subjected to the following requirements:
	- Each child must have at least one candy.
	- Children with a higher rating get more candies than their neighbors.
	What is the minimum candies you must give?

	Solution: 
	You may refer to https://github.com/AnnieKim/ITint5/blob/master/031_%E5%88%86%E9%85%8D%E7%B3%96%E6%9E%9C.cpp
	1. traverse only once with O(1) space. 2. O(n) space.
	3. recursion + memo.
*/

#include <vector>

using namespace std;

class Solution
{
public:
	Solution() {}
	~Solution() {}

	int Candy(vector<int> children)
	{
		int current = 1;
		int min = current;

		int result = current;

		for (int i = 1; i < children.size(); i++)
		{
			if (children[i] < children[i-1])
			{
				current--;
			}

			if (children[i] > children[i - 1])
			{
				current++;
			}

			if (current < min)
			{
				min = current;
			}

			result += current;
		}

		result += children.size() * (1 - min);

		return result;
	}
};