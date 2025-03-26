/*
2033. Minimum Operations to Make a Uni-Value Grid
Medium

You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
A uni-value grid is a grid where all the elements of it are equal.
Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int base_rem=grid[0][0]%x;
        vector<int> vec;
        for(auto i :grid){
            for(auto j :i) {
                vec.push_back(j);
                if(j%x!=base_rem) return -1;
            }
        }
        sort(vec.begin(),vec.end());
        int n=vec.size();
        int median=vec[n/2];
        int ans=0;
        for(int i:vec){
            ans+=(abs(median-i)/x);
        }
        return ans;
    }
};
