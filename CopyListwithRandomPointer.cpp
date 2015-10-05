/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
File: CopyListwithRandomPointer.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "CopyListwithRandomPointer1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    ListNode *root = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(6);
    ListNode *node7 = new ListNode(7);

    root->pNext = node2;
    root->pRandom = node4;
   
    node2->pNext = node3;
    node2->pRandom = node7;
    
    node3->pNext = node4;
    node3->pRandom = node5;

    node4->pNext = node5;
    node4->pRandom = NULL;

    node5->pNext = node6;
    node5->pRandom = root;

    node6->pNext = node7;
    node6->pRandom = NULL;
  
    node7->pNext = NULL;
    node7->pRandom = node5;

    ListNode *list = solution.CopyListwithRandomPointer(root);

    ListNode *node = list;

    cout << "value" << ": " << "Next" << ", " << "Random" << "\r\n";
    while (node != NULL)
    {
        cout << node->value << ": " << (node->pNext == NULL ? 0 : node->pNext->value) << ", " << (node->pRandom == NULL ? 0 : node->pRandom->value) << "\r\n";
        node = node->pNext;
    }

	return 0;
}

