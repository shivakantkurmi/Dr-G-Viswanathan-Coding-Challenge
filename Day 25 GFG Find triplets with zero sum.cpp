/*
Find triplets with zero sum
Difficulty: MediumAccuracy: 25.81%Submissions: 337K+Points: 4Average Time: 20m
Given an array arr[] of integers, determine whether it contains a triplet whose sum equals zero. Return true if such a triplet exists, otherwise, return false.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: true
Explanation: The triplet [0, -1, 1] has a sum equal to zero.
*/

class Solution {
  public:
    // Function to find triplets with zero sum.
    bool findTriplets(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n-2;i++) {
            int ans1=arr[i];
            
            int j=i+1,k=n-1;
            while(j<k)
            {
                if(ans1+arr[j]+arr[k]==0)
                return true;
                else if(ans1+arr[j]+arr[k]>0)
                k--;
                else
                j++;
                
            }
        }
        return false;
    }
};
