/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/12/2015
Notes:
	You are climbing a stair case. It takes n steps to reach to the top.
	Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Solution: 
	Clime one step from last stair or clime 2 steps from the last last stair.
*/

#include <vector>

using namespace std;

class Solution
{
public:
	Solution() {}
	~Solution() {}

	int ClimbingStairs(int stairs)
	{
		int result = 0;

		if (0 >= stairs)
		{
			result = 0;
		}
		else if (1 == stairs)
		{
			result = 1;
		}
		else if (2 == stairs)
		{
			result = 2;
		}
		else
		{
			result = ClimbingStairs(stairs - 1) + ClimbingStairs(stairs - 2);
		}

		return result;
	}
};