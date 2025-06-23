234. Palindrome Linked List
Solved
Easy
Topics
premium lock icon
Companies
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
Seen this question in a real interview before?
1/5
Yes
No
Accepted
2,444,387/4.4M
Acceptance Rate
55.9%



// my code 

// Finds middle and returns midNode, and sets prevNode to node before mid
ListNode* funMidN(ListNode* &currNode, ListNode* &prevNode) {
    ListNode* fast = currNode;
    ListNode* slow = currNode;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            prevNode = slow;
            slow = slow->next;
        }
    }
    return slow;
}

// Reverse the linked list from currentnode, return new head
ListNode* funHalfNode(ListNode* &currentnode, ListNode* previousNode) {
    if (currentnode == NULL) {
        return previousNode;
    }
    ListNode* forwardNode = currentnode->next;
    currentnode->next = previousNode;
    return funHalfNode(forwardNode, currentnode);
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // single node is palindrome

        ListNode* currNode = head;
        ListNode* prevNode = NULL;
        ListNode* midNode = funMidN(currNode, prevNode);

        if (prevNode != NULL)
            prevNode->next = NULL;  // Disconnect first half

        ListNode* beforenode = NULL;
        ListNode* headnode = funHalfNode(midNode, beforenode);

        ListNode* firstHNode1head = head;
        ListNode* secondHNode1head = headnode;

        while (secondHNode1head != NULL) { // Compare till second half ends
            if (firstHNode1head->val != secondHNode1head->val) {
                return false;
            }
            firstHNode1head = firstHNode1head->next;
            secondHNode1head = secondHNode1head->next;
        }
        return true;
    }
};





  //                code by love babbar 




// leetcode 234: Palindrome Linked List

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
    ListNode* getMiddle(ListNode* head, ListNode* &middleNodeKaPrev){
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL){
            fast= fast->next;
            if(fast!=NULL){
                fast=fast->next;
                middleNodeKaPrev=slow;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverselist(ListNode* &prev, ListNode* &curr){
        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr= forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            // LL is empty
            return true;
        }
        if(head->next == NULL){
            //single node
            return true;
        }
        // travel till middle node and break the LL in 2 halves
        ListNode* firstHalfHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head,middleNodeKaPrev);
        // break
        middleNodeKaPrev ->next = NULL;
        // reverse the second half
        ListNode* prev=NULL;
        ListNode* curr=middleNode;
        ListNode* secondHalfHead = reverselist(prev,curr);
        // compare both the halves if they are equal
        // even length wale case me dono part ki length equal hogi
        // odd length wale case me second half ki length badi hogi by 1
        // that's why comparison firstHalf ke according krenge
        ListNode* tempHead1 = firstHalfHead;
        ListNode* tempHead2 = secondHalfHead;
        while(tempHead1!=NULL){
            if(tempHead1->val != tempHead2->val){
                return false;
            }
            else{
                //data equal hai toh aage wali node check kro
                tempHead1= tempHead1->next;
                tempHead2= tempHead2->next;
            }
        }

        return true;
    }
};
