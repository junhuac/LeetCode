/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
Notes:
    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
Solution: Recursion.
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

    NODE* ConvertTree(vector<int>::iterator it, int size)
    {
        if (size <= 0)
        {
            return NULL;
        }

        int npos = size / 2;
        NODE *tree = new NODE(*(it + size / 2));
        tree->left = ConvertTree(it, npos);
        tree->right = ConvertTree(it + npos + 1, size - npos - 1);

        return tree;
    }

    NODE* ConvertSortedArraytoBinarySearchTree(vector<int> nodes)
    {
        NODE *tree = ConvertTree(nodes.begin(), nodes.size());

        return tree;
    }
};
