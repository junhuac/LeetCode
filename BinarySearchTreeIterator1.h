/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 07/20/2015
Problem: 
	Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

	Calling next() will return the next smallest number in the BST.

	Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

	Solution: 
	1. Inorder traversal use stack.
	2. Morris Inorder Traversal.
*/

#include <string>
#include <stack>
#include <algorithm>

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

class Iterator
{
public:
	Iterator(TreeNode* root)
	{
		m_stack.push(root);
		init();
	}

	int next()
	{
		if (m_stack.size() == 0)
		{
			return 0;
		}

		TreeNode* node = m_stack.top();
		m_stack.pop();

		if (node->right != NULL)
		{
			m_stack.push(node->right);
			init();
		}

		return node->val;
	}

	bool hasNext()
	{
		return m_stack.size() > 0;
	}

private:
	void init()
	{
		TreeNode* top = m_stack.top();

		while (top != NULL)
		{
			if (top->left != NULL)
			{
				m_stack.push(top->left);
				top = top->left;
			}
			else
			{
				top = NULL;
			}
		}
	}

	stack<TreeNode*> m_stack;
};

class Solution
{
public:
	Solution() {}
	~Solution() {}

	Iterator BinarySearchTreeIterator(TreeNode* root)
	{
		Iterator iterator(root);

		return iterator;
	}
};