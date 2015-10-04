/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/02/2015
Notes:
    Given inorder and postorder traversal of a tree, construct the binary tree.
    Note:
    You may assume that duplicates do not exist in the tree.
Solution: Recursion.
*/

#include <vector>

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

    NODE* ConstructBinaryTreefromInorderandPostorderTraversal(vector<int> Inorder, vector<int> Postorder)
    {
        NODE* tree;

        if (Inorder.size() == 0 && Postorder.size() == 0)
        {
            tree = NULL;
        }
        else if (Inorder.size() == 1 && Postorder.size() == 1)
        {
            tree = new NODE(Postorder[0]);
        }
        else if (Inorder.size() == 2 && Postorder.size() == 2)
        {
            tree = new NODE(Postorder[1]);
            if (Inorder[0] == Postorder[0])
            {
                NODE* left = new NODE(Inorder[0]);
                tree->left = left;
                tree->right = NULL;
            }
            else
            {
                NODE* right = new NODE(Postorder[0]);
                tree->left = NULL;
                tree->right = right;
            }
        }
        else
        {
            // Find the root node
            int value = Postorder[Postorder.size() - 1];

            vector<int> left_i, left_p;
            vector<int> right_i, right_p;

            bool root = false;
            for (int i = 0, j = 0; i < Inorder.size() && j < Postorder.size();)
            {
                if (Inorder[i] == value)
                {
                    root = true;
                    i++;
                }
                else if (!root)
                {
                    left_i.push_back(Inorder[i++]);
                    left_p.push_back(Postorder[j++]);
                }
                else
                {
                    right_i.push_back(Inorder[i++]);
                    right_p.push_back(Postorder[j++]);
                }
            }

            NODE* left = ConstructBinaryTreefromInorderandPostorderTraversal(left_i, left_p);
            NODE* right = ConstructBinaryTreefromInorderandPostorderTraversal(right_i, right_p);

            tree = new NODE(value);
            tree->left = left;
            tree->right = right;
        }

        return tree;
    }

};
