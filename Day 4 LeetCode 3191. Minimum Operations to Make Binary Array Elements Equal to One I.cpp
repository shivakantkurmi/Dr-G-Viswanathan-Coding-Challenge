/*
3191. Minimum Operations to Make Binary Array Elements Equal to One I

You are given a binary array nums.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
*/

//Solution 1 
class Solution {
public:
    void flipbit(vector<int>&arr ,int l ,int r){
        for(;l<=r;l++) arr[l]=!(arr[l]);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int op=0;
        int l=0,r=2;
        while(r<n){
            if(nums[l]==0) flipbit(nums,l,r),op++;
            l++,r++;
        }
        for(;l<r;l++) if(nums[l]==0) return -1;
        return op;
    }
};

//Solution 2:
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), k = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                k++;
            }
        }

        for (int num : nums) {
            if (num == 0) return -1;
        }
        return k;
    }
};
