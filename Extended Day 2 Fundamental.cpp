/*
258. Add Digits
Solved
Easy

Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
 

Example 1:
Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0

Constraints:
0 <= num <= 231 - 1

Follow up: Could you do it without any loop/recursion in O(1) runtime?

*/

// class Solution {
// public:
//     int sumDigit(int num){
//         int x=0;
//         while(num){
//             x+=(num%10);
//             num/=10;
//         }
//         return x;
//     }
//     int addDigits(int num) {
//         while(num>=10){
//             num=sumDigit(num);
//         }
//         return num;
//     }
// };

//Solution 2 
//A number is divisible by 
//if the sum of its digits is divisible by 

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num%9 == 0) return 9;
        else return num%9;
    }
};
