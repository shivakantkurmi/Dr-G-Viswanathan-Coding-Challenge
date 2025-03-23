/*
67. Add Binary
Given two binary strings a and b, return their sum as a binary string. 

Example 1:
Input: a = "11", b = "1"
Output: "100"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int i = a.length() - 1, j = b.length() - 1;
        bool carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;
            int total = bitA + bitB + carry;
            sum += (total % 2) + '0';  
            carry = total / 2;  
            i--; j--;
        }
        reverse(sum.begin(), sum.end()); 
        return sum;
    }
};
