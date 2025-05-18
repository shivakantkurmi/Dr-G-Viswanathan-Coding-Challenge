/*
20. Valid Parentheses
Solved
Easy
Topics
Companies
Hint
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

//Link : https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.length()%2!=0) return false;
        for (auto i:s){
            if (i=='('||i=='{'||i=='[') st.push(i);
            else if (st.size()>0){
                if (i==')'&&st.top()!='(') return false;
                else if (i=='}'&&st.top()!='{') return false;
                else if (i==']'&&st.top()!='[') return false;
                else st.pop();
            }
            else return false;
        }
        if(st.size()!=0) return false;
        return true;
    }
};
