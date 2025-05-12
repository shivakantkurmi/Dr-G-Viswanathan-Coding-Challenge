/*
1822. Sign of the Product of an Array
Solved
Easy

Implement a function signFunc(x) that returns:
1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
 */

//Link : https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool neg=0;
        for(int i:nums){
            if(i==0)return 0;
            if(i<0)neg=!neg;
        }
        return neg?-1:1;
    }
};
