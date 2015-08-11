// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include "BinaryTreeZigzagLevelOrderTraversal1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	TreeNode *root = new TreeNode(2);
	TreeNode *left = new TreeNode(-1);
	TreeNode *right = new TreeNode(4);
	TreeNode *left2 = new TreeNode(3);
	TreeNode *right2 = new TreeNode(5);

	root->left = left;
	root->right = right;
	right->left = left2;
	right->right = right2;

	vector<vector<int>> result = solution.BinaryTreeZigzagLevelOrderTraversal(root);

	cout << "[\r\n";
	for (int i = 0; i < result.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j];
			if (j < result[i].size() - 1)
			{
				cout << ", ";
			}
		}
		cout << "]";
		if (i < result.size() - 1)
		{
			cout << ",";
		}
		cout << "\r\n";
	}
	cout << "]\r\n";

	return 0;
}

