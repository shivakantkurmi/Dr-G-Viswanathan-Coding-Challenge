/*
1358. Number of Substrings Containing All Three Characters
Solved
Medium

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/

//Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution {
public:
    int numberOfSubstrings(std::string s) {
        std::vector<int> count(3, 0); 
        int left = 0; 
        int result = 0; 

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.length() - i; 
                count[s[left] - 'a']--; 
                left++; 
            }
        }
        return result; 
    }
};
