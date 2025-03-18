/*
3 Sum - Triplet Sum in Array

Given an array arr[] of size n and an integer sum, the task is to check if there is a triplet in the array which sums up to the given target sum.

Examples: 
Input: arr[] = [1, 4, 45, 6, 10, 8], target = 13
Output: true 
Explanation: The triplet [1, 4, 8] sums up to 13
*/

//solution 1: can use 3 loop and check (O(n^3))

//Solution 2 : by using Hashing (O(n^2)) time and O(n) space complexity 
class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            unordered_set<int>st;
            for(int j=i+1;j<n;j++){
                int second=target-arr[i]-arr[j];
                if(st.find(second)!=st.end()) return true;
                st.insert(arr[j]);
            }
        }
        return false;
    }
};

//Solution 3 : Using Sorting + Two pointer O(n^2) time ans O(1) Space complexity
class Solution {
  public:
    bool hasTripletSum(vector<int>& arr, int target) {
      int n = arr.size();
      sort(arr.begin(), arr.end());
    
      // Fix the first element as arr[i] 
      for (int i = 0; i < n - 2; i++) {
      
          // Initialize left and right pointers with 
          // start and end of remaining subarray
          int l = i + 1, r = n - 1;
      
          int requiredSum = target - arr[i];
          while(l < r) {
              if(arr[l] + arr[r] == requiredSum)
                  return true;
              if(arr[l] + arr[r] < requiredSum)
                  l++;
              else if(arr[l] + arr[r] > requiredSum)
                  r--;
        }
    } 
};
