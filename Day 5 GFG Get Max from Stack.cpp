/*
Get Max from Stack
Given q queries, You task is to implement the following three functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMax() – Retrieve the maximum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the maximum element from the stack.
*/

//Solution 1 : using 2 stack(vector)
class Solution {
  public:
    vector<int>st;
    vector<int>maxst={-1};
    Solution() {
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        if(x>=maxst.back()) maxst.push_back(x);
        st.push_back(x);
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(st.empty())return;
        if(st.back()==maxst.back())maxst.pop_back();
        st.pop_back();
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(st.size()==0)return -1;
        return st.back();
    }

    // Finds minimum element of Stack
    int getMax() {
        // code here
        return maxst.back();
    }
};



//Solution 2 : by Using single stack 
// C++ program to implement a stack that find
// maximum in stack in O(1) time and space.
#include <iostream>
#include <stack>
using namespace std;

// Class to implement a stack with getMax()
class MaxStack {
  private:
    stack<int> s;
    int maxEle;

  public:
    MaxStack() { 
        maxEle = -1; 
    }

    // Add an element to the top of Stack
    void push(int x) {
        if (s.empty()) {
            maxEle = x;
            s.push(x);
        }
        // If new number is greater than maxEle
        else if (x > maxEle) {
            s.push(2 * x - maxEle);
            maxEle = x;
        } else {
            s.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        if (s.empty()) {
            return;
        }

        int top = s.top();
        s.pop();

        // Maximum will change if the maximum element
        // of the stack is being removed.
        if (top > maxEle) {
            maxEle = 2 * maxEle - top;
        }
    }

    // Returns top element of the Stack
    int peek() {
        if (s.empty()) {
            return -1;
        }

        int top = s.top();

        // If maxEle < top means maxEle stores value of top.
        return (maxEle < top) ? maxEle : top;
    }

    // Finds maximum element of Stack
    int getMax() {
        if (s.empty())
            return -1;

        // variable maxEle stores the maximum element
        // in the stack
        return maxEle;
    }
};

int main() {
    MaxStack stk;
    
    stk.push(2); 
    stk.push(3);
    cout << stk.peek() << " ";
    stk.pop();
    cout << stk.getMax() << " ";
    stk.push(1);
    cout << stk.getMax() << " ";

    return 0;
}
