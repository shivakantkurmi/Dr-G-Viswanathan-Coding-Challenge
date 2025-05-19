/*
1979. Find Greatest Common Divisor of Array
Solved
Easy
Topics
Companies
Hint
Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

//Link : https://leetcode.com/problems/find-greatest-common-divisor-of-array/description/

class Solution {
public:
    int GCD(int a,int b){
        if(b==0)return a;
        else return GCD(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxVal=0,minVal=1001;
        for(int i: nums){
            if(i<minVal)minVal=i;
            if(i>maxVal)maxVal=i;
        }
        return GCD(minVal,maxVal);
    }
};
