// leetcode 25: Reverse Nodes in k-Group

25. Reverse Nodes in k-Group
Solved
Hard
Topics
premium lock icon
Companies
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,246,202/2M
Acceptance Rate
63.1%


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* &head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        // LL is empty
        if(head == NULL){
            return head;
        }
        // single node
        if(head->next == NULL){
            return head;
        }
        // atleast 2 node
        int position = 0;
        // check for LL length
        int len = getLength(head);
        if(len<k){
            // no need to reverse as per question
            return head;
        }

        // 1case hum, baki recursion sambhal lega
        // reverse k length
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(position<k){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            position++;
        }
        // baaki recursion sambhal lega
        if(curr!=NULL){
            ListNode* recursionHead = reverseKGroup(curr,k);
            head->next = recursionHead;
        }
        return prev;
    }
};
