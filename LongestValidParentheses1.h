/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Jan 18, 2021
 Problem:    Longest Valid Parentheses
 Difficulty: High
 Source:     https://leetcode.com/problems/longest-valid-parentheses/
 Notes:

*/

#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <stack>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;

		for (int i = 0; i < s.length(); i++) {
			if (st.empty()) {
				st.push(i);
			}
			else {
				int e = st.top();
				if (s[e] == '(' && s[i] == ')') {
					st.pop();
				} else {
					st.push(i);
				}
			}
		}

		if (st.empty()) {
			return s.length();
		}
		else {
			int index = s.length();
			int max = 0;

			while (!st.empty()) {
				int e = st.top();
				st.pop();

				if (index - e - 1 > max) {
					max = index - e - 1;
				}

				index = e;
			}

			if (index > max) {
				max = index;
			}
			return max;
		}
	}
};