// leetcode 142: Linked List Cycle II
       // my code 
    /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
 142. Linked List Cycle II
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer.
 Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
 Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
 

Follow up: Can you solve it using O(1) (i.e. constant) memory?
 
  // lakchya code is better than mine
 
ListNode* detectloop(ListNode *head, ListNode *fast, ListNode *slow) {
    // base case
    if(fast == NULL || fast->next == NULL) { return nullptr; }
    
    // Move pointers first
    fast = fast->next->next;
    slow = slow->next;
    
    // Then check if they meet
    if(fast == slow) { return fast; }
     
    return detectloop(head, fast, slow);
}

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return nullptr;
        
        // detect loop
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* meetpoint = detectloop(head, fast, slow);
        
        if(meetpoint == nullptr) return nullptr;
        
        slow = head;
        while(meetpoint != slow) {
            meetpoint = meetpoint->next;
            slow = slow->next;
        }
       
        return slow;
    }
};




  //        code by lakchya
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast == slow) return fast;
        }
        return nullptr;
    }
    // slow-fast approach
    ListNode *detectCycle(ListNode *head) {
        // step-1: check if loop is there or not
        ListNode*fast = hasCycle(head);
        if(!fast) return nullptr;
        // fast is non-null means->cycle is there
        // find starting point of cycle
        ListNode*slow = head;
        // now move slow & fast ptr with 1x speed and return where they meet
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;   //starting point
    }
};


// BRUTE FORCE METHOD
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> m;
        ListNode* temp = head;
        while(temp!=NULL){
            if(m[temp]==true) return temp;
            else{
                m[temp]=true;
            }
            temp=temp->next;
        }
        return temp;
    }
};
