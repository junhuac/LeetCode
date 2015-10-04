/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/02/2015
File: ConstructBinaryTreefromInorderandPostorderTraversal.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "ConstructBinaryTreefromInorderandPostorderTraversal1.h"

#include <queue>

using namespace std;

void PrintTree(NODE* node)
{
    int tabs = 4;
    queue<NODE*> q;

    q.push(node);
    q.push(NULL);

    for (int i = 0; i < tabs; i++)
    {
        cout << "\t";
    }

    while (!q.empty())
    {
        NODE* n = q.front();
        q.pop();

        if (n != NULL)
        {
            cout << n->value;

            for (int i = 0; i < 2 * tabs; i++)
            {
                cout << "\t";
            }

            if (n->left != NULL)
            {
                q.push(n->left);
            }

            if (n->right != NULL)
            {
                q.push(n->right);
            }
        }
        else
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            cout << "\r\n";
          
            tabs /= 2;

            for (int i = 0; i < tabs; i++)
            {
                cout << "\t";
            }
        }
    }
}

int main(int argc, char* argv[])
{
	Solution solution;

    vector<int> Inorder = { 1, 2, 3, 4, 5, 6, 7 };
    vector<int> Postorder = { 1, 3, 2, 5, 7, 6, 4 };
  
    NODE* tree = solution.ConstructBinaryTreefromInorderandPostorderTraversal(Inorder, Postorder);

    PrintTree(tree);

	return 0;
}

