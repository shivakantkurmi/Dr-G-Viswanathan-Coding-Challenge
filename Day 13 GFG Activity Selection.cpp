/*
Activity Selection
Difficulty: MediumAccuracy: 36.21%Submissions: 151K+Points: 4Average Time: 20m
You are given a set of activities, each with a start time and a finish time, represented by the arrays start[] and finish[], respectively. A single person can perform only one activity at a time, meaning no two activities can overlap. Your task is to determine the maximum number of activities that a person can complete in a day.

Examples:

Input: start[] = [1, 3, 0, 5, 8, 5], finish[] = [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: A person can perform at most four activities. The maximum set of activities that can be executed is {0, 1, 3, 4}
*/


//greedy approach
class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
        // code here
        int n=start.size();
        vector<pair<int,int>>store;
        for(int i=0;i<n;i++){
            store.push_back({start[i],end[i]});
        }
        
        sort(store.begin(),store.end());
        int maxi=1;
        int activity=1;
        int s=-1,e=-1;
        for(int i=0;i<n;i++){
            int first=store[i].first,second=store[i].second;
            if(s==-1 && e==-1){
                s=first,e=second;
            } else if(first>e){
                activity++;
                maxi=max(maxi,activity);
                s=first,e=second;
            } else if(first<=e){
                s=max(s,first),e=min(e,second);
            }
        }
        
        return maxi;
    }
};
