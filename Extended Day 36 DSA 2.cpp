/*
129. Sum Root to Leaf Numbers
Solved
Medium

You are given the root of a binary tree containing digits from 0 to 9 only.
Each root-to-leaf path in the tree represents a number.
For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.
A leaf node is a node with no children.
*/

//Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0,ans=0;
    void DFS(TreeNode *root){
        if(root==nullptr){
            return;
        }
        sum=sum*10+root->val;
        DFS(root->left);
        DFS(root->right);
        if(root->left==nullptr&&root->right==nullptr){
            ans+=sum;
        }
        sum-=root->val;
        sum/=10;
    }
    int sumNumbers(TreeNode* root) {
        DFS(root);
        return ans;
    }
};
