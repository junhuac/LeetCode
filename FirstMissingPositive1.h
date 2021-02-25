/*
 Author:     Junhua Chang, junhuac@hotmail.com
 Date:       Feb 24, 2021
 Problem:    First Missing Positive
 Difficulty: High
 Source:     https://leetcode.com/problems/first-missing-positive/
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
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() == 0) return 1;

		set<int> st;
		long min = numeric_limits<int>::max();
		long max = 0;
		long sum = 0;
		long total = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= 0) continue;
			if (st.find(nums[i]) != st.end()) continue;

			st.insert(nums[i]);

			if (nums[i] < min) min = nums[i];

			if (nums[i] > max) max = nums[i];

			sum += nums[i];
		}

		if (max == 0 || min != 1) return 1;

		if (min == max) return max + 1;

		total = (min + max) * (max - min + 1) / 2;

		if (total == sum) {
			return max + 1;
		}
		else {
			for (int i = min + 1; i < max; i++) {
				if (st.find(i) == st.end()) {
					return i;
				}
			}
		}

		return 1;
	}
};