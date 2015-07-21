/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 07/21/2015
Notes:
	Given a binary tree, return the inorder traversal of its nodes' values.
	For example:
	Given binary tree {1,#,2,3},
	1
	\
	2
	/
	3
	return [1,3,2].
	Note: Recursive solution is trivial, could you do it iteratively?
	Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
	2. Recursive solution.      Time: O(n), Space: O(n).
	3. Threaded tree (Morris).  Time: O(n), Space: O(1).
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

	vector<int> BinaryTreeInorderTraversal(TreeNode* root)
	{
		vector<int> result;
		stack<TreeNode*> st;

		TreeNode* node = root;

		while (NULL != node)
		{
			st.push(node);
			node = node->left;
		}

		node = st.top();
		while (NULL != node)
		{
			result.push_back(node->val);
			st.pop();
			if (NULL != node->right)
			{
				node = node->right;
				while (NULL != node)
				{
					st.push(node);
					node = node->left;
				}
			}

			if (st.size() > 0)
			{
				node = st.top();
			}
			else
			{
				node = NULL;
			}
		}

		return result;
	}
};