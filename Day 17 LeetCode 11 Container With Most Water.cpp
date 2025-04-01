/*
11. Container With Most Water
Solved
Medium

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sum=accumulate(height.begin(),height.end(),0);
        int left=0,right=height.size()-1;
        int ans=-1;
        while(left<right){
            if(height[left]<=height[right]){
                ans=max(ans,height[left]*(right-left));
                left++;
            }
            else {
                ans=max(ans,height[right]*(right-left));
                right--;
            }
        }
        return ans;
    }
};
