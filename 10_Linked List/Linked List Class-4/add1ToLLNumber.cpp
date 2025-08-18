// gfg: Add 1 to a Linked List Number
 // my code 
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







 Node* reversefunction(Node* &currentNode, Node* &prevNode)
{
    if(currentNode == NULL) {
        return prevNode; 
    }
    Node* forwardnode = currentNode->next;
    currentNode->next = prevNode;
    prevNode = currentNode;
    currentNode = forwardnode;
    return reversefunction(currentNode, prevNode);
}

class Solution {
public:
    Node* addOne(Node* head) {
        // Step 1: Reverse the list
        Node* currentNode = head;
        Node* prevNode = NULL;
        head = reversefunction(currentNode, prevNode);

        // Step 2: Add 1 to the reversed list
        int carry = 1;
        Node* temp = head;
        while (temp != NULL) {
            int sum = carry + temp->data;
            int digittostore = sum % 10;
            carry = sum / 10;
            temp->data = digittostore;

            if (temp->next == NULL && carry != 0) {
                Node* newnode = new Node(carry);
                temp->next = newnode;
                break;
            }

            temp = temp->next;
        }

        // Step 3: Reverse again to restore original order
        Node* prevv = NULL;
        head = reversefunction(head, prevv);  // ? fixed here
        return head;
    }
};




// code by love babbar 

class Solution
{
    public:
    Node* reverseList(Node* &head){
            Node* prev = NULL;
            Node* curr = head;
            while(curr!=NULL){
                Node* forward = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forward;
            }
            return prev;
        }
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        // step1: reverse list
        head = reverseList(head);
        // step2: add one
        // mujhe plus one krna hai, toh carry ko hi 1 manlia
        int carry = 1;
        Node* temp = head;
        while(temp!=NULL){
            int sum = carry + temp->data;
            // current node me 1 hi digit store hoga, double digit nhi ho skta
            int digit = sum%10;
            carry = sum/10;
            temp->data = digit;
            // move to next node
            // special case for last node only
            if(temp->next == NULL && carry!=0){
                Node* newNode = new Node(carry);
                temp->next = newNode;
                temp=newNode;
            }
            temp = temp->next;
        }
        // step3: reverse list
        head = reverseList(head);
        return head;
    }
};

