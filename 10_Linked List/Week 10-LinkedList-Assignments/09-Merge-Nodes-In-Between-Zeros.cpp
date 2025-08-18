// leetcode 2181 : Merge Nodes in Between Zeros
2181. Merge Nodes in Between Zeros
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. 
The modified list should not contain any 0's.

Return the head of the modified linked list.

 

Example 1:


Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.
Example 2:


Input: head = [0,1,0,3,0,2,2,0]
Output: [1,3,4]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 1 = 1.
- The sum of the nodes marked in red: 3 = 3.
- The sum of the nodes marked in yellow: 2 + 2 = 4.
 

Constraints:

The number of nodes in the list is in the range [3, 2 * 105].
0 <= Node.val <= 1000
There are no two consecutive nodes with Node.val == 0.
Th


  // my code 
  
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
    ListNode* mergeNodes(ListNode* head) 
    {
      if(head==NULL ||head->next==NULL){return head;}
      ListNode* slow=head;
      ListNode* start=head->next;
      ListNode* fast=head;
      ListNode* last=NULL;

      int sum=0;
      while(fast !=NULL)
       {
          sum=sum+fast->val;
          if(fast->val==0)
           {
             slow->val=sum;
             sum=0;
             last=slow;
             slow=slow->next;
           }
           fast=fast->next;
       } 
       last->next=NULL;
       return start; 
    }
};


         //  code by lakchyaa
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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return 0;
        ListNode*slow = head, *fast = head->next, *newLastNode=0;
        int sum = 0;
        while(fast){
            if(fast->val != 0) sum += fast->val;
            else{
                //fast->val==0
                    slow->val = sum;
                    newLastNode = slow;
                    slow = slow->next;
                    sum = 0;
            }
            fast = fast->next;
        }
        ListNode*temp = newLastNode->next;
        // just formed new list
        newLastNode->next = 0;
        // Deleting old list
        while(temp){
            ListNode*nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return head;
    }
};
