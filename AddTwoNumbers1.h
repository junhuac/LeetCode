/*
Author: Junhua Chang
Email: junhuac@hotmail.com
Date: 06/16/2015
Problem: Given 2 linked lists with a single digit stored in each node (least significant digit stored at head), 
		return another linked list representing the sum.
*/

#include <vector>

using namespace std;

class Node
{
public:
	Node()
	{
		value = 0;
		next = NULL;
	}

	Node(vector<int> intarray)
		:Node()
	{
		Node* node = this;
		Node* parent = this;

		for (unsigned int i = 0; i < intarray.size(); i++)
		{
			if (!node)
			{
				node = new Node();
			}

			node->value = intarray[i];
			node->next = NULL;

			parent->next = node;
			parent = node;

			node = NULL;
		}
	}

	int value;
	Node* next;
};

class Solution
{
public:
	Solution() {}

	Node* AddTwoNumbers(Node* Node1, Node* Node2)
	{
		Node* node = NULL;
		Node* root = node;
		int carry = 0;

		Node* parent = root;

		while (carry || Node1 || Node2)
		{
			node = new Node();

			if (!root)
			{
				root = node;
			}

			if (parent)
			{
				parent->next = node;
			}

			parent = node;

			int value = carry;
			
			if (Node1)
			{
				value += Node1->value;
				Node1 = Node1->next;
			}

			if (Node2)
			{
				value += Node2->value;
				Node2 = Node2->next;
			}

			node->value = value % 10;
			carry = value / 10;
		}

		return root;
	}
};

