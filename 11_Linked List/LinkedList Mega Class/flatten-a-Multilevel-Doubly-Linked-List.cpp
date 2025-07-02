// leetcode 430: Flatten a Multilevel Doubly Linked List
  
                    // my code         sradhyakhapra             https://youtu.be/I8b0rff5F9M?feature=shared

430. Flatten a Multilevel Doubly Linked List
Solved
Medium
Topics
premium lock icon
Companies
You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

 

Example 1:


Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:


Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:

Input: head = []
Output: []
Explanation: There could be empty list in the input.
 

Constraints:

The number of Nodes will not exceed 1000.
1 <= Node.val <= 105
 

How the multilevel linked list is represented in test cases:

We use the multilevel linked list from Example 1 above:

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
The serialization of each level is as follows:

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
To serialize all levels together, we will add nulls in each level to signify no node connects to the upper node of the previous level. The serialization becomes:

[1,    2,    3, 4, 5, 6, null]
             |
[null, null, 7,    8, 9, 10, null]
                   |
[            null, 11, 12, null]
Merging the serialization of each level and removing trailing nulls we obtain:

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

 
  /*
// Definition for a Node.
class Node {
public:
    int val;        // Value stored in the node
    Node* prev;     // Pointer to previous node in main list
    Node* next;     // Pointer to next node in main list
    Node* child;    // Pointer to head of child list
};
*/
 
class Solution {
public:
    Node* flatten(Node* head) {
        // Base case: if list is empty, return null
        if(head == NULL) {
            return head;
        }  
        
        Node* current = head;  // Pointer to traverse the main list
        
        while(current != NULL) {
            // Check if current node has a child list
            if(current->child != NULL) {
                // Store the next node in main list before flattening
                Node* nextInMainList = current->next;
                
                // Recursively flatten the child list
                current->next = flatten(current->child);
                current->next->prev = current;  // Set prev pointer of new next node
                current->child = NULL;          // Remove child reference
                
                // Traverse to the end of the newly flattened child list
                while(current->next != NULL) {
                    current = current->next;
                } 
                
                // Connect the tail of flattened child list to the original next node
                if(nextInMainList != NULL) {
                    current->next = nextInMainList;
                    nextInMainList->prev = current;
                }
            }
            // Move to next node in the main (now flattened) list
            current = current->next;
        }
        return head;
    }
};

  //       code by lakchya 

class Solution {
public:
    Node*solve(Node*head){
        if(!head) return nullptr;
        auto it = head;
        auto tail = it;  //for tracking tail node
        while(it){
            if(it->child){
                auto childTail = solve(it->child);  //tail node
                // flatten
                auto temp = it->next;
                it->next=it->child;
                it->next->prev = it;
                childTail->next = temp;
                if(temp) temp->prev = childTail;
                it->child=nullptr;
            }
            tail = it;
            it = it->next;
        }
        return tail;
    }

    Node* flatten(Node* head) {
        solve(head);
        return head;
    }
};
