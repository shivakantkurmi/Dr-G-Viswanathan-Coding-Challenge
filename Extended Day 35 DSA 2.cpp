/*
434. Number of Segments in a String
Solved
Easy

Given a string s, return the number of segments in the string.

A segment is defined to be a contiguous sequence of non-space characters.
*/

//Link : https://leetcode.com/problems/number-of-segments-in-a-string/description/

class Solution {
public:
    int countSegments(string s) {
        int ans=0;
        int i=0,n=s.length();
        while(i<n){
            if(s[i]!=' '){
                ans++;
                while(i<n && s[i]!=' '){i++;}
            }
            else i++;
        }
        return ans;
    }
};
