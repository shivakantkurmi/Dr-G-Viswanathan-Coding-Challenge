/*
Remove Duplicates from a Sorted Linked List
Difficulty: EasyAccuracy: 49.37%Submissions: 308K+Points: 2Average Time: 20m
Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way.

Examples:

Input:
LinkedList: 2->2->4->5
Output: 2 -> 4 -> 5
*/

/*
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
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if (!head) return nullptr; // Edge case: Empty list
        
        Node* temp = head;
        while (temp && temp->next) { // Ensure temp and temp->next are not null
            if (temp->data == temp->next->data) {
                // Skip duplicate nodes and do not change tempto ensure that temp->next->next is also not duplicate
                temp->next = temp->next->next;
            } else {
                // Move to the next unique node
                temp = temp->next;
            }
        }
        return head;
    }
};
