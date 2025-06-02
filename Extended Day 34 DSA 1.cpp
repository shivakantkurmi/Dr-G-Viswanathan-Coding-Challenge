/*
58. Length of Last Word
Solved
Easy
Topics
premium lock icon
Companies
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/

//Link : https://leetcode.com/problems/length-of-last-word/description/


class Solution {
public:
    int lengthOfLastWord(string s) {
        int i=s.length()-1;
        int ans=0;
        while(s[i]==' ')i--;
        while(i>=0 && s[i]!=' ')i--,ans++;
        return ans;
    }
};
