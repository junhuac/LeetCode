/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/16/2015
Notes:
    Given a string S and a string T, count the number of distinct subsequences of T in S.
    A subsequence of a string is a new string which is formed from the original string by deleting
    some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
    Here is an example:
    S = "rabbbit", T = "rabbit"
    Return 3.
Solution: dp.
*/

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    typedef map<int, int> MAP;

    Solution() {}

    int DistinctSubsequences(string S, string T)
    {
        int result = 0;

        for (int i = 0; i < S.length(); i++)
        {
            int index = i;
            int j = 0;
            bool found = true;
            for (j = 0; j < T.length(); j++)
            {
                while (index < S.length() && S[index] != T[j])
                {
                    index++;
                }

                if (index == S.length())
                {
                    found = false;
                    break;
                }
                index++;
            }

            if (found)
            {
                result++;
            }
        }

        return result;
    }
};