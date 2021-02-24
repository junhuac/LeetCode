/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Jan 18, 2021
 Problem:    Sudoku Solver
 Difficulty: High
 Source:     https://leetcode.com/problems/sudoku-solver/
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
	set<char> getRow(const vector<vector<char>>& board, int row, int col) {
		set<char> st;

		for (int j = 0; j < board[0].size(); j++) {
			st.insert(board[row][j]);
		}

		st.erase('.');

		return st;
	}

	set<char> getCol(const vector<vector<char>>& board, int row, int col) {
		set<char> st;

		for (int i = 0; i < board.size(); i++) {
			st.insert(board[i][col]);
		}

		st.erase('.');

		return st;
	}

	set<char> getSubBox(const vector<vector<char>>& board, int row, int col) {
		set<char> st;

		int r = 3 * (row / 3);
		int c = 3 * (col / 3);

		for (int i = r; i < r + 3; i++) {
			for (int j = c; j < c + 3; j++) {
				st.insert(board[i][j]);
			}
		}

		st.erase('.');

		return st;
	}

	map<vector<int>, set<char>> solveSudokuHelper(vector<vector<char>>& board) {
		map<vector<int>, set<char>> st;

		set<char> test;

		for (int i = 0; i < 9; i++) {
			test.insert('1' + i);
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == '.') {
					st[{ i, j }] = test;
				}
			}
		}

		vector<vector<int>> solved;
		vector<char> sol;

		if (!st.empty()) {
			for (map<vector<int>, set<char>>::iterator itr = st.begin(); itr != st.end(); itr++) {
				vector<int> v = itr->first;
				set<char> row = getRow(board, v[0], v[1]);
				set<char> col = getCol(board, v[0], v[1]);
				set<char> box = getSubBox(board, v[0], v[1]);

				for (set<char>::iterator itr2 = row.begin(); itr2 != row.end(); itr2++) {
					itr->second.erase(*itr2);
				}

				for (set<char>::iterator itr3 = col.begin(); itr3 != col.end(); itr3++) {
					itr->second.erase(*itr3);
				}

				for (set<char>::iterator itr4 = box.begin(); itr4 != box.end(); itr4++) {
					itr->second.erase(*itr4);
				}

				if (itr->second.size() == 1) {
					sol.push_back(*(itr->second.begin()));
					board[v[0]][v[1]] = *(itr->second.begin());
					solved.push_back(v);
				}
			}

			for (int i = 0; i < solved.size(); i++) {
				st.erase(solved[i]);
			}
		}

		int sz = solved.size();

		while (!st.empty()) {
			for (map<vector<int>, set<char>>::iterator itr = st.begin(); itr != st.end(); itr++) {
				vector<int> v = itr->first;

				for (int i = 0; i < solved.size(); i++) {
					if (solved[i][0] == v[0] || solved[i][1] == v[1] || (v[0] / 3 == solved[i][0] / 3 && v[1] / 3 == solved[i][1] / 3)) {
						itr->second.erase(sol[i]);
					}
				}

				if (itr->second.size() == 1) {
					sol.push_back(*(itr->second.begin()));
					board[v[0]][v[1]] = *(itr->second.begin());
					solved.push_back(v);
				}
			}

			for (int i = 0; i < solved.size(); i++) {
				st.erase(solved[i]);
			}

			if (sz == solved.size()) {
				break;
			}

			sz = solved.size();
		}

		return st;
	}

	void solveSudoku(vector<vector<char>>& board) {
		map<vector<int>, set<char>> m;
		queue<vector<vector<char>>> q;

		q.push(board);

		while (!q.empty()) {
			board = q.front();
			q.pop();

			m = solveSudokuHelper(board);

			if (m.empty()) {
				return;
			}

			map<vector<int>, set<char>>::iterator itr0 = m.begin();
			int sz = itr0->second.size();
			for (map<vector<int>, set<char>>::iterator itr = itr0; itr != m.end(); itr++) {
				if (itr->second.size() < sz) {
					itr0 = itr;
					sz = itr->second.size();
				}
			}

			vector<int> v = itr0->first;
			set<char> s = itr0->second;
			int n = m.size();

			for (set<char>::iterator itr2 = s.begin(); itr2 != s.end(); itr2++) {
				vector<vector<char>> b = board;

				b[v[0]][v[1]] = *itr2;

				q.push(b);
			}
		}
	}
};