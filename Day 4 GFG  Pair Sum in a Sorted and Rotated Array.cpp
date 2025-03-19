/*
Pair Sum in a Sorted and Rotated Array
Given an array of positive elements arr[] that is sorted and then rotated around an unknown point, the task is to check if the array has a pair with sum equals to a given target.
*/

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int rotateind=0;
        for(rotateind=0;rotateind<n-1;rotateind++){
           if(arr[rotateind]>arr[rotateind+1]) break;
        }
        int l=(rotateind+1)%n;
        int r=rotateind;
        while(l!=r){
            if(arr[l]+arr[r]==target) return true;
            if(arr[l]+arr[r]>target) r=(r-1+n)%n;
            else l=(l+1)%n;
        }
        return false;
        
    }
};
