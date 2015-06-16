// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

#include "AddTwoNumbers1.h"

using namespace std;

void print(Node* node)
{
	Node* p = node;

	while (p)
	{
		cout << p->value;
		p = p->next;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;
	Node*  Node1 = new Node(vector<int>({ 1, 4, 6 }));
	Node*  Node2 = new Node(vector<int>({ 4, 8, 9, 0 }));
	
	Node* result = solution.AddTwoNumbers(Node1, Node2);

	print(Node1);
	cout << "+";
	print(Node2);
	cout << "=";
	print(result);

	return 0;
}

