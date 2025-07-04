// leetcode 2058: Find the Minimum and Maximum Number of Nodes Between Critical Points

2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Solved
Medium
Topics
premium lock icon
Companies
Hint
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

 

Example 1:


Input: head = [3,1]
Output: [-1,-1]
Explanation: There are no critical points in [3,1].
Example 2:


Input: head = [5,3,1,2,5,1,2]
Output: [1,3]
Explanation: There are three critical points:
- [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
- [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
- [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
Example 3:


Input: head = [1,3,2,2,3,2,2,2,7]
Output: [3,3]
Explanation: There are two critical points:
- [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
- [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
Both the minimum and maximum distances are between the second and the fifth node.
Thus, minDistance and maxDistance is 5 - 2 = 3.
Note that the last node is not considered a local maxima because it does not have a next node.
 

Constraints:

The number of nodes in the list is in the range [2, 105].
1 <= Node.val <= 105


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      vector<int>ans={-1,-1};
      if(head==NULL){return ans;}
      if(head->next==NULL ||head->next->next==NULL){return ans;}  
      ListNode* prev=head;
      ListNode* current=head->next;
      ListNode* forward=head->next->next;
      int index=1;
      int firstindex=-1;
      int lastindex=-1;
      int previouscritical=-1;
      int minimumdist=INT_MAX;
while(forward !=NULL)
    {
      if((current->val < prev->val && current->val <forward->val)|| (current->val > prev->val && current->val > forward->val)  )
       {
         if(firstindex==-1)
          {
            firstindex=index;
          }
         else
          {
                minimumdist=min(minimumdist,index-previouscritical) ;
          }
         previouscritical=index;
       }
       //age shift kar dete hai
       prev=prev->next;
       current=current->next;
       forward=forward->next;
      index++;
    }
    lastindex=previouscritical;
    if(lastindex==firstindex ||firstindex==-1){return ans;}
    ans={minimumdist,lastindex-firstindex} ;
    
    return ans;
    }
};




    //     code by lakchyaa
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans = {-1,-1};  //store minDist, maxDist
        ListNode* prev = head;
        if(!prev) return ans;
        ListNode* curr = head->next;
        if(!curr) return ans;
        ListNode* nxt = head->next->next;
        if(!nxt) return ans;

        int firstCP = -1;
        int lastCP = -1;
        int minDist = INT_MAX;
        int i = 1;
        while(nxt){
            bool isCP = ((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val) ) ? true : false;
            if(isCP && firstCP==-1){
                firstCP = i;
                lastCP = i;
            }
            else if(isCP){
                minDist = min(minDist,i-lastCP);
                lastCP = i;
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if(lastCP == firstCP){
            // only one critical points was found
            return ans;
        }
        else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }
        return ans;
    }
};
