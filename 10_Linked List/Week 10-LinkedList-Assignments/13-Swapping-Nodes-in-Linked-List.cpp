// leetcode 1721: Swapping Nodes in a Linked List


1721. Swapping Nodes in a Linked List
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]
Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]
 

Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100
Seen this question in a real interview before?
1/5
Yes
No
Accepted
406,099/592.7K
Acceptance Rate
68.5%

     // my simple code        try to do lakchya code 
     
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
    ListNode* swapNodes(ListNode* head, int k) {
        // Step 1: Get length of the list
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        
        // Edge case: if k is invalid
        if (k > size) return head;

        // Step 2: Find the k-th node from start
        ListNode* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 3: Find the k-th node from end
        ListNode* second = head;
        for (int i = 1; i < size - k + 1; i++) {
            second = second->next;
        }

        // Step 4: Swap their values
        int tempVal = first->val;
        first->val = second->val;
        second->val = tempVal;

        return head;
    }
};



    //  code by lakchya 
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
    int Len(ListNode*head){
        if(!head) return 0;
        return 1 + Len(head->next);
    }

    ListNode* swapNodes(ListNode* head, int k) {
        // case 1
        if(!head || !head->next) return head;
        int len = Len(head);
        int lpos = k;
        int rpos = len - k + 1;

        if(rpos < lpos) swap(lpos, rpos);

        // case 2
        if(lpos == rpos) return head;

        // case 3
        if(len == 2){
            ListNode*nextNode = head->next;
            nextNode->next = head;
            head->next = 0;
            head = nextNode;
            return head;
        }

        // case 4
        if(lpos == 1){
            ListNode*lp = 0;
            ListNode*ln = head;
            ListNode*rp = head;
            for(int i=0; i<rpos-2; i++) rp=rp->next;
            ListNode*rn = rp->next;
            ListNode*rsave = rn->next;
            // swapping
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            head=rn;
            return head;
        }

        // case 5
        int noOfNodesBetweenSwapNodes = rpos - lpos - 1;
        if(noOfNodesBetweenSwapNodes == 0){
            // ln and rn are adjacents
            ListNode*lp = head;
            for(int i=0; i<lpos-2;i++) lp=lp->next;
            ListNode*ln = lp->next;

            ListNode*rp = head;
            for(int i=0; i<rpos-2;i++) rp=rp->next;
            ListNode*rn = rp->next;
            ListNode*rsave = rn->next;
            // swap
            lp->next = rp->next;
            rn->next = rp;
            rp->next = rsave;
            return head;
        }
        // case 6
        else{
            // noOfNodesBetweenSwapNodes >= 1
            ListNode*lp = head;
            for(int i=0; i<lpos-2;i++) lp=lp->next;
            ListNode*ln = lp->next;

            ListNode*rp = head;
            for(int i=0; i<rpos-2;i++) rp=rp->next;
            ListNode*rn = rp->next;
            ListNode*rsave = rn->next;
            // swap
            lp->next = rn;
            rn->next = ln->next;
            rp->next = ln;
            ln->next = rsave;
            return head;
        }
    }
};
