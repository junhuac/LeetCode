/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Dec 8, 2020
 Problem:    Regular Expression Matching
 Difficulty: High
 Source:     https://leetcode.com/problems/regular-expression-matching/
 Notes:

*/

class Solution {
public:
	bool isMatch(string s, string p) {
		memset(m_V, -1, sizeof(m_V));
		return isMatchHelper(s, p, s.length() - 1, p.length() - 1);
	}

	bool isMatchHelper(string s, string p, int n, int m) {
		if (n < 0 && m < 0) return true;
		else if (n < 0) {
			if (m < 1) return false;

			int j = 1;
			for (j = 1; j <= m; j += 2) {
				if (p[j] != '*') return false;
			}
			return (m % 2 == 1);
		}
		else if (m < 0) return false;

		if (m_V[n][m] != -1) return (m_V[n][m] == 1);

		if (s[n] == p[m] || p[m] == '.') {
			m_V[n][m] = isMatchHelper(s, p, n - 1, m - 1);
		}
		else if (p[m] != '*' && s[n] != p[m]) {
			m_V[n][m] = 0;
		}
		else if (p[m] == '*') {
			if (s[n] != p[m - 1] && p[m - 1] != '.') {
				m_V[n][m] = isMatchHelper(s, p, n, m - 2);
			}
			else {
				m_V[n][m] = isMatchHelper(s, p, n, m - 2) || isMatchHelper(s, p, n - 1, m);
			}
		}

		return (m_V[n][m] == 1);
	}

private:
	char m_V[20][30];
};