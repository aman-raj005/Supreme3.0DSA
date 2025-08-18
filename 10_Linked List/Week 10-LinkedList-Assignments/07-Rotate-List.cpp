// leetcode 61: Rotate List

61. Rotate List
Solved
Medium
Topics
premium lock icon
Companies
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109

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
      int getlength(ListNode* &head,int &length ,ListNode* &lastnode)
       {
         //base case
         if(head==NULL){return length;}
         //aik mai karuga
         length++;
         lastnode=head;
         return getlength(head->next,length,lastnode) ;
       }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL){return head;}
      ListNode* current=head;
      ListNode* lastnode=NULL;
      int length=0;
      int size=getlength(head,length,lastnode); 
      if(k%size==0){return current;}
      int realrotate=size-(k%size)-1; 
      //now reach to the end where we want to null
      ListNode* dummy=current;
      for(int i=0;i<realrotate;i++)
        {
             dummy=dummy->next;
        }
        ListNode* newhead=dummy->next;
        dummy->next=NULL;
        lastnode->next=current;
      return newhead;
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
    int getLength(ListNode*head){
        int len = 0;
        while(head){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        int len = getLength(head);
        int actualRotateK = (k % len);
        if(actualRotateK == 0) return head;
        int newLastNodePos = len - actualRotateK - 1;
        ListNode* newLastNode = head;
        for(int i=0; i<newLastNodePos;i++){
            newLastNode = newLastNode->next;
        }
        ListNode* newHead = newLastNode->next;
        newLastNode->next = NULL;

        ListNode* it = newHead;
        while(it->next){
            it=it->next;
        }
        it->next = head;
        return newHead;
    }
};
