/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Dec 5, 2020
 Problem:    Recover Binary Search Tree
 Difficulty: High
 Source:     https://leetcode.com/problems/recover-binary-search-tree/
 Notes:
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.

Constraints:

The number of nodes in the tree is in the range [2, 1000].
-231 <= Node.val <= 231 - 1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
	TreeNode* recoverTreeHelper(TreeNode* root, TreeNode* prev, TreeNode*& first, TreeNode*& second) {
		if (root == nullptr) return root;

		TreeNode* mid = nullptr;
		TreeNode* next = root;

		if (root->left != nullptr) {
			next = recoverTreeHelper(root->left, prev, first, mid);

			if (root->val < next->val) {
				if (mid == nullptr) {
					first = next;
					mid = root;
				}
				else {
					second = root;
				}
			}
		}
		else {
			if (prev != nullptr && root->val < prev->val) {
				first = prev;
				mid = root;
			}
		}

		if (root->right != nullptr) {
			next = recoverTreeHelper(root->right, root, mid, second);
		}
		else {
			next = root;
		}

		if (first == nullptr) {
			first = mid;
		}

		if (second == nullptr) {
			second = mid;
		}

		return next;
	}

	void recoverTree(TreeNode* root) {
		TreeNode* first = nullptr;
		TreeNode* second = nullptr;

		recoverTreeHelper(root, nullptr, first, second);

		if (first != nullptr && second != nullptr) {
			swap(first->val, second->val);
		}
	}
}; #pragma once
