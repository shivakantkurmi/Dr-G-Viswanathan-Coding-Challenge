/*
14. Longest Common Prefix
Easy

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

 
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix="";
        string current=strs[0];
        int i;
        bool flag=false;
        for(i=0 ;i<current.length();i++){
            for(int ind=1;ind<strs.size();ind++){
                if(strs[ind].length()>i && strs[ind][i]==current[i]) continue ;
                else{ 
                    flag=true;
                    break;}
            }
            if (flag) break;
        }
        return current.substr(0,i);
    }
};
