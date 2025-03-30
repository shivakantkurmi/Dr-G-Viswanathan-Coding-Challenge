/*
763. Partition Labels
Solved
Medium
Topics
Companies
Hint
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears 
in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(auto i:s) freq[i-'a']++;
        vector<int>ans;
        int len=0,charcnt=0;
        for(auto i:s){
            len++;
            if(freq[i-'a']==-1) charcnt--;
            else{
                charcnt+=freq[i-'a']-1;
                freq[i-'a']=-1;
            }
            if(charcnt==0)ans.push_back(len),len=0;
        }
        return ans;
    }
};
