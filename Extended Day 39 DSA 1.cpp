/*
701. Insert into a Binary Search Tree
Solved
Medium

You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.
*/

//Link : https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)
        {
            return new TreeNode(val);
        }
        TreeNode* temp=root;
        while(true)
        {
            if(root->val<val)
            {
                if(root->right==NULL)
                {
                    root->right=new TreeNode(val);
                    break;
                }
                root=root->right;
            }
            else
            {
                if(root->left==NULL)
                {
                    root->left=new TreeNode(val);
                    break;
                }
                root=root->left;
            }
        }
        return temp;
    }
};
