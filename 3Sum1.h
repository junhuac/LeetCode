/*
Given an array of integers, return all triplets which has a sum of 0
*/

#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> intvector;

class Solution
{
public:
	Solution() {}

	vector<intvector> _3Sum(intvector intarray)
	{
		vector<vector<int>> result;

		sort(intarray.begin(), intarray.end());

		for (int i = 0; i < intarray.size() - 2; i++)
		{
			int l = i + 1;
			int r = intarray.size() - 1;

			while (l < r)
			{
				int sum = intarray[i] + intarray[l] + intarray[r];
				if (sum < 0)
				{
					l++;
				}
				else if (sum > 0)
				{
					r--;
				}
				else
				{
					result.push_back(vector<int>({ intarray[i], intarray[l], intarray[r] }));
					l++;
					r--;
				}
			}
		}

		return result;
	}
};