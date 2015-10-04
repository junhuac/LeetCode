/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
Notes:
    Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
    n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
    Find two lines, which together with x-axis forms a container, such that the container contains the most water.
    
    You may not slant the container.
Solution: From both sides to the center.
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

    vector<int> ContainerWithMostWater(vector<int> container)
    {
        int maxvolume = 0;
        vector<int> result;

        for (int i = 0; i < container.size() - 1; i++)
        {
            for (int j = i + 1; j < container.size(); j++)
            {
                int volume = (j - i) * min(container[i], container[j]);

                if (volume > maxvolume)
                {
                    maxvolume = volume;
                    result = { container[i], container[j] };
                }
            }
        }

        return result;
    }
};
