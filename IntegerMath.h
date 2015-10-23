/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
Notes:
    integer math solver.  How would you architect, in an OO design, a problem to solve integer arithmetic?

    sample problem: (4 + 6) / 2
Solution:
*/

#include <string>

using namespace std;

enum Operator { minus, plus, time, divide };

class Node
{
public:
    Node() : left(NULL), right(NULL), value(0) {}
    Node(int v) : left(NULL), right(NULL), value(v) {}

    Operator op;
    int value;

    Node* left;
    Node* right;
};

class Math
{
public:
    Math() {}

    Node* BuildTree(string str)
    {
        Node* tree = NULL;

        return tree;
    }

    int Evaluate(string str)
    {
        Node* tree = BuildTree(str);

        int result = Evaluate(tree);

        delete tree;

        return result;
    }

    int Evaluate(Node* tree)
    {
        if (tree == NULL) return 0;
        if (tree->left == NULL && tree->right == NULL) return tree->value;

        int left = Evaluate(tree->left);
        int right = Evaluate(tree->right);

        switch (tree->op)
        {
        case Operator::minus:
            return (left - right);

        case Operator::plus:
            return (left + right);

        case Operator::time:
            return (left*right);

        case Operator::divide:
            if (right == 0)
                return INFINITY;
            else
                return (left / right);

        }

        return 0;
    }
};

