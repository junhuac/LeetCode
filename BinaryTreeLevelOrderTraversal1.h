/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 07/21/2015
Notes:
	Given a binary tree, return the level order traversal of its nodes' values.
	(ie, from left to right, level by level).
	For example:
	Given binary tree {3,9,20,#,#,15,7},
	3
	/ \
	9  20
	/  \
	15   7
	return its level order traversal as:
	[
	[3],
	[9,20],
	[15,7]
	]

	Solution: 
	1. Use queue. In order to seperate the levels, use 'NULL' as the end indicator of one level.
	2. DFS.
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

	vector<vector<int>> BinaryTreeLevelOrderTraversal(TreeNode* root)
	{
		vector<vector<int>> result;
		queue<TreeNode*> children;
		queue<TreeNode*> grandchildren;

		children.push(root);

		TreeNode* node = NULL;

		while (children.size() > 0)
		{
			vector<int> level;

			while (children.size() > 0)
			{
				node = children.front();
				children.pop();
				level.push_back(node->val);

				if (NULL != node->left)
				{
					grandchildren.push(node->left);
				}

				if (NULL != node->right)
				{
					grandchildren.push(node->right);
				}
			}

			result.push_back(level);
			queue<TreeNode*> temp = children;
			children = grandchildren;
			grandchildren = temp;
		}

		return result;
	}
};