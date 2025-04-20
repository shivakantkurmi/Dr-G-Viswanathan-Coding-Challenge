/*
Maximum XOR of two numbers in an array
Difficulty: MediumAccuracy: 50.0%Submissions: 23K+Points: 4
Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.

Examples:

Input: arr[] = [25, 10, 2, 8, 5, 3]
Output: 28
Explanation: The maximum possible XOR is 5 ^ 25 = 28.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation : The maximum possible XOR is 1 ^ 6 = 7.
Constraints:
2 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 106
*/


// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &arr) {

        int res = 0, mask = 0;
        unordered_set<int> s;
        for (int i = 30; i >= 0; i--) {
            mask |= (1 << i);
            for (auto value: arr) {
                s.insert(value & mask);
            }
            int cur = res | (1 << i);
            for (int prefix : s) {
                if (s.count(cur ^ prefix)) {
                    res = cur;
                    break;
                }
            }
            s.clear();
        }
        return res;
    }   

};

