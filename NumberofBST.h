/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/07/2015
Notes:
    // Given an integer, say n = 3, how many unique BST can be to store values: 1...n
    // 1, 2, 3

    1
    \
    2
    /
    3

    2
    / \
    1   3
Solution: 
*/

#include <list>
#include <unordered_map>

using namespace std;

int NumofBST(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        int total = 0;

        for (int i = 1; i <= n; i++)
        {
            total += NumofBST(i - 1) * NumofBST(n - i);
        }

        return total;
    }

}

