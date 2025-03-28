/*
83. Remove Duplicates from Sorted List
Solved
Easy

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; 

        ListNode* temp = head;
        while (temp != nullptr && temp->next != nullptr) { 
            ListNode* t = temp;
            while (t->next != nullptr && t->val == t->next->val) 
                t = t->next; 

            temp->next = t->next; 
            temp = temp->next; 
        }
        return head;
    }
};
