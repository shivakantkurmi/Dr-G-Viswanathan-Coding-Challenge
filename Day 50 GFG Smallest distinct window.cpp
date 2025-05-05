/*
Smallest distinct window
Difficulty: MediumAccuracy: 31.85%Submissions: 107K+Points: 4
Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:
Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 8
Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks". 
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets.
*/

/* Link :  https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1   */

class Solution {
  public:
   int findSubString(string& str) {
    set<char> st;
    for (auto v : str) st.insert(v);
    int head = -1, tail = 0, cnt = 0, n = str.size(), ans = INT_MAX;
    unordered_map<char, int> mp;
    while (tail < n) {
        while (head + 1 < n && cnt < st.size()) {
            head++;
            mp[str[head]]++;
            if (mp[str[head]] == 1) cnt++;
        }
        if (cnt == st.size()) ans = min(ans, head - tail + 1);
        if (tail > head) {
            tail++;
            head = tail - 1;
        } else {
            mp[str[tail]]--;
            if (mp[str[tail]] == 0) cnt--;
            tail++;
        }
    }
    return ans;
}

};
