/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/05/2015
File: DecodeWays.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>
#include <set>

using namespace std;

#include "IntegerMath.h"

int main(int argc, char* argv[])
{
    Math solution;
    string str = "(4 + 6) / 2";

    Node* root = new Node();
    root->op = Operator::divide;

    root->left = new Node();
    root->left->op = Operator::plus;
   
    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right = new Node(2);

    try
    {
        int result = solution.Evaluate(root);

        cout << str.c_str() << " = " << result << "\r\n";
    }
    catch (exception& e)
    {
        cout << e.what();
    }

	return 0;
}

