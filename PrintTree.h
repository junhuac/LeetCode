/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
File: PrintTree.h
Purpose: Prints a tree using breadth first search.
*/

#include <iostream>

#include <queue>

using namespace std;

class NODE
{
public:
    NODE(int v) : value(v), left(NULL), right(NULL) {}

    int value;
    NODE* left;
    NODE* right;
};

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
