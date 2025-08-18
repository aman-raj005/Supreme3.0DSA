// leetcode 83: Remove Duplicates from Sorted List

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
 83. Remove Duplicates from Sorted List
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,1,2]
Output: [1,2]
Example 2:


Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.






class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //1st case-> LL is empty
        if(head==NULL) return head;
        //2nd case-> single node in LL
        if(head->next == NULL) return head;
        // 3rd case-> more than 1 nodes present
        ListNode* prev = head;
        ListNode* temp = head->next;

        while(temp!=NULL){
            
            // check duplicate
            if(temp->val == prev->val){
                //duplicate found->delete
                prev->next = temp->next;
                temp->next = NULL;
                delete temp;
            }
            else{
                prev=prev->next;
                temp=temp->next;
            }
            temp = prev->next;
        }
        return head;
    }
};
