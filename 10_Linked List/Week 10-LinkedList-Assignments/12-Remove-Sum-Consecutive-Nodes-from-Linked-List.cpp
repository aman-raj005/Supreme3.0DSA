// leetcode 1171: Remove Zero Sum Consecutive Nodes from Linked List
          //                  https://youtu.be/TKhj7o_bRVE?feature=shared

1171. Remove Zero Sum Consecutive Nodes from Linked List
Solved
Medium
Topics
premium lock icon
Companies
Hint
Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of ListNode objects.)

Example 1:

Input: head = [1,2,-3,3,1]
Output: [3,1]
Note: The answer [1,2,1] would also be accepted.
Example 2:

Input: head = [1,2,3,-3,4]
Output: [1,2,4]
Example 3:

Input: head = [1,2,3,-3,-2]
Output: [1]
 

Constraints:

The given linked list will contain between 1 and 1000 nodes.
Each node in the linked list has -1000 <= node.val <= 1000.



 //    my code 
 
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
    ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*>map;
    int prefixsum=0;
    ListNode* dummyhead=new ListNode(0);
    dummyhead->next=head;
    ListNode* temp=dummyhead;

    while(temp !=NULL)
    {
      prefixsum +=temp->val;
      map[prefixsum]=temp; 
      temp=temp->next;
    } 
     prefixsum=0;
     temp=dummyhead;
     while(temp !=NULL)
      {
        prefixsum +=temp->val;
        if(map.find(prefixsum) !=map.end())
         {
           temp->next=map[prefixsum]->next;
         }
         temp=temp->next;
      }
    return dummyhead->next;
    }
};



    //    code by  lakchyaaa
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
    void sanitizeMap(ListNode*head, unordered_map<int, ListNode*>& mp, int csum){
        int temp = csum;
        while(true){
            temp += head->val;
            if(temp==csum) break;
            mp.erase(temp);
            head=head->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head || (!head->next && head->val == 0)) return 0;
        unordered_map<int, ListNode*>mp;
        auto it = head;
        int csum = 0;
        while(it){
            csum += it->val;
            if(csum==0){
                head=it->next;
                mp.clear();
            }
            else if(mp.find(csum) != mp.end()){
                // already exist in map
                sanitizeMap(mp[csum]->next,mp,csum);
                mp[csum]->next = it->next;
            }
            else mp[csum]=it;
            it=it->next;
        }
        return head;
    }
};
