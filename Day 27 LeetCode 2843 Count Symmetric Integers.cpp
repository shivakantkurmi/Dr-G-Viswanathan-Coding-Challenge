/*
2843. Count Symmetric Integers
Solved
Easy
You are given two positive integers low and high.
An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.
Return the number of symmetric integers in the range [low, high].

Example 1:
Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
*/

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        string s1=to_string(low);
        string s2=to_string(high);
        int ans=0;
        if(s1.length()==s2.length() && s1.length()%2!=0) return 0;
        while(low<=high){
            string str=to_string(low);
            int len=str.length();
            if(len%2!=0){
                low=pow(10,len);
            }
            else{
                int half=len/2,leftSum=0,rightSum=0;
                for (int i = 0; i < half; ++i) {
                    leftSum += str[i] - '0'; 
                }
                for (int i = half; i < len; ++i) {
                    rightSum += str[i] - '0';
                }
                if (leftSum == rightSum) {
                    ans++;
                }
                low++;
            }

        }
        return ans;
    }
};
