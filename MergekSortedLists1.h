/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Dec 8, 2020
 Problem:    Regular Expression Matching
 Difficulty: High
 Source:     https://leetcode.com/problems/regular-expression-matching/
 Notes:

*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <queue>

struct comparenode {
	bool operator () (ListNode* node1, ListNode* node2) const {
		if (node1 == NULL && node2 == NULL) return false;
		else if (node1 == NULL) return false;
		else if (node2 == NULL) return true;
		else return (node1->val > node2->val);
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, comparenode> q;

		ListNode* root = NULL;
		ListNode* curr = NULL;

		for (int i = 0; i < lists.size(); i++) {
			q.push(lists[i]);
		}

		while (!q.empty()) {
			ListNode* top = q.top();

			if (root == NULL) {
				root = curr = top;
			}
			else {
				curr->next = top;
				curr = curr->next;
			}

			q.pop();

			if (top != NULL && top->next != NULL) q.push(top->next);
		}

		return root;
	}
}; #pragma once
