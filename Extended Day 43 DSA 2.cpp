/*
6. Zigzag Conversion
Solved
Medium

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
*/

//Link : https://leetcode.com/problems/zigzag-conversion/description/


class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows <= 1) return s;
    vector<string>v(numRows, ""); 
    int j = 0, dir = -1;
    for(int i = 0; i < s.length(); i++){
        if(j == numRows - 1 || j == 0) dir *= (-1); 
        v[j] += s[i];
        if(dir == 1) j++;
        else j--;
    }
    string res;
    for(auto &it : v) res += it; 
    return res;
    }
};
