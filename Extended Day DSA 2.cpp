/*
2108. Find First Palindromic String in the Array
Solved
Easy

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.
*/

//Link : https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            bool flag{true};
            for(int j=0;j<words[i].size()/2;j++){
                if(words[i][j]!=words[i][words[i].size()-1-j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return words[i];
        }
    return "";
    }
};
