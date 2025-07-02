// leetcode 328: Odd Even Linked List

328. Odd Even Linked List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
 

Constraints:

The number of nodes in the linked list is in the range [0, 104].
-106 <= Node.val <= 106
Seen this question in a real interview before?
1/5
Yes
No
Accepted
1,247,725/2M
Acceptance Rate
62.0%

//     my code 

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
    ListNode* oddEvenList(ListNode* head)
     {
        if(head==NULL || head->next==NULL){return head;}
        ListNode* odd=head;
        ListNode* even= head->next ;
        ListNode* firsthead=even;
        while(even !=NULL &&  even->next !=NULL)
         {
           //odd
           odd->next=even->next;
           //even
           even->next=even->next->next;
           odd=odd->next;
           even=even->next;
         }
         odd->next=firsthead;
  
        return head ;

     }
};




   //         code by lakchya
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next==0) return head;
        ListNode* h1 = head, *h2 = head->next;     //h1->odd indexed list, h2->even list
        ListNode* evenHead = h2;
        while(h2 && h2->next){
            h1->next = h2->next;
            h2->next = h2->next->next;
            h1 = h1->next;
            h2 = h2->next;
        }
        // the two independent prepared list has been re-grouped
        h1->next =evenHead;
        return head;
    }
};
