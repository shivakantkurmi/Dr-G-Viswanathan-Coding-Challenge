/*
String Rotated by 2 Places
Difficulty: EasyAccuracy: 32.7%Submissions: 242K+Points: 2Average Time: 20m
Given two strings s1 and s2. Return true if the string s2 can be obtained by rotating (in any direction) string s1 by exactly 2 places, otherwise, false.

Note: Both rotations should be performed in same direction chosen initially.

Examples:

Input: s1 = "amazon", s2 = "azonam"
Output: true
Explanation: "amazon" can be rotated anti-clockwise by two places, which will make it as "azonam".
*/

class Solution {
  public:
    bool isRotated(string& s1, string& s2) {
        if (s1.length() != s2.length()) return false;
        if(s1.length()==1 && s1!=s2)return false;
        int n = s1.length();
        string t1 = s1.substr(n-2) + s1.substr(0, n-2);
        string t2 = s1.substr(2) + s1.substr(0, 2);

        return (s2 == t1 || s2 == t2);
    }
};
