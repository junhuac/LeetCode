/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Feb 25, 2021
 Problem:    Wildcard Matching
 Difficulty: High
 Source:     https://leetcode.com/problems/wildcard-matching/
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
	bool isMatch(string s, string p) {
		if (s.length() == 0) {

			for (int i = 0; i < p.length(); i++) {
				if (p[i] != '*') return false;
			}

			return true;
		}

		if (p.length() == 0) {
			return false;
		}

		vector<bool> v;
		vector<vector<bool>> m;

		for (int i = 0; i <= s.length(); i++) {
			v.push_back(false);
		}

		for (int i = 0; i <= p.length(); i++) {
			m.push_back(v);
		}

		for (int index1 = s.length() - 1; index1 >= 0; index1--) {
			for (int index2 = p.length() - 1; index2 >= 0; index2--) {
				if (m[index2][index1]) {
					continue;
				}
				else if (s[index1] == p[index2] || p[index2] == '?' || p[index2] == '*') {
					if ((index1 == s.length() - 1 && index2 == p.length() - 1) ||
						(index1 == s.length() - 1 && index2 < p.length() - 1 && p[index2 + 1] == '*' && m[index2 + 1][index1 + 1]) ||
						(index1 == s.length() - 1 && p[index2] == '*' && m[index2 + 1][index1]) ||
						(index2 == p.length() - 1 && p[index2] == '*') ||
						(index2 < p.length() - 1 && p[index2] == '*' && m[index2 + 1][index1]) ||
						(index1 < s.length() - 1 && index2 < p.length() - 1 && m[index2 + 1][index1 + 1])) {
						if (p[index2] == '*') {
							int index = index1;
							if (index2 == p.length() - 1 || m[index2 + 1][index1 + 1]) {
								index++;
							}
							for (int i = index; i >= 0; i--) {
								m[index2][i] = true;
							}
						}
						else {
							m[index2][index1] = true;
						}
					}
				}
			}
		}

		return m[0][0];
	}
};