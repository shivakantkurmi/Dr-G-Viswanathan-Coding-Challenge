/*
1071. Greatest Common Divisor of Strings
Solved
Easy

For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).
Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.
*/

//Link : https://leetcode.com/problems/greatest-common-divisor-of-strings/description/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        auto gcd = [](int len1, int len2) {
            int minVal = min(len1, len2);
            for (int i = minVal; i > 0; --i) {
                if (len1 % i == 0 && len2 % i == 0) {
                    return i;
                }
            }
            return 1;
        };

        int lenGCD = gcd(str1.length(), str2.length());
        return str1.substr(0, lenGCD);        
    }
};
