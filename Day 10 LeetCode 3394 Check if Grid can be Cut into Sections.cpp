/*
3394. Check if Grid can be Cut into Sections
Solved
Medium

You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.
*/

class Solution {
public:
    bool check(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int sections = 0;
        int max_end = intervals[0][1];
        
        for (auto& interval : intervals) {
            int start = interval[0], end = interval[1];
            if (max_end <= start) {
                sections++;
            }
            max_end = max(max_end, end);
        }
        
        return sections >= 2;
    }
    
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x_intervals, y_intervals;
        
        for (auto& rect : rectangles) {
            x_intervals.push_back({rect[0], rect[2]});
            y_intervals.push_back({rect[1], rect[3]});
        }
        
        return check(x_intervals) || check(y_intervals);
    }
};
