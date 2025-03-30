/*
Delete in a Singly Linked List
Difficulty: EasyAccuracy: 39.85%Submissions: 219K+Points: 2
Given a singly linked list and an integer, x. Delete the xth node (1-based indexing) from the singly linked list.
*/

/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // cdoe here
        Node *temp=head;
        if(x==1) {
            temp=head->next;
            return temp;
        }
        while(x-2){
            temp=temp->next;
            x--;
        }
        temp->next=temp->next->next;
        return head;
    }
};
