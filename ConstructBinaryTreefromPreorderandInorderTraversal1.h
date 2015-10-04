/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/03/2015
Notes:
    Given preorder and inorder traversal of a tree, construct the binary tree.
    You may assume that duplicates do not exist in the tree.
Solution: Recursion.
*/

#include <vector>
#include <algorithm>

using namespace std;

class NODE
{
public:
    NODE(int v): value(v), left(NULL), right(NULL) {}

    int value;
    NODE* left;
    NODE* right;
} ;


class Solution
{
public:
    Solution()
    {
    }

    ~Solution()
    {
    }

    NODE* BuildTree(vector<int>::iterator It_Preorder, vector<int>::iterator It_Inorder, int size)
    {
        NODE *tree, *left, *right;

        if (size == 0)
        {
            return NULL;
        }

        tree = new NODE(*It_Preorder);

        vector<int>::iterator it = find(It_Inorder, It_Inorder + size, *It_Preorder);

        int npos = it - It_Inorder;
        left = BuildTree(It_Preorder + 1, It_Inorder, npos);
        right = BuildTree(It_Preorder + npos + 1, it + 1, size - npos - 1);

        tree->left = left;
        tree->right = right;

        return tree;
    }

    NODE* ConstructBinaryTreefromPreorderandInorderTraversal(vector<int> Preorder, vector<int> Inorder)
    {
        NODE* tree = BuildTree(Preorder.begin(), Inorder.begin(), Inorder.size());

        return tree;
    }

};
