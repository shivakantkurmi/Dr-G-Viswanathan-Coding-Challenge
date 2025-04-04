/*
Sorted Array Search
Difficulty: BasicAccuracy: 48.03%Submissions: 351K+Points: 1Average Time: 20m
Given an array, arr[] sorted in ascending order and an integer k. Return true if k is present in the array, otherwise, false.

Examples:

Input: arr[] = [1, 2, 3, 4, 6], k = 6
Output: true
Exlpanation: Since, 6 is present in the array at index 4 (0-based indexing), output is true.
*/


class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // k: element to be searched
    bool searchInSorted(vector<int>& arr, int k) {
        int r=arr.size();
        int l=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==k) return 1;
            else if(arr[mid]>k) r=mid-1;
            else l=mid+1;
        }
        return 0;

    }
};
