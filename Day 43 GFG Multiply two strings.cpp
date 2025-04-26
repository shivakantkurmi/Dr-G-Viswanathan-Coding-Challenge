/*
Multiply two strings
Difficulty: MediumAccuracy: 20.06%Submissions: 222K+Points: 4Average Time: 20m
Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Constraints:
1 ≤ s1.size() ≤ 103
1 ≤ s2.size() ≤ 103
*/

class Solution {
  public:
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        int n = s1.length(), m = s2.length();
    
        bool isNegative = false;
        if (s1[0] == '-' && s2[0] != '-') isNegative = true;
        if (s1[0] != '-' && s2[0] == '-') isNegative = true;
    
        string temp1 = "", temp2 = "";
        int startIdx = (s1[0] == '-') ? 1 : 0;
        for (int i = startIdx; i < n; i++) temp1.push_back(s1[i]);
        startIdx = (s2[0] == '-') ? 1 : 0;
        for (int i = startIdx; i < m; i++) temp2.push_back(s2[i]);
        s1 = temp1;
        s2 = temp2;
    
        string str = "";
        int index = -1;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != '0') {
                index = i;
                break;
            }
        }
        for (int i = index; i < s1.length(); i++) str.push_back(s1[i]);
        s1 = (index == -1) ? "0" : str;
    
        str = "";
        index = -1;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] != '0') {
                index = i;
                break;
            }
        }
        for (int i = index; i < s2.length(); i++) str.push_back(s2[i]);
        s2 = (index == -1) ? "0" : str;
    
        if (s1 == "0" || s2 == "0") return "0";
    
        n = s1.length();
        m = s2.length();
    
        string prod(n + m, '0');
    
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = (prod[i + j + 1] - '0') + mul;
                prod[i + j + 1] = (sum % 10) + '0';
                prod[i + j] += sum / 10;
            }
        }
    
        index = -1;
        for (int i = 0; i < prod.length(); i++) {
            if (prod[i] != '0') {
                index = i;
                break;
            }
        }
        str = "";
        for (int i = index; i < prod.length(); i++) str.push_back(prod[i]);
        prod = (index == -1) ? "0" : str;
    
        return isNegative ? "-" + prod : prod;
    }
};
