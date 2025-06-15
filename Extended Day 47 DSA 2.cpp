/*
191. Number of 1 Bits
Solved
Easy

Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
*/


//Link : https://leetcode.com/problems/number-of-1-bits/description/

class Solution {
public:
    int hammingWeight(int n) {
        int ans=0;
        while(n>0){
            if(n%2==1)ans++;
            n/=2;
        }
        return ans;
    }
};
