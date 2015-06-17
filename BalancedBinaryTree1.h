/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 06/16/2015
Problem: Given a binary tree, return whether it's balanced or not.
		If the depths of child trees of any node do not differ more than 1,
		then the tree is balanced.
*/

#define max(a, b) (a>b?a:b)

typedef struct _Node
{
	_Node* left;
	_Node* right;
} Node;

class Solution
{
public:
	Solution() {}

	// Returns maximum depth of tree if it's balanced
	// otherwise return -1 if it's not balanced
	int BalancedBinaryTree(Node* root)
	{
		int depth[2];

		if (root)
		{
			depth[0] = BalancedBinaryTree(root->left);
			depth[1] = BalancedBinaryTree(root->right);
		}
		else
		{
			return 0;
		}

		if (depth[0] < 0 || depth[1] < 0)
		{
			return -1;
		}
		else
		{
			return abs(depth[0] - depth[1]) <= 1 ? 1 + max(depth[0], depth[1]) : -1;
		}
	}
};