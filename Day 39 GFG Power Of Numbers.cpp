/*
Power Of Numbers
Difficulty: MediumAccuracy: 20.22%Submissions: 333K+Points: 4
Given a number n, find the value of n raised to the power of its own reverse.

Note: The result will always fit into a 32-bit signed integer.

Examples:

Input: n = 2
Output: 4
Explanation: The reverse of 2 is 2, and 22 = 4.
Input: n = 10
Output: 10
Explanation: The reverse of 10 is 1 (leading zero is discarded), and 101 = 10.
Input: n = 3
Output: 27
Explanation: The reverse of 3 is 3, and 33 = 27.
Constraints:
1 <= n <= 10
*/

class Solution {
  public:
    int power(int num,int x){
        if (x==1)return num;
        if(x%2==0){
            int half=power(num,x/2);
            return half*half;
        }
        else return num*power(num,x-1);
    }
    int reverseExponentiation(int n) {
        // code here
        int x=0,num=n;
        while(n){
            x+=(n%10);
            n/=10;
        }
        return power(num,x);
    }
};
