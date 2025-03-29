/*
38. Count and Say
Solved
Medium
Topics
Companies
Hint
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with 
the concatenation of the character and the number marking the count of the characters (length of the run). For example,
to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.
*/

class Solution {
public:
    string modify(string s) {
        string ans = "";
        char ele = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                char c = '0' + cnt;
                ans += c;
                ans += s[i - 1];
                cnt = 1;
            }
        }
        char c = '0' + cnt;
        ans += c;
        ans += s[s.size() - 1];
        return ans;
    }

    string util(string s, int n) {
        if (n == 1) return s;
        string t = modify(s);
        return util(t, n - 1);
    }

    string countAndSay(int n) {
        string temp = "1";
        return util(temp, n);
    }
};
