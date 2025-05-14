/*
168. Excel Sheet Column Title
Solved
Easy

Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
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

//Link : https://leetcode.com/problems/excel-sheet-column-title/description/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        //just a base 26 number conversion
        string ans;
        while (columnNumber--) {
            ans += columnNumber % 26 + 'A';
            columnNumber /= 26;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
