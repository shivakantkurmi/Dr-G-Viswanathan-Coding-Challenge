/*
Isomorphic Strings
Difficulty: EasyAccuracy: 34.21%Submissions: 198K+Points: 2Average Time: 30m
Given two strings s1 and s2, check if these two strings are isomorphic to each other.

If the characters in s1 can be changed to get s2, then two strings, s1 and s2, are isomorphic. A character must be completely swapped out for another character while maintaining the order of the characters. A character may map to itself, but no two characters may map to the same character.

Examples:

Input: s1 = "aab", s2 = "xxy"
Output: true
Explanation: There are two different characters in aab and xxy, i.e a and b with frequency 2 and 1 respectively.
*/


class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        if (s1.length() != s2.length()) return false;

        int map1[26]; // For mapping s1 -> s2
        int map2[26]; // For mapping s2 -> s1

        fill(map1, map1 + 26, -1);
        fill(map2, map2 + 26, -1);

        for (int i = 0; i < s1.length(); ++i) {
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            if (map1[c1] == -1 && map2[c2] == -1) {
                map1[c1] = c2;
                map2[c2] = c1;
            } else {
                if (map1[c1] != c2 || map2[c2] != c1)
                    return false;
            }
        }

        return true;
    }
};
