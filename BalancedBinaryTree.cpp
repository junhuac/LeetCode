// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "BalancedBinaryTree1.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	Node*  Node1 = new Node();
	Node*  Node2 = new Node();
	Node*  Node3 = new Node();
	Node1->left = Node2;
	Node1->right = Node3;

	Node*  Node4 = new Node();
	Node*  Node5 = new Node();
	Node2->left = Node4;
	Node2->right = Node5;
	Node4->left = NULL;
	Node4->right = NULL;
	Node5->left = NULL;
	Node5->right = NULL;

	Node*  Node6 = new Node();
	Node*  Node7 = new Node();
	Node3->left = Node6;
	Node3->right = Node7;
	Node6->left = NULL;
	Node6->right = NULL;
	Node7->left = NULL;
	Node7->right = NULL;

	int depth = solution.BalancedBinaryTree(Node1);

	cout << ((depth > 0) ? "Balanced" : "Not balanced");

	if (depth > 0)
	{
		cout << ", Depth: " << depth;
	}

	return 0;
}

