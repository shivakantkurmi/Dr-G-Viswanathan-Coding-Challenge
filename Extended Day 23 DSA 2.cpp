/*
35. Search Insert Position
Solved
Easy

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
*/

//Link : https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int binarySearch(vector<int>&arr,int l , int r , int target){
        while(l<=r){
            int mid = l+(r-l)/2;
            if(arr[mid]==target)return mid;
            else if(arr[mid]>target)r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};
