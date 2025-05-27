/*
2470. Number of Subarrays With LCM Equal to K
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.

A subarray is a contiguous non-empty sequence of elements within an array.

The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.
*/

//Link : https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/

class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < size(nums); i++) {
            int currLcm = 1;
            for (int j = i; j < size(nums); j++) {
                currLcm = lcm(currLcm, nums[j]);
                if (currLcm == k)
                    cnt++;
                if (currLcm > k)
                    break;
            }
        }
        return cnt;
    }
};
