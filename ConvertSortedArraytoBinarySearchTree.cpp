/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 10/04/2015
File: ConvertSortedArraytoBinarySearchTree.cpp
Purpose: Defines the entry point for the console application.
*/

#include <iostream>

#include "PrintTree.h"
#include "ConvertSortedArraytoBinarySearchTree1.h"

using namespace std;

int main(int argc, char* argv[])
{
	Solution solution;

    vector<int> nodes = { 1, 2, 3, 4, 5, 6, 7 };
  
    NODE *tree = solution.ConvertSortedArraytoBinarySearchTree(nodes);

    PrintTree(tree);

	return 0;
}

