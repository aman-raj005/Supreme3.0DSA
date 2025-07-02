// gfg
Delete N nodes after M nodes of a linked list
Difficulty: EasyAccuracy: 32.83%Submissions: 59K+Points: 2
Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.
Examples:

Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2

Output: 9->1->5->9->10->1

Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input: Linked List: 1->2->3->4->5->6, n = 1, m = 6

Output: 1->2->3->4->5->6

Explanation: After skipping 6 nodes for the first time , we will reach of end of the linked list, so, we will get the given linked list itself.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= size of linked list <= 1000
0 < n, m <= size of linked list
       
       // my code 
  /*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
    Node* current=head;
    while(current !=NULL){
       
            for(int i=0;i<m-1 && current !=NULL;i++)
             {
               current=current->next; 
             }
             
             // If we reached end of list, break
            if(current == NULL) break;
             
             Node* temp= current->next;
             //ham current tak aa chuke hai
             for(int j=0;j<n && temp!=NULL ;j++)
              {
                 Node* nexttnode= temp->next;
                 delete temp;
                 temp= nexttnode;
              }
              //merge both the nodes
              current->next=temp;
              current=temp;
        }
         
        return head;
    }
};

                       // code by lakchya
class Solution {
    public:
    void linkdelete(struct Node **head, int N, int M) {
        Node* temp=*head;
        while(true){
            int m=M,n=N;
            m--;
            while(m>0 && temp!=NULL){
                temp=temp->next;
                m--;
            }
            if(temp==NULL) break;
            n++;
            Node* temp2=temp;
            while(n>0 &&temp2!=NULL){
                temp2=temp2->next;
                n--;
            }
            temp->next=temp2;
            temp=temp->next;
        }
    }
};
