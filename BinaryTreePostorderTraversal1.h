/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 08/05/2015
Notes:
	Given a binary tree, return the postorder traversal of its nodes' values.
	For example:
	Given binary tree {1,#,2,3},
	1
	\
	2
	/
	3
	return [3,2,1].

Note: 
	Recursive solution is trivial, could you do it iteratively?
	Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
	2. Recursive solution.      Time: O(n), Space: O(n).
	3. Threaded tree (Morris).  Time: O(n), Space: O(1).
	You may refer to my blog for more detailed explanations:
	http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
	4. Recursive solution#2. transform into preorder traversal and reverse.
	5. Threaded tree (Morris). Time: O(n), Space: O(logn);
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

	vector<int> BinaryTreePostorderTraversal(TreeNode* root)
	{
		vector<int> result;

		stack<TreeNode*> st;

		st.push(root);

		while (st.size() > 0)
		{
			TreeNode* node = st.top();
			st.pop();

			if (NULL != node)
			{
				if ((st.size() > 0 && NULL == st.top()) || (NULL == node->left && NULL == node->right))
				{
					result.push_back(node->val);
				}
				else
				{
					st.push(NULL);
					st.push(node);
					if (NULL != node->right)
					{
						st.push(node->right);
					}
					if (NULL != node->left)
					{
						st.push(node->left);
					}
				}
			}
		}

		return result;
	}
};