/*
171. Excel Sheet Column Number
Solved
Easy

Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
*/

//Link : https://leetcode.com/problems/excel-sheet-column-number/description/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        int i=columnTitle.length()-1;
        for(i;i>=0;i--){
            ans+=pow(26,columnTitle.length()-i-1)*(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};
