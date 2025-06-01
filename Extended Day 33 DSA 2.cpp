/*
199. Binary Tree Right Side View
Solved
Medium

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

//Link : https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ll;
        if (!root) return ll;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            TreeNode* rv = nullptr;
            while (n-- > 0) {
                rv = q.front();
                q.pop();
                if (rv->left) q.push(rv->left);
                if (rv->right) q.push(rv->right);
            }
            ll.push_back(rv->val);
        }
        return ll;
    }
};
