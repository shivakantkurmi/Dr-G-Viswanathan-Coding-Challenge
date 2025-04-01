/*
Largest subarray with 0 sum
Difficulty: MediumAccuracy: 41.84%Submissions: 398K+Points: 4Average Time: 20m
Given an array arr containing both positive and negative integers, the task is to compute the length of the largest subarray that has a sum of 0.

Examples:

Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
*/

class Solution {
  public:
    int maxLen(vector<int>& arr) {
        unordered_map<int, int>values;
        int sum=0;
        int Max_size=0;
        int n=arr.size();
        
        for (int i = 0; i < n; i++) {
        
            sum += arr[i]; 
            
            if (sum == 0) {
                Max_size=i+1;
            }
            else{
                if(values.find(sum)!=values.end()){
                    Max_size=max(Max_size, i-values[sum]);
                }
                else{
                    values[sum]=i;
                }
            }
        }
        return Max_size;
    }
};
