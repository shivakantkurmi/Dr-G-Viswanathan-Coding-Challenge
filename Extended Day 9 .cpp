/*
1721. Swapping Nodes in a Linked List
Solved
Medium

You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).
*/

//link : https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *itr=head;
        ListNode *l1,*l2;
        if(head==NULL || head->next==NULL) return head;
        int len=0;
        while(itr!=NULL){
            len++;
            itr=itr->next;
        }
        itr=head;
        int i=0;
        while(itr!=NULL){
          i++;
          if(i==k) l1=itr;
          if(i==(len-k+1)) l2=itr;
          itr=itr->next;
        }
        swap(l1->val,l2->val);
        return head;
    }
};
