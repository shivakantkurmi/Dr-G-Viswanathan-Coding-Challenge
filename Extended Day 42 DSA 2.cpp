/*
151. Reverse Words in a String
Solved
Medium

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/

//Link : https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=0;
        while(s[i]==' ')i++;
        string word="";
        while(i<s.length()){
            if(s[i]!=' ') word+=s[i];
            if(s[i]==' ' && word.length()!=0){
                if(ans.empty())ans=word;
                else ans=word+" "+ans;
                word="";
            }
            i++;
        }
        if(word.empty()) return ans;
        else if(ans.empty())return word;
        else return word+" "+ans ;
    }
};
