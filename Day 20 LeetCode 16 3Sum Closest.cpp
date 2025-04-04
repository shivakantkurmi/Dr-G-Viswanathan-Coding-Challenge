/*
16. 3Sum Closest
Solved
Medium

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

 
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest{INT_MAX}, sum{0}, tsum{0};
        int i{0},j{0}, n = nums.size(), k =n;
        for(int i=0;i<n;i++){
            j=i+1;
            k = n-1;
            while(j<n && k>=0 && j<k){
                tsum = nums[i]+nums[j]+nums[k];
                if(abs(target-tsum) < closest){
                    sum = tsum;
                    closest = abs(target-tsum);
                }
                if(tsum>target)
                    k--;
                else 
                    j++;

            }
        }
        return sum;
    }
};
