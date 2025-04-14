/*
First Repeating Element
Difficulty: EasyAccuracy: 32.57%Submissions: 285K+Points: 2Average Time: 15m
Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.

Note:- The position you return should be according to 1-based indexing. 

Examples:

Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.
Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.
Constraints:
1 <= arr.size <= 106
0 <= arr[i]<= 106
*/

class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        int max_ele=*max_element(arr.begin(),arr.end());
        vector<int> freq(max_ele+1,-1);
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(freq[arr[i]]>0)return i+1;
        }
        return -1;
    }
};
