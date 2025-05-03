/*
Prime List
Difficulty: MediumAccuracy: 53.68%Submissions: 32K+Points: 4
You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104
*/


// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
   bool isPrime(int n) {
        if (n <=1) return false;
        if (n<=3) return true;
        if (n % 2==0 || n %3==0) return false;
        for (int i=5; i * i <= n;i +=6) {
            if (n%i== 0|| n % (i + 2)== 0) return false;
        }
        return true;
    }
    int close(int num){
        if (num<= 1)
            return 2;
    
        if (isPrime(num)) 
            return num;
    
        int l=num-1;
        int h=num+1;
    
        while (true){
            if (l>= 2 && isPrime(l)) {
                if (isPrime(h)) {
                    if ((num-l)<=(h - num)) 
                        return l;
                    else
                        return h;
                
                } else
                    return l;
            } else if(isPrime(h))
                return h;
            l--;
            h++;
        }
    }

    Node* primeList(Node *head){
        Node *recent=head;
        while (recent!=nullptr){
            int val = recent->val;
            recent->val=close(val);
            recent=recent->next;
        }
        return head;
    }
};
