/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
Source:     http://leetcode.com/onlinejudge#question_109
Notes:
    A linked list is given such that each node contains an additional random pointer
    which could point to any node in the list or null.
    Return a deep copy of the list.
Solution: Solution 1 uses constant extra space.
*/

#include <vector>

struct ListNode
{
    int value;
    ListNode *pNext;
    ListNode *pRandom;
    ListNode *pCopy;

    ListNode(int v) : value(v), pNext(NULL), pRandom(NULL), pCopy(NULL) {}
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

    ListNode* CopyListwithRandomPointer(ListNode *node)
    {
        if (node == NULL)
        {
            return NULL;
        }

        ListNode *p = node;

        while (p != NULL)
        {
            if (p->pCopy == NULL)
            {
                p->pCopy = new ListNode(p->value);
            }

            if (p->pNext != NULL)
            {
                if (p->pNext->pCopy == NULL)
                {
                    p->pNext->pCopy = new ListNode(p->pNext->value);
                }
                p->pCopy->pNext = p->pNext->pCopy;
            }
     
            if (p->pRandom != NULL)
            {
                if (p->pRandom->pCopy == NULL)
                {
                    p->pRandom->pCopy = new ListNode(p->pRandom->value);
                }
                p->pCopy->pRandom = p->pRandom->pCopy;
            }

            p = p->pNext;
        }

        return node->pCopy;
    }
};
