/*
Sort a linked list of 0s, 1s and 2s
Difficulty: MediumAccuracy: 60.75%Submissions: 241K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 → 2 → 0 → 1

Output: 0 → 1 → 2 → 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2
*/

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        unordered_map<int,int> mp;
        Node* temp = head;
        while(temp){
            mp[temp->data]++;
            temp = temp -> next;
        }
        
        int zeroes = mp[0];
        int ones = mp[1];
        int twos = mp[2];
        
        temp = head;
        while(temp){
            if(zeroes){
                temp -> data = 0;
                zeroes--;
            }else if(ones){
                temp -> data = 1;
                ones--;
            }else{
                temp -> data = 2;
                twos--;
            }
            temp = temp ->  next;
        }
        return head;
    }
};
