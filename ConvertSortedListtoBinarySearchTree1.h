/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
Source:     http://leetcode.com/onlinejudge#question_109
Notes:
    Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
Solution: 
1. Recursion. Pre-order. A very good Idea. O(n)
2. Recursion, Binary Search.
*/

#include <vector>

struct ListNode
{
    int value;
    ListNode *pNext;

    ListNode(int v) : value(v), pNext(NULL) {}
};

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

    NODE* ConvertTree(ListNode *begin, ListNode *end)
    {
        if (begin == NULL || (begin == end))
        {
            return NULL;
        }

        ListNode *p1 = begin, *p2 = begin;

        while (p2 != end)
        {
            p2 = p2->pNext;
            if (p2 != end)
            {
                p1 = p1->pNext;
                p2 = p2->pNext;
            }
        }

        NODE *tree = new NODE(p1->value);
        tree->left = ConvertTree(begin, p1);
        tree->right = ConvertTree(p1->pNext, p2);

        return tree;
    }

    NODE* ConvertSortedListtoBinarySearchTree(ListNode *node)
    {
        NODE *tree = ConvertTree(node, NULL);

        return tree;
    }
};
