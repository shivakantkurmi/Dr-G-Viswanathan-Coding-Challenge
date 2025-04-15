/*
Subarray with 0 sum
Difficulty: MediumAccuracy: 39.79%Submissions: 292K+Points: 4Average Time: 20m
Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 

Examples:

Input: arr[] = [4, 2, -3, 1, 6]
Output: true
Explanation: 2, -3, 1 is the subarray with a sum of 0.
*/


class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int> ans;
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==0 || ans.count(sum)>0){
                return true;
            }
            ans.insert(sum);
        }
        return false;
    }
};
