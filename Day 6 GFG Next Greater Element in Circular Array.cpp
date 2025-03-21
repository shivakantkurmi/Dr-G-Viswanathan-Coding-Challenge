/*
Next Greater Element in Circular Array

Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.
The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.
Circular Property:
Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once
*/

//Solution:
class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=2*n-1;i>=0;i--){
            while(!(st.empty()) && st.top()<=arr[i%n])st.pop();
            if(i<n && !st.empty()) ans[i]=st.top();
            st.push(arr[i%n]);

        }
        return ans;
        
    }
};
