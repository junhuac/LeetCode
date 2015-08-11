/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/11/2015
Notes:
	Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left
	to right, then right to left for the next level and alternate between).
	For example:
	Given binary tree {3,9,20,#,#,15,7},
	3
	/ \
	9  20
	/ \
	15  7
	return its zigzag level order traversal as:
	[
	[3],
	[20,9],
	[15,7]
	]
Solution: 
	1. Queue + reverse.
	2. Two stacks.
	3. Vector. Contributed by yinlinglin.
*/

#include <vector>
#include <stack>

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

	vector<vector<int>> BinaryTreeZigzagLevelOrderTraversal(TreeNode* root)
	{
		int direction = 0;
		vector<vector<int>> result;

		stack<TreeNode*> st0, st1;

		st0.push(root);

		while (st0.size() > 0 || st1.size() > 0)
		{
			vector<int> level;

			if (0 == direction)
			{
				while (st0.size() > 0)
				{
					TreeNode* node = st0.top();
					level.push_back(node->val);
					st0.pop();


					if (NULL != node->left)
					{
						st1.push(node->left);
					}

					if (NULL != node->right)
					{
						st1.push(node->right);
					}
				}
				direction = 1;
			}
			else
			{
				while (st1.size() > 0)
				{
					TreeNode* node = st1.top();
					level.push_back(node->val);
					st1.pop();

					if (NULL != node->right)
					{
						st0.push(node->right);
					}

					if (NULL != node->left)
					{
						st0.push(node->left);
					}
				}
				direction = 0;
			}

			result.push_back(level);
		}

		return result;
	}
};