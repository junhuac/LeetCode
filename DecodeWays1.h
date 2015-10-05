/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
Notes:
    A message containing letters from A-Z is being encoded to numbers using the following mapping:
    'A' -> 1
    'B' -> 2
    ...
    'Z' -> 26
    Given an encoded message containing digits, determine the total number of ways to decode it.
    For example,
    Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
    The number of ways decoding "12" is 2.
Solution: 1. dp. Note that '0' must be decoded in together with the number in front of it.
2. dp. Time : O(n); Space : O(1).
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

    int DecodeWays(string msg)
    {
        int num = 0;

        if (msg.length() == 0)
        {
            return 0;
        }
        else if (msg.length() == 1)
        {
            return 1;
        }
        else if (msg.length() == 2)
        {
            return 1 + (atoi(msg.c_str()) <= 26);
        }

        num = DecodeWays(msg.substr(1, msg.length() - 1));
        if (atoi(msg.substr(0, 2).c_str()) <= 26)
        {
            num += DecodeWays(msg.substr(2, msg.length() - 2));
        }

        return num;
    }
};
