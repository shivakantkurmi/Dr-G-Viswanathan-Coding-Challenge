/*
7. Reverse Integer
Solved
Medium

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

//Link : https://leetcode.com/problems/reverse-integer/description/

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) {
                return 0; // Return 0 to indicate overflow or underflow
            }
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};
