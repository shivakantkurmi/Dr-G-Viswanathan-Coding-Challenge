/*
19. Remove Nth Node From End of List
Solved
Medium
Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

//Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0, head);
        ListNode* fast = dummy; 
        ListNode*slow = dummy; 
        int count = 0;
        while (fast != nullptr) {
            fast = fast->next;
            if (count > n) {
               slow =slow->next;
            }
            count++;
        }
        slow->next =slow->next->next;
        return dummy->next;
    }
};
