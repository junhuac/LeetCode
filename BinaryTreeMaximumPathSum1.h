/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 07/21/2015
Notes:
	Given a binary tree, find the maximum path sum.
	The path may start and end at any node in the tree.
	For example:
	Given the below binary tree,
	1
	/ \
	2   3
	Return 6.
Solution:
	Recursion...
*/

#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
	TreeNode()
	{
		val = 0;
		left = NULL;
		right = NULL;
	}

	TreeNode(int val)
		:TreeNode()
	{
		this->val = val;
	}

	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution
{
public:
	Solution() {}
	~Solution() {}

	int BinaryTreeMaximumPathSum(TreeNode* root)
	{
		maxpathsum = 0;

		BinaryTreeMaximumPath(root);

		return maxpathsum;
	}

private:
	int BinaryTreeMaximumPath(TreeNode* root)
	{
		int path = 0;
		int pathsum = 0;

		if (NULL == root)
		{
			return 0;
		}

		path = root->val + max(BinaryTreeMaximumPath(root->left), BinaryTreeMaximumPath(root->right));
		pathsum = root->val + BinaryTreeMaximumPath(root->left) + BinaryTreeMaximumPath(root->right);

		if (pathsum > maxpathsum)
		{
			maxpathsum = pathsum;
		}

		return path;
	}

	int maxpathsum;
};