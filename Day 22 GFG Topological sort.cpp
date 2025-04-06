/*
Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 276K+Points: 4Average Time: 15m
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes an directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.
*/

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>ans;
        
        vector<int>deg(V + 1, 0);
        vector<vector<int>>graf(V);
        for(auto i : edges){
            graf[i[0]].push_back(i[1]);
            deg[i[1]]++;
        }
        queue<int>q;
        for(int i = 0; i < V; i++){
            if(deg[i] == 0){
                q.push(i);
                ans.push_back(i);
                deg[i] = -1;
            }
        }
        while(!q.empty()){
            int f = q.front();
            q.pop();
            
            for(auto i : graf[f]){
                deg[i]--;
                
                if(deg[i] == 0){
                    deg[i] = -1;
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};
