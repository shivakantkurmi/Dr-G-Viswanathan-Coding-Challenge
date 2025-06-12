/*
1456. Maximum Number of Vowels in a Substring of Given Length
Solved
Medium

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
*/

//Link : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int maxVowel = 0, left = 0, vowel = 0;

        for (int right = 0; right < s.length(); right++) {
            if (isVowel(s[right])) vowel++;

            if ((right - left + 1) == k) {
                maxVowel = max(maxVowel, vowel);
                if (isVowel(s[left])) vowel--;
                left++;
            }
        }
        return maxVowel;
    }
};
