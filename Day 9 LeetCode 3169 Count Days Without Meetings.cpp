/*
3169. Count Days Without Meetings

You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). 
You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
Return the count of days when the employee is available for work but no meetings are scheduled.

Note: The meetings may overlap.
*/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); 
        int ans = 0;
        int lastBusyDay = 0; 
        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > lastBusyDay + 1) {
                ans += (start - lastBusyDay - 1);
            }
            lastBusyDay = max(lastBusyDay, end);
        }

        if (lastBusyDay < days) {
            ans += (days - lastBusyDay);
        }

        return ans;
    }
};
