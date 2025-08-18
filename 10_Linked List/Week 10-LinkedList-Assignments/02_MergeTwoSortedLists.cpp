21. Merge Two Sorted Lists
Solved
Easy
Topics
premium lock icon
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

 

Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
 

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.


// mu code 
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(-1); // Dummy node to simplify edge cases
    ListNode* mktr = &dummy;
    
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            mktr->next = list1; // Link mktr to list1
            list1 = list1->next; // Move list1 forward
        } else {
            mktr->next = list2; // Link mktr to list2
            list2 = list2->next; // Move list2 forward
        }
        mktr = mktr->next; // Move mktr forward
    }
    
    // Attach the remaining nodes
    mktr->next = list1 ? list1 : list2;
    
    return dummy.next; // The merged list starts after dummy
}



// leetcode 21: Merge Two Sorted Lists

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;

        ListNode* ans = new ListNode(-1);
        ListNode* mptr = ans;

        while(list1 && list2){
            if(list1->val <= list2->val){
                mptr->next = list1;
                mptr = list1;
                list1 = list1->next;
            }
            else{
                mptr->next = list2;
                mptr = list2;
                list2 = list2->next;
            }
        }
        // leftover list
        if(list1){
            mptr->next = list1;
            // mptr = list1;
            // list1 = list1->next;
        }
        if(list2){
            mptr->next = list2;
            // mptr = list2;
            // list2 = list2->next;
        }
        return ans->next;
    }
};
