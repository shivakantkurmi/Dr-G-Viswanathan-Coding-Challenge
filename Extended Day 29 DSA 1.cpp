/*
215. Kth Largest Element in an Array
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
*/

//Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        vector<int> count(maxValue - minValue + 1, 0);

        for (int num : nums) {
            count[num - minValue]++;
        }

        int remaining = k;
        for (int i = count.size() - 1; i >= 0; i--) {
            remaining -= count[i];

            if (remaining <= 0) {
                return i + minValue;
            }
        }

        return -1; // This line should not be reached        
    }
};
