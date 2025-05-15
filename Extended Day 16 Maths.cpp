/*
633. Sum of Square Numbers
Solved
Medium

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
*/

//Link : https://leetcode.com/problems/sum-of-square-numbers/description/

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = static_cast<long>(sqrt(c));
        while(a<=b){
            long long sum=a*a + b*b;

            if(sum == c){
                return true;
            }

            if(sum < c){
                a++;
            }
            else{
                b--;
            }
        }
        return false;
    }
};
