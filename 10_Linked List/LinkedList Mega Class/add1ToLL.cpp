// Add 1 to a Linked List Number gfg 
Add 1 to a Linked List Number
Difficulty: MediumAccuracy: 31.91%Submissions: 318K+Points: 4Average Time: 20m
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9



// my code 

/*
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

Node* rachtoTail(Node* &head, Node* current, int &carry) {
    // base case
    if (current == NULL) return NULL;

    // recursion to go till end
    rachtoTail(head, current->next, carry);

    // process current node after recursion
    int sum = current->data + carry;
    current->data = sum % 10;
    carry = sum / 10;

    // at head node, if carry is still left, insert new node at front
    if (current == head && carry != 0) {
        Node* newHead = new Node(carry);
        newHead->next = head;
        head = newHead;
    }

    return head;
}

class Solution {
  public:
    Node* addOne(Node* head) {
        int carry = 1;
        return rachtoTail(head, head, carry);
    }
};



//    code by lakchyaa
#include<iostream>
using namespace std;
// add 1 to Linked List using Head Recursion

class Node{
    public:
        int data;
        Node* next;

        //constructor
        Node(int value){
            this->data = value;
            this->next = NULL;
        }
};
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp = temp-> next;
        
    }
    cout<<"NULL"<<endl;
}



void solve(Node*head, int&carry){
    if(!head) return;
    solve(head->next,carry);
    //1case
    int sum = head->data+carry;
    int digit = sum%10;
    carry=sum/10;
    head->data = digit;
}
Node* add1(Node*head, int&carry){
    solve(head,carry);
    if(carry){
        Node*newHead=new Node(carry);
        newHead->next = head;
        head = newHead;
    }
    return head;
}
int main(){
    Node*head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    print(head);
    int carry = 1;
    head = add1(head,carry);
    print(head);
    return 0;
}
