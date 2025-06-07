/*
1047. Remove All Adjacent Duplicates In String
Solved
Easy

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
*/

//Link : https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();

        string ans = "";
        for(int i = 0; i<n; i++){
            char curChar = s[i];
            if(ans.empty()){
                ans.push_back(curChar);
            }
            else if(curChar == ans.back()){
                ans.pop_back();
            }
            else if(curChar != ans.back()){
                ans.push_back(curChar);
            }
        }
        return ans;   
    }
};
