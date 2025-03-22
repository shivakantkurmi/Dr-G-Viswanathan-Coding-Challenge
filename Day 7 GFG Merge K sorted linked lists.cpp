/*
Merge K sorted linked lists
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<int , vector<int> ,greater<int>>heap;
        for(auto i : arr){
            while(i!=nullptr)heap.push(i->data),i=i->next;
        }
        Node* head=nullptr;
        Node *temp=head;
        while(!heap.empty()){
            Node* newNode=new Node(heap.top());
            if(temp==nullptr){
                head=newNode;
                temp=head;
            }
            else {
                temp->next=newNode;
                temp=temp->next;
            }
            heap.pop();
        }
        return head;
        
    }
};
