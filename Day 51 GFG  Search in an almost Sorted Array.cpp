/*
Search in an almost Sorted Array
Difficulty: MediumAccuracy: 56.81%Submissions: 10K+Points: 4Average Time: 20m
Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.

Examples:

Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 40
Output: 2
Explanation: Index of 40 in the given array is 2.
Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 90
Output: -1
Explanation: 90 is not present in the array.
Input: arr[] = [-20], target = -20
Output: 0
Explanation: -20 is the only element present in the array.
Constraints:
1 <= arr.size() <= 105
-109 <= arr[i] <= 109


*/

// link : https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1


class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
       int st=0,end=n-1;
       while(st<=end)
       {
           
           int mid=(st+end)/2;
          // find the taher at mid 
           if(arr[mid]==target)return mid;
           
           
           // for if arr[i] change with arr[i-1]
           
           
           else if(mid>st&&arr[mid]<arr[mid-1])
           {
               if(arr[mid-1]==target)return mid-1;
               else if(arr[mid-1]>target)end=mid-1;
               else st=mid+1;
           }
           
           
           // for if arr[i]  change arr[i+1]
           else if(mid<n-1&&arr[mid]>arr[mid+1])
           {
                if(arr[mid+1]==target)return mid+1;
               else if(arr[mid+1]>target)end=mid-1;
               else st=mid+1;
           }
           
           
           // for if arr[i] not change its position
           else 
           {
               if(arr[mid]>target)end=mid-1;
               else st=mid+1;
           }
       }
       
       return -1;
        
    }
};
