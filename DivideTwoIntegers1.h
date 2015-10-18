/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/16/2015
Notes:
    Divide two integers without using multiplication, division and mod operator.
Solution:
    Use << operator.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution() {}

    int DivideTwoIntegers(int i, int j)
    {
        int k = 0;
        int sign = 0;

        if (i < 0)
        {
            i = -i;
            if (j > 0)
            {
                sign = 1;
            }
        }

        if (j < 0)
        {
            j = -j;
            if (i > 0)
            {
                sign = 1;
            }
        }

        int d = 0;
        int result = 0;
        int temp = 0;

        if (j == 0)
        {
            return INFINITY;
        }

        if (j > i)
        {
            return 0;
        }
        else if (j == i)
        {
            return sign ? -1 : 1;
        }

        while (result < i)
        {
            if (result > i - j)
            {
                break;
            }

            if (d == 0)
            {
                d = 1;
            }
            else
            {
                d << 1;
            }

            if (temp == 0)
            {
                temp = j;
            }
            else
            {
                temp << 1;
            }

            if (result + temp > i)
            {
                d = 0;
                temp = 0;
            }
            else
            {
                k += d;
                result += temp;
            }
        }

        return sign ? -k : k;
    }
};