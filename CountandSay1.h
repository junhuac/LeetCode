/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
Notes:
    The count-and-say sequence is the sequence of integers beginning as follows:
    1, 11, 21, 1211, 111221, ...
    1 is read off as "one 1" or 11.
    11 is read off as "two 1s" or 21.
    21 is read off as "one 2, then one 1" or 1211.
    Given an integer n, generate the nth sequence.
    Note: The sequence of integers will be represented as a string.
Solution: ...
*/

#include <string>
#include <vector>

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

    string CountandSay(int n)
    {
        if (n == 0)
        {
            return "";
        }
        else if (n == 1)
        {
            return "1";
        }

        string result;
        string pre = CountandSay(n-1);

        for (int i = 0, j; i < pre.length();)
        {
            int num = 0;

            j = i;
            while (j < pre.length() && pre[j] == pre[i])
            {
                num++;
                j++;
            }
            result += '0' + num;
            result += pre[i];
            i = j;
        }

        return result;
    }
};
