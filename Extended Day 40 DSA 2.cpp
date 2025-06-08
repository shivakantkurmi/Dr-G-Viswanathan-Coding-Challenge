/*
796. Rotate String
Solved
Easy

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
A shift on s consists of moving the leftmost character of s to the rightmost position.
For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

//Link : https://leetcode.com/problems/rotate-string/description/

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!= goal.length())return false;
        goal+=goal;
        if(goal.find(s)!=-1)return true;
        else return false;
    }
};
