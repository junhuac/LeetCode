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
	int trap(vector<int>& height) {
		if (height.size() == 0) return 0;

		vector<int> peaks;
		vector<int> heights;

		int sum = 0;
		int left = 0;
		int right = 0;

		int h = height[0];

		while (left < height.size() - 1 && right < height.size() - 1) {
			while (left < height.size() - 1 && height[left + 1] >= h) {
				left++;
				h = height[left];
			}
			if (peaks.size() == 0) {
				peaks.push_back(left);
				heights.push_back(h);
			}

			right = left;
			while (right < height.size() - 1 && height[right + 1] <= h) {
				right++;
				h = height[right];
			}
			h = height[right];
			while (right < height.size() - 1 && height[right + 1] >= h) {
				right++;
				h = height[right];
			}

			if (height[right] < height[right - 1]) break;

			peaks.push_back(right);
			heights.push_back(h);

			h = min(height[left], height[right]);

			left = right;

			h = height[left];
		}

		if (heights.size() < 2) return 0;

		for (int i = 0; i < heights.size() - 1;) {
			int h = heights[i];

			int index = i + 1;
			int p = heights[index];

			if (p < h) {
				for (int j = index + 1; j < heights.size(); j++) {
					if (heights[j] > p) {
						index = j;
						p = heights[j];

						if (p > h) {
							break;
						}
					}
				}
			}

			int H = min(h, p);
			for (int k = peaks[i] + 1; k < peaks[index]; k++) {
				if (H > height[k]) {
					sum += H - height[k];
				}
			}

			i = index;
		}

		return sum;
	}
};