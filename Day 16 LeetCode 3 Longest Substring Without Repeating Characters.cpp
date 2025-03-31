/*
3. Longest Substring Without Repeating Characters
Solved
Medium
Given a string s, find the length of the longest substring without duplicate characters.
 
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

/*
Solution Approach :
Step 1: Traverse the linked list while checking for consecutive duplicate values.

Step 2: If a duplicate is found, update the next pointer to skip it.

Step 3: Continue until the end of the list is reached. 
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLength = 0;
        unordered_set<char> charSet;

        for (int right = 0; right < s.length(); right++) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;        
    }
};
