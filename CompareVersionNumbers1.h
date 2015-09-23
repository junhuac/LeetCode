/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 09/23/2015
Notes:
    Compare two version numbers version1 and version1.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
    You may assume that the version strings are non-empty and contain only digits and the . character.
    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
    Here is an example of version numbers ordering:
    0.1 < 1.1 < 1.2 < 13.37
Solution: ...
*/

#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 1000;

class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    vector<int> GetVersion(string v)
    {
        vector<int> version;

        char buf[MAX_LENGTH + 1];
        for (int i = 0, j = 0; i <= v.size(); i++)
        {
            if (i == v.size() || v[i] == '.')
            {
                buf[j] = 0;
                version.push_back(atoi(buf));
                j = 0;
            }
            else
            {
                buf[j++] = v[i];
            }
        }

        return version;
    }

    int CompareVersionNumbers(string v1, string v2)
    {
        int result = 0;
        vector<int> version1, version2;

        version1 = GetVersion(v1);
        version2 = GetVersion(v2);

        for (int i = 0; i < min(version1.size(), version2.size()); i++)
        {
            if (version1[i] > version2[i])
            {
                return 1;
            }
            else if (version1[i] < version2[i])
            {
                return -1;
            }
            else
            {
                continue;
            }
        }

        if (result == 0 && version1.size() != version2.size())
        {
            result = version1.size() > version2.size() ? 1 : -1;
        }

        return result;
    }
};
