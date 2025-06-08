/*
235. Lowest Common Ancestor of a Binary Search Tree
Solved
Medium

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p
and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

//Link : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } else {
                return root;
            }
        }
        return nullptr;        
    }
};

