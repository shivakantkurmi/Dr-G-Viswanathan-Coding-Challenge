/*
Max distance between same elements
Difficulty: EasyAccuracy: 46.67%Submissions: 73K+Points: 2Average Time: 20m
Given an array arr[], the task is to find the maximum distance between two occurrences of an element. If no element has two occurrences, then return 0.

Examples:

Input: arr[] = [1, 1, 2, 2, 2, 1]
Output: 5
Explanation: distance for 1 is: 5-0 = 5, distance for 2 is : 4-2 = 2, So max distance is 5.
*/

class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        int res=0;
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            if(freq.find(arr[i])==freq.end()){
                freq[arr[i]]=i;
            }
            else {
                res=max(res,i-freq[arr[i]]);
            }
        }
        return res;
    }
};
