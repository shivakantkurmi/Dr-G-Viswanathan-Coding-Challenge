/*
119. Pascal's Triangle II
Solved
Easy

Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
*/

//Link : https://leetcode.com/problems/pascals-triangle-ii/description/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(1, 1);

        for (int i = 0; i < rowIndex; i++) {
            vector<int> newRow;
            newRow.push_back(1);
            for (int j = 1; j < row.size(); j++) {
                newRow.push_back(row[j - 1] + row[j]);
            }
            newRow.push_back(1);
            row = newRow;
        }

        return row;        
    }
};
