/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
File: ConvertSortedListtoBinarySearchTree.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "PrintTree.h"
#include "ConvertSortedListtoBinarySearchTree1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    ListNode *root = new ListNode(1);
    root->pNext = new ListNode(2);
    root->pNext->pNext = new ListNode(3);
    root->pNext->pNext->pNext = new ListNode(4);
    root->pNext->pNext->pNext->pNext = new ListNode(5);
    root->pNext->pNext->pNext->pNext->pNext = new ListNode(6);
    root->pNext->pNext->pNext->pNext->pNext->pNext = new ListNode(7);

    NODE *tree = solution.ConvertSortedListtoBinarySearchTree(root);

    PrintTree(tree);

	return 0;
}

