/*
112. Path Sum
Solved
Easy

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
*/

//Link : https://leetcode.com/problems/path-sum/description/

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
    bool rootToLeafPathSum(TreeNode* root, int targetSum, int sum){
        if(root == nullptr)
            return false;
        if(root -> left == nullptr && root -> right == nullptr){
            sum = sum + root -> val;
            if(sum == targetSum)
                return true;   
        }
        return rootToLeafPathSum(root -> left, targetSum, sum + root -> val) || rootToLeafPathSum(root -> right, targetSum, sum + root -> val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return rootToLeafPathSum(root, targetSum, sum);
    }
};

