/*
34. Find First and Last Position of Element in Sorted Array
Solved
Medium

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
*/

//Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans={-1,-1};
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                while(mid>=0 && nums[mid]==target )mid--;
                mid++;
                ans[0]=mid;
                while(mid<nums.size() && nums[mid]==target)mid++;
                ans[1]=mid-1;
                break;
            }
            else if (nums[mid]>target)high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};
