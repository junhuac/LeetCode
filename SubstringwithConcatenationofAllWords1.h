/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Jan 14, 2021
 Problem:    Substring with Concatenation of All Words
 Difficulty: High
 Source:     https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 Notes:

*/

#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		int w = words[0].length();
		map<string, int> m;
		for (int i = 0; i < words.size(); i++) {
			m[words[i]]++;
		}
		int l = s.length();
		vector<queue<map<string, int>::iterator>> v(l);

		for (int i = l - 1; i >= 0; i--) {
			string str = s.substr(i, w);
			map<string, int>::iterator itr = m.find(str);
			if (itr != m.end()) {
				int index = i + w;

				if (index < l) {
					v[i] = v[index];
				}

				v[i].push(itr);
				if (v[i].size() > words.size()) {
					v[i].pop();
				}

				if (v[i].size() == words.size()) {
					queue<map<string, int>::iterator> q = v[i];
					map<string, int> t = m;

					while (!q.empty()) {
						map<string, int>::iterator e = q.front();
						q.pop();

						t[e->first]--;

						if (t[e->first] == 0) {
							t.erase(e->first);
						}
					}

					if (t.empty()) {
						result.push_back(i);
					}
				}
			}
		}

		sort(result.begin(), result.end());

		return result;
	}
};