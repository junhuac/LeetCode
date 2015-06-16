/*
Given an array of integers, find quadruplet (a,b,c,d) who sum is 0
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	Solution() {}

	vector<vector<int>> _4Sum(vector<int> intarray)
	{
		vector<vector<int>> result;

		sort(intarray.begin(), intarray.end());

		for (int i = 0; i < intarray.size() - 4; i++)
		{
			int j = i + 1;

			while (j < intarray.size() - 3)
			{
				int l = j + 1;
				int r = intarray.size() - 1;
				int sum = 0;

				while (l < r)
				{
					sum = intarray[i] + intarray[j] + intarray[l] + intarray[r];
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
						result.push_back(vector<int>({ intarray[i], intarray[j], intarray[l], intarray[r] }));
						l++;
						r--;
					}
				}

				j++;
			}

		}


		return result;
	}
};