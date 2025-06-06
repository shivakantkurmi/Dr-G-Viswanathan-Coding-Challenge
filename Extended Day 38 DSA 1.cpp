/*
700. Search in a Binary Search Tree
Solved
Easy

You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.
*/

//Link : https://leetcode.com/problems/search-in-a-binary-search-tree/description/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr || root->val==val)return root;
        TreeNode* newRoot=root;
        while(newRoot){
            if(newRoot->val==val)return newRoot;
            else if(newRoot->val>val)newRoot=newRoot->left;
            else newRoot=newRoot->right;
        }
        return nullptr;
    }
};

