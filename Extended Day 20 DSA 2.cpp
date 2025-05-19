/*
150. Evaluate Reverse Polish Notation
Solved
Medium

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

//Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/") {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();

                if (i == "+") st.push(left + right);
                else if (i == "-") st.push(left - right);
                else if (i == "*") st.push(left * right);
                else if (i == "/") st.push(left / right);
            }
            else {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
