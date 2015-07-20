// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "BinarySearchTreeIterator1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	TreeNode *root = new TreeNode(2);
	TreeNode *left = new TreeNode(1);
	TreeNode *right = new TreeNode(4);
	TreeNode *left2 = new TreeNode(3);
	TreeNode *right2 = new TreeNode(5);

	root->left = left;
	root->right = right;
	right->left = left2;
	right->right = right2;

	Iterator iterator = solution.BinarySearchTreeIterator(root);

	while (iterator.hasNext())
	{
		cout << iterator.next() << "\r\n";
	}

	return 0;
}

