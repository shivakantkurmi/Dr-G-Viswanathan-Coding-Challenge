/*
2780. Minimum Index of a Valid Split
Solved
Medium

An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.
You are given a 0-indexed integer array nums of length n with one dominant element.
You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:
0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.
Return the minimum index of a valid split. If no valid split exists, return -1.

 
Example 1:
Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. 
*/

/*
🔹 Approach:
✅ Two-Pass Scan with Frequency Tracking
Pass 1: Find the dominant element using Boyer-Moore Voting Algorithm (O(N)).
Pass 2: Iterate over nums[], tracking occurrences of the dominant element in both halves.

Valid Split Condition:
Left side: Dominant element appears in more than half of its elements.
Right side: Dominant element appears in more than half of its elements.
Return the smallest i where this holds.
Time Complexity: O(N), Space Complexity: O(1).
Key Insight: Boyer-Moore Voting finds the dominant element efficiently.
*/

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int candidate=0,votes=0;
        for(int i=0;i<n;i++){
            if(votes==0){
                candidate=nums[i];
                votes++;
            }
            else {
                if(nums[i]==candidate) votes++;
                else votes--;
            }
        }
        int cnt=0;
        for(int i:nums) {
            if(i==candidate) cnt++;
        }
        vector<int> maxfreq={candidate,cnt};
        int i=0,currentfreq=0;
        while(i<n){
            if(nums[i]==maxfreq[0])currentfreq++,maxfreq[1]--;
            if(currentfreq>(i+1)/2 && maxfreq[1]>(n-i-1)/2) return i;
            i++;
        }
        return -1;
    }
};
