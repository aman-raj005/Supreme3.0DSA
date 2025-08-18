// leetcode 138: Copy List with Random Pointer
 138. Copy List with Random Pointer       //       https://youtu.be/8ze7Zopdsaw?feature=shared            by sradha khapra
Solved
Medium
Topics
premium lock icon
Companies
Hint
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its 
corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that 
the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 

Constraints:

0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,639,259/2.7M
Acceptance Rate
60.6%


    // my code 

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        
        if (head == NULL) return NULL;

        // make the copy first
        Node* dummy = head;
        Node* copy = new Node(-1);
        Node* secondhead = copy;

        while (dummy != NULL) {
            Node* newnode = new Node(dummy->val);
            map[dummy] = newnode;
            copy->next = newnode;
            copy = copy->next;
            dummy = dummy->next;
        }

        // save head of new list
        Node* copyHead = secondhead->next;

        // reset pointers for random copy
        Node* origCurr = head;
        Node* copyCurr = copyHead;

        while (origCurr != NULL) {
            copyCurr->random = map[origCurr->random];
            origCurr = origCurr->next;
            copyCurr = copyCurr->next;
        }

        return copyHead;
    }
};




    //      code by lakchyaa
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// TC:O(N), SC: O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return 0;

        // Step 1: Clone A->A'
        Node*it = head; //iteratre over old head
        while(it){
            Node*clonedNode = new Node(it->val);
            clonedNode->next = it->next;
            it->next = clonedNode;
            it = it->next->next;
        }

        // Step 2: Assign random links of A' with the help of old Node A
        it = head;
        while(it){
            Node*clonedNode = it->next;
            clonedNode->random = it->random? it->random->next : nullptr;
            it = it->next->next;
        }

        // Step 3: Detach A' from A
        it = head;
        Node*clonedHead = it->next;
        while(it){
            Node*clonedNode= it->next;
            it->next = it->next->next;
            if(clonedNode->next){
                clonedNode->next = clonedNode->next->next;
            }
            it=it->next;
        }
        return clonedHead;
    }
};



// TC: O(N) , SC: O(n)
class Solution {
public:
    Node* helper(Node* head, unordered_map<Node*, Node*>&mp){
        if(head==0) return 0;
        Node* newHead = new Node(head->val);
        mp[head] = newHead;
        newHead->next = helper(head->next, mp);
        
        // random links
        if(head->random){
            newHead->random = mp[head->random];
        }
        
        return newHead;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;  //old node->new node mapping
        return helper(head,mp);
    }
};
