/*
Palindrome Linked List
Difficulty: MediumAccuracy: 41.48%Submissions: 354K+Points: 4Average Time: 20m
Given a head singly linked list of positive integers. The task is to check if the given linked list is palindrome or not.
*/

//Solution 1 : using stack
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        stack<int> st;
        Node *temp=head;
        while(temp)st.push(temp->data),temp=temp->next;
        Node *temp2=head;
        while(temp2){
            if(temp2->data !=st.top()) return false;
            temp2=temp2->next;
            st.pop();
        }
        return true;
    }
};



//Solution 2 :firts reverse the linked list then compare with original list 
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if(head==NULL|| head->next==NULL) return true;
        Node *temp=head;
        Node *prev=head;
        Node *next=head;
        while(next&&next->next){
            prev=prev->next;
            next=next->next->next;
        }
        Node *start=NULL;
        Node *curr=prev;
        while(curr){
            Node *next1 = curr->next;
            curr->next = start;
            start = curr;
            curr = next1;
        }
        while(start){
            if(start->data!=temp->data) return false;
            start=start->next;
            temp=temp->next;
        }
        return true;
        
    }
};
