/*
53. Maximum Subarray
Solved
Medium

Given an integer array nums, find the subarray with the largest sum, and return its sum.
*/

//Link : https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> pre = nums;
		for(int i = 1; i < size(nums); i++) pre[i] += max(0, pre[i-1]);
		return *max_element(begin(pre), end(pre));
	}
};
