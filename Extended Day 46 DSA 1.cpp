/*
762. Prime Number of Set Bits in Binary Representation
Solved
Easy

Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
Recall that the number of set bits an integer has is the number of 1's present when written in binary.
For example, 21 written in binary is 10101, which has 3 set bits.
*/

//Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/

class Solution {
public:
    bool isprime(int x){
        if (x <= 1) return false;
        for(int i = 2; i*i <= x; i++){
            if (x%i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for (unsigned int i = left; i <= right; i++){
            int setbits = __builtin_popcount(i);
            if (isprime(setbits)) count++;
        }
        return count;
    }
};
