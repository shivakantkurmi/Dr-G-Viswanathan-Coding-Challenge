/*
2206. Divide Array Into Equal Pairs

You are given an integer array nums consisting of 2 * n integers.
You need to divide nums into n pairs such that:
Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.
*/

//solution 1 : using hashing 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i: nums) mp[i]++;
        for(auto i :mp){
            if(i.second %2 !=0)return false;
        }
        return true;
    }
};

//solution 2 : using sorting then comparision 
class Solution {
public:
    bool divideArray(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       for(int i=0;i<nums.size();i+=2)
       {
        if(nums[i]!=nums[i+1])
        {
            return false;
        }
       }
       return true;
    }
};
