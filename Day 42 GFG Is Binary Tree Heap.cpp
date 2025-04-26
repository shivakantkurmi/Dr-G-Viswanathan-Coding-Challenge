/*
Is Binary Tree Heap
Difficulty: MediumAccuracy: 34.41%Submissions: 116K+Points: 4
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103
*/


// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  bool isCompleteBT(struct Node* root) {
      
      if(!root) return true;
      
      queue<Node*>q;
      q.push(root);
      bool nullFlag = false; 
      
      while(!q.empty()){
          
          Node* front = q.front();
          q.pop();
        
          if(!front){
            nullFlag = true;  
          }
          
          else{
              if(nullFlag){
                return false;
              }
          q.push(front->left);
           if (front->left) {
            if (front->left->data > front->data) return false;
            
        }
        // Right Child Check
        q.push(front->right);
        if (front->right) {
            if (front->right->data > front->data) return false;
            
        }
          }  
      }
      return true;
    }
    
    
    bool isHeap(struct Node* tree) {
        if(!tree) return true;
        
        return isCompleteBT(tree);
            
        
    }
};
