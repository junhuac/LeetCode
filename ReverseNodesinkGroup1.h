/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Jan 12, 2021
 Problem:    Reverse Nodes in k-Group
 Difficulty: High
 Source:     https://leetcode.com/problems/reverse-nodes-in-k-group/
 Notes:

*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* newhead = nullptr;
		ListNode* node = head;
		ListNode* knode = head;

		ListNode* oldnode = nullptr;

		while (knode != nullptr) {
			int i = 1;
			for (; i < k; i++) {
				if (knode != nullptr) {
					knode = knode->next;
				} else {
					break;
				}
			}

			if (knode != nullptr) {
				reverseHelper(node, knode);
			}

			if (oldnode != nullptr) {
				oldnode->next = node;
			}
			oldnode = knode;

			if (newhead == nullptr) newhead = node;

			if (knode != nullptr) {
				node = knode->next;
			}
			else {
				node = nullptr;
			}
			knode = node;
		}

		return newhead;
	}

	ListNode* reverseHelper(ListNode*& head, ListNode*& tail) {
		if (head == nullptr) return nullptr;

		ListNode* node = head;
		ListNode* next = head->next;

		if (next == nullptr) return head;

		ListNode* nextnext = next->next;

		ListNode* tailnext = nullptr;

		if (tail != nullptr) {
			tailnext = tail->next;
		}

		while (node != nullptr && next != nullptr && node != tail) {
			next->next = node;
			node = next;

			ListNode* oldnextnext = nextnext;

			if (nextnext != nullptr) {
				nextnext = nextnext->next;
			}

			next = oldnextnext;
		}

		head->next = tailnext;

		swap(head, tail);

		return head;
	}
};
