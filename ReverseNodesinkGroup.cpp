// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <regex>
#include <chrono> 

using namespace std;
using namespace std::chrono;

#include "ReverseNodesinkGroup1.h"

void PrintLinkedList(ListNode* root) {
	ListNode* node = root;

	while (node != nullptr) {
		std::cout << node->val << " ";
		node = node->next;
	}

	std::cout << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Solution solution;

	ListNode* node5 = new ListNode(5);
	ListNode* node4 = new ListNode(4, node5);
	ListNode* node3 = new ListNode(3, node4);
	ListNode* node2 = new ListNode(2, node3);
	ListNode* root = new ListNode(1, node2);

	PrintLinkedList(root);


	// Get starting timepoint 
	auto start = high_resolution_clock::now();

	int k = 3;
	std::cout << "k = " << k << endl;
	ListNode* node = solution.reverseKGroup(root, k);

	// Get ending timepoint 
	auto stop = high_resolution_clock::now();

	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);

	PrintLinkedList(node);

	return 0;
}

