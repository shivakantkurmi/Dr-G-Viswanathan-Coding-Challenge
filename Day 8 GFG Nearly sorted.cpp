/*
Nearly sorted

Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.
*/

class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int j=0;
        for(int i:arr){
            if(minHeap.size()>k){
                arr[j++]=minHeap.top();
                minHeap.pop();
            }
            minHeap.push(i);
        }
        while(!minHeap.empty()){
            arr[j++]=minHeap.top();
            minHeap.pop();
        }
    }
};
