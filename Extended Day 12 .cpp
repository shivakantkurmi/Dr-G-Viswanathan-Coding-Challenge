/*

2807. Insert Greatest Common Divisors in Linked List
Solved
Medium
Topics
Companies
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/


//Link : https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/


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
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
 public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* p=head;
        while(p && p->next!=NULL){
            int val1=p->val;
            int val2=p->next->val;
            int num=gcd(val1,val2);
            ListNode* newnode= new ListNode(num,p->next);
            p->next=newnode;
            p=p->next->next; 
        }
        return head;
    }
};
