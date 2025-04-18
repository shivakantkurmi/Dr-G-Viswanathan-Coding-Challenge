/*
At Least K Occurrences
Difficulty: EasyAccuracy: 37.11%Submissions: 205K+Points: 2Average Time: 20m
Given an array arr. Return the element that occurs at least k number of times.

Note:

If there are multiple answers, please return the first one.
If there is no element found, return -1.
Examples

Input: arr[] = [1, 7, 4, 3, 4, 8, 7], k = 2
Output: 4
Explanation: Both 7 and 4 occur 2 times. But 4 is first that occurs twice. As the index = 4, is the first element.
Input:  arr[] = [3, 1, 3, 4, 5, 1, 3, 3, 5, 4], k = 3
Output: 3
Explanation: Here, 3 is the only number that appeared atleast 3 times in the array.
Input: arr[] = [10, 8, 2], k = 10
Output: -1
Explanation: Here no element is returning atleast 10 number of times, so -1.
Constraints:
1 <= arr.size() <= 106
1 <= k <= 103
0 <= arr[i] <= 106
*/

class Solution {
  public:
    int firstElementKTime(vector<int>& arr, int k) {
        // write code
        unordered_map<int,int> mp;
        for(int i:arr){
            mp[i]++;
            if(mp[i]==k) return i;
        }
        return -1;
    }
};
