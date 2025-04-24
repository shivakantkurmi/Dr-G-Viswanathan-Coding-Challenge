/*
Unique Number III
Difficulty: MediumAccuracy: 49.87%Submissions: 53K+Points: 4Average Time: 20m
Given an array of integers arr[] where, every element appears thrice except for one which occurs once.
Find that element which occurs once.

Examples:

Input: arr[] = [1, 10, 1, 1]
Output: 10
Explanation: 10 occurs once in the array while the other element 1 occurs thrice.
Input: arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]
Output: 3
Explanation: All elements except 3 occurs thrice in the array.
Constraints:
1 ≤ arr.size() ≤ 105
arr.size() % 3 = 1
-109 ≤ arr[i] ≤ 109
*/

class Solution {
  public:
    int getSingle(vector<int> &arr) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0;
            for (int num : arr) {
                if ((num >> i) & 1) {
                    bitSum++;
                }
            }
            if (bitSum % 3 != 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};
