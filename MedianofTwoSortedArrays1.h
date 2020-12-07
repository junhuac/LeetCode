class Solution {
public:

	int GetMinimum(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > 0 && nums2.size() > 0)
		{
			return min(nums1[0], nums2[0]);
		}
		else if(nums1.size() > 0)
		{
			return nums1[0];
		}
		else if (nums2.size() > 0)
		{
			return nums2[0];
		}
		else
		{
			return 0;
		}
	}

	int GetMaximum(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > 0 && nums2.size() > 0)
		{
			return max(nums1[nums1.size() - 1], nums2[nums2.size() - 1]);
		}
		else if (nums1.size() > 0)
		{
			return nums1[nums1.size() - 1];
		}
		else if (nums2.size() > 0)
		{
			return nums2[nums2.size() - 1];
		}
		else
		{
			return 0;
		}
	}

	int GetIndex(vector<int>& nums, double num, int& left, int& right) {
		if (nums.size() == 0)
		{
			return 0;
		}

		left = 0;
		right = nums.size() - 1;

		if (num <= nums[0]) {
			right = 0;
			return 0;
		}

		if (num >= nums[nums.size() - 1]) {
			left = nums.size() - 1;
			return nums.size() - 1;
		}

		int index = (left + right) / 2;
		int number = num;

		while (left < right && nums[index] != number && index != left && index != right) {
			if (num < nums[index]) {
				right = index;
			}
			else {
				left = index;
			}

			index = (left + right) / 2;
		}

		if (nums[index] < num)
		{
			left = index;
			right = index == nums.size() - 1 ? index : index + 1;
		}
		else if(nums[index] > num)
		{
			left = index == 0 ? 0 : index - 1;
			right = index;
		}
		else
		{
			left = right = index;
		}

		return index;
	}

	int GetIndex(vector<int>& nums1, vector<int>& nums2, double num, int& left, int& right, int& floor, int& ceiling) {
		int number1 = 0;
		int left1 = 0;
		int right1 = 0;

		int number2 = 0;
		int left2 = 0;
		int right2 = 0;

		int index1 = GetIndex(nums1, num, left1, right1);
		int index2 = GetIndex(nums2, num, left2, right2);

		left = 0;
		right = 0;

		int index = index1;

		if (nums1.size() > 0)
		{
			while (index >= 0 && nums1[index] >= num) index--;
			left += index + 1;
		}

		index = index2;
		if (nums2.size() > 0)
		{
			while (index >= 0 && nums2[index] >= num) index--;
			left += index + 1;
		}


		index = index1;
		if (nums1.size() > 0)
		{
			while (index >= 0 && index < nums1.size() && nums1[index] <= num) index++;
			if (index < (int)(nums1.size()))
			{
				right += nums1.size() - index;
			}
		}

		index = index2;
		if (nums2.size() > 0)
		{
			while (index >= 0 && index < nums2.size() && nums2[index] <= num) index++;
			if (index < (int)(nums2.size()))
			{
				right += nums2.size() - index;
			}
		}

		if (nums1.size() > 0 && nums2.size() > 0)
		{
			if (nums1[left1] == num || nums2[left2] > num) {
				floor = nums1[left1];
			} else if (nums2[left2] == num || nums1[left1] > num) {
				floor = nums2[left2];
			}else {
				floor = max(nums1[left1], nums2[left2]);
			}
		}
		else if (nums1.size() > 0)
		{
			floor = nums1[left1];
		}
		else if (nums2.size() > 0)
		{
			floor = nums2[left2];
		}
		else
		{
			floor = 0;
		}

		if (nums1.size() > 0 && nums2.size() > 0)
		{
			if (nums1[right1] == num || nums2[right2] < num) {
				ceiling = nums1[right1];
			}
			else if (nums2[right2] == num || nums1[right1] < num) {
				ceiling = nums2[right2];
			}
			else {
				ceiling = min(nums1[right1], nums2[right2]);
			}
		}
		else if (nums1.size() > 0)
		{
			ceiling = nums1[right1];
		}
		else if (nums2.size() > 0)
		{
			ceiling = nums2[right2];
		}
		else
		{
			ceiling = 0;
		}

		return left;
	}

	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		int left = 0;
		int mid = 0;
		int right = size;
		int minimum = GetMinimum(nums1, nums2);
		int maximum = GetMaximum(nums1, nums2);
		int floor = 0;
		int ceiling = 0;

		double median = (minimum + maximum) / 2.0;
		floor = minimum;
		ceiling = maximum;

		while (left != right) {
			GetIndex(nums1, nums2, median, left, right, floor, ceiling);

			mid = nums1.size() + nums2.size() - left - right;

			double midpoint = (nums1.size() + nums2.size()) / 2.0;

			if (midpoint > left && midpoint - left < mid)
			{
				return median;
			}

			if (left < right) {
				minimum = ceiling;
			}
			else if (left > right)
			{
				maximum = floor;
			}
			else
			{
				break;
			}

			median = (minimum + maximum) / 2.0;
		}

		return (floor + ceiling) / 2.0;
	}
};