/*
1523. Count Odd Numbers in an Interval Range
Solved
Easy

Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
*/

//Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

class Solution {
public:
    int countOdds(int low, int high) {
        return (high - low) / 2 + ((low % 2 != 0 || high % 2 != 0) ? 1 : 0);
    }
};
