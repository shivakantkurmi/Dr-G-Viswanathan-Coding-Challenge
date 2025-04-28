/*
Maximum sum of Non-adjacent nodes
Difficulty: MediumAccuracy: 55.35%Submissions: 80K+Points: 4Average Time: 45m
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105
*/

// User function Template for C++

// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    
    unordered_map<Node*, int> dp;
    int solve(Node* root) {
        
        if(root == NULL){
            return 0;
        }
        if(dp[root]){
            return dp[root];
        }
        int take = root->data;
        
        if(root->left){
            take += solve(root->left->left);
            take += solve(root->left->right);
        }
        if(root->right){
            take += solve(root->right->right);
            take += solve(root->right->left);
        }
        int skip = solve(root->left) + solve(root->right);
        
        return dp[root] = max(take,skip);
    }
    int getMaxSum(Node *root) {
        
        return solve(root);
    
    }
};
