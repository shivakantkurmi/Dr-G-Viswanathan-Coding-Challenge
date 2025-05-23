/*
224. Basic Calculator
Solved
Hard
Topics
Companies
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/

//Link : https://leetcode.com/problems/basic-calculator/description/

class Solution {
public:
    int calculate(string s) {
        stack <long long> nums; // Changed to long long
        stack <int> ops;        // Ops (signs) are small, int is fine

        long long num = 0;      // Changed to long long
        long long rst = 0;      // Changed to long long
        int sign = 1;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else {
                rst += sign * num;
                num = 0; // Reset num for the next number

                if (c == '+') sign = 1;
                else if (c == '-') sign = -1; // Use else if for clarity and efficiency
                else if (c == '(') {
                    nums.push(rst); // Save the result computed so far
                    ops.push(sign); // Save the sign before the parenthesis
                    rst = 0;        // Reset result for new calculation inside parenthesis
                    sign = 1;       // Reset sign for inside parenthesis
                }
                else if (c == ')' && ops.size()) { // Check ops.size() to prevent accessing empty stack
                    rst = ops.top() * rst + nums.top(); // Calculate (saved_sign * current_rst_in_paren + saved_rst_before_paren)
                    ops.pop();
                    nums.pop();
                }
            }
        }
        rst += sign * num; // Add the last number
        return static_cast<int>(rst); // Cast back to int if the problem specifies int return type
    }
};
