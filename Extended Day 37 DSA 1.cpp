/*
103. Binary Tree Zigzag Level Order Traversal
Solved
Medium

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/

//Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            vector<int> temporary;
            int level = q.front().second;

            for (int i = 0; i < n; i++) {
                auto temp = q.front(); q.pop();
                TreeNode* currRoot = temp.first;
                if (currRoot->left) q.push({currRoot->left, level + 1});
                if (currRoot->right) q.push({currRoot->right, level + 1});
                temporary.push_back(currRoot->val);
            }

            if (level % 2 != 0) reverse(temporary.begin(), temporary.end());
            ans.push_back(temporary);
        }
        return ans;
    }
};
