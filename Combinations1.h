/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/22/2015
Notes:
    Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
    For example,
    If n = 4 and k = 2, a solution is:
    [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
    ]
Solution: DFS.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    vector<vector<int>> Combinations(int n, int k)
    {
        vector<vector<int>> result;

        for (int i = 1; i <= n - 1; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                result.push_back(vector<int>({i, j}));
            }
        }

        return result;
    }
};
